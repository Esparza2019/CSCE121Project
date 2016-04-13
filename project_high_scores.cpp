#include "std_lib_facilities_4.h"
#include "Graph.h"
#include "GUI.h"
#include "Point.h"
#include "Simple_window.h"
#include "Window.h"
#include "project_high_scores.h"
using namespace Graph_lib;

void high_score::set_initials(String s)
{
	initials = s;
}
void high_score::set_score(int p)
{
	score = p;
}
String high_score::get_initials()
{
	return initials;
}
int high_score::get_score()
{
	return score;
}

istream& operator>>(istream& is, high_score& h)
{
	string str;
	int a;
	is >> str >> a;
	if (!is) return is;
	h = high_score{str, a};
	return is;
}

Game_window::Game_window(Point p, int w, int h, String name)
	:Window{p, w, h, name},
	continue_button{Point{35+w/2,800}, 70, 20, "Continue",
		[](Address, Address pw) {reference_to<Game_window>(pw).next_button();}},
	high_scores(Point(w/10, h/8), "HIGH SCORES"),
	background(Point(0,0), "project_background.gif"),
	user_initials(Point{w/2-35, 800}, 70, 20, "Enter Initials: ")
	
	{
		ifstream is{"high_scores.txt"};
		high_scores.set_font_size(140);
		high_scores.set_font(Graph_lib::Font::helvetica_bold);
		high_scores.set_color(Color::blue);
		read_initials_and_scores(scores, is);
		sort_scores(scores, initials_and_scores);
//		attach(background);
		attach(continue_button);
		attach(high_scores);
		attach(user_initials);
		for(int k = 0; k < initials_and_scores.size(); k++)
		{
			initials_and_scores[k]->set_color(Color::blue);
			initials_and_scores[k]->set_font_size(70);
			initials_and_scores[k]->set_font(Graph_lib::Font::helvetica_bold);
			attach(*(initials_and_scores[k]));
		}
	}
	
void Game_window::next_button()
{
	detach(continue_button);
	detach(high_scores);
//	detach(background);
	detach(user_initials);
	hide();
}

void Game_window::read_initials_and_scores(vector<high_score>& s, istream& is)
{	
	high_score h;
	
	while(!is.eof())
	{
		if(!is)
		{
			return;
		}
		else
		{
			is >> h;
			s.push_back(h);
		}
	}
}

void Game_window::sort_scores(vector<high_score>& s, vector<Text*>& t)
{	
	for(int j = 0 ; j < 5; j++)
	{
		int a = 0;
		for(int i = 1 ; i < s.size(); i++)
		{
			if(s[i].score > s[a].score)
			{
				a = i;
			}
		}
		t.push_back(new Text(Point(500,200 + 100*j), s[a].initials + " " + to_string(s[a].score)));
		s.erase(s.begin() + a);
	}
}

int main()
try
{
	Game_window game(Point(0,0), 1500, 900, "Game");
	return gui_main();
}

catch (exception& e)			//Catches errors
{
	cerr << "error: " << e.what() << '\n';
	keep_window_open();
	return 1;					//1 indicates failure
}

catch (...)						//Catches errors
{
	cerr << "Oops: unknown exception!\n";
	keep_window_open();
	return 2;					//2 indicates failure
}