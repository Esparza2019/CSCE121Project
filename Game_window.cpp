#include "Game_window.h"


Game_window::Game_window(Point xy, int w, int h, const string& title)
	:Window{xy,w,h,title},
//-----------------------------Screen 1-----------------------------------------------
	my_background_1{Point(0,0), "background-bicubic.gif"},
	next_button_1(Point (x_max()-800, y_max()-200), 100, 50, "Continue", cb_next_1),
	button_cover_1(Point(x_max()-800, y_max()-200), 100, 50),
	button_text_1(Point(x_max()-796, y_max()-165), "Continue"),
	game_name_1(Point(400, 250), "Wifi Hero"),
	team_name_1(Point(180, 400), "Designed by Team 11:"),
	names_1(Point(50, 550), "Justin DeSalvo, Tyler Fenske, Daniel Esparza"),
	text_backdrop_1(Point(350, 50), 710, 260),
	backdrop_outline_1(Point(340, 40), 730, 280),

//------------------------------Screen 2----------------------------------------------------
	intro_2{Point(500,150),"Wifi Hero"},
	summary_2{Point(200,300), "No Service."},
	summary1_2{Point(200,400),"Today all connectivity was lost, our world's top minds are working hard to find a solution."},
	summary2_2{Point(200,500),"Normally this might've been an easy task, but without any communication its all up to you."},
    summary3_2{Point(200,600),"Our engineers have repaired some satelites and you need to place them and cover as many people as possible."},
    summary4_2{Point(200,700),"Click on any satellite to select it, and move it by pressing the movement buttons."},
    summary5_2{Point(200,800),"The game ends when no moves are left."},
	
	next_button_2(Point(x_max()-800, y_max()-200), 100, 50, "Continue", cb_next_2),
	button_cover_2(Point(x_max()-800, y_max()-200), 100, 50),
    button_text_2(Point(x_max()-796, y_max()-165), "Continue"),
	
	
//-----------------------------Screen 3---------------------------------------------------------


    high_scores(Point(w/10, h/8), "HIGH SCORES"),
    background(Point(0,0), "project_background.gif"),
    user_initials(Point{w/2-35, 800}, 70, 20, "Enter Initials: "),

    next_button_3(Point(x_max()-800, y_max()-200), 100, 50, "Continue", cb_next_3),
    button_cover_3(Point(x_max()-800, y_max()-200), 100, 50),
    button_text_3(Point(x_max()-796, y_max()-165), "Continue"),
	
	backdrop_3{Point(w/2-50, 790), 140, 90},
    
 //--------------------------------Screen 4------------------------------------------------------------
    title_4(Point(w+60, 250), "Please Select a Difficulty Level"),
    level_2_button(Point(w/6, h/2), 100, 50, "Level 2", cb_level_2),
    level_3_button(Point(w*2/6, h/2), 100, 50, "Level 3", cb_level_3),
    level_4_button(Point(w*3/6, h/2), 100, 50, "Level 4", cb_level_4),
    level_5_button(Point(w*4/6, h/2), 100, 50, "Level 5", cb_level_5),
    level_6_button(Point(w/5, h*1/3), 100, 50, "Level 6", cb_level_6),
    level_7_button(Point(w*2/5, h*1/3), 100, 50, "Level 7", cb_level_7),
    level_8_button(Point(w*3/5, h*1/3), 100, 50, "Level 8", cb_level_8)
    
//----------------------------------------Screen 1 Functions-------------------------------------------------------
//this initializes the window, first screen of the game(splash screen)
{
	design_win_1();
	build_win_1();
}

//design_win styles the objects for the screen
void Game_window::design_win_1(){
	button_cover_1.set_fill_color(Color::red);
	button_text_1.set_font_size(24);
//	button_text_1.set_font(Font::courier_bold_italic);
	button_cover_1.set_style(Line_style::solid);

	game_name_1.set_font_size(150);
	game_name_1.set_color(Color::red);
	team_name_1.set_font_size(100);
	team_name_1.set_color(Color::white);
	names_1.set_font_size(70);
	names_1.set_color(Color::white);
	text_backdrop_1.set_fill_color(Color::black);
	backdrop_outline_1.set_fill_color(Color::white);
}

//build_win attaches the objects
void Game_window::build_win_1(){
	attach(my_background_1);
	attach(next_button_1);
	attach(button_cover_1);
	attach(button_text_1);
	attach(backdrop_outline_1);
	attach(text_backdrop_1);
	attach(game_name_1);
	attach(team_name_1);
	attach(names_1);
}

//takedown_win will detach all of the objects from the screen
void Game_window::takedown_win_1(){
	detach(next_button_1);
	detach(button_cover_1);
	detach(button_text_1);
	detach(backdrop_outline_1);
	detach(text_backdrop_1);
	detach(game_name_1);
	detach(team_name_1);
	detach(names_1);
}

//-----move to next screen----------
void Game_window::next_1(){
//take old elements off of the screen
	takedown_win_1();
//set the styles for the second screen
	design_win_2();
//attach the elements to the window
	build_win_2();
}

//callback function to next function above^^
void Game_window::cb_next_1(Address, Address pw){
	reference_to<Game_window>(pw).next_1();
}

//---------------------------------------Screen 2 functions-------------------------------------
//design_win styles the objects for the screen
void Game_window::design_win_2(){
	intro_2.set_color(Color::white);
    intro_2.set_font(FL_TIMES);
    intro_2.set_font_size(100);
	
	button_cover_2.set_fill_color(Color::red);
	
    summary_2.set_color(Color::white);
    summary1_2.set_color(Color::white);
    summary2_2.set_color(Color::white);
    summary3_2.set_color(Color::white);
    summary4_2.set_color(Color::white);
    summary5_2.set_color(Color::white);
    
    summary_2.set_font_size(20);
    summary1_2.set_font_size(20);
    summary2_2.set_font_size(20);
    summary3_2.set_font_size(20);
    summary4_2.set_font_size(20);
    summary5_2.set_font_size(20);
}

//build_win attaches the objects
void Game_window::build_win_2(){
	attach(next_button_2);
	attach(summary_2);
	attach(summary1_2);
	attach(summary2_2);
	attach(summary3_2);
	attach(summary4_2);
	attach(summary5_2);
	attach(intro_2);
	attach(button_cover_2);
    attach(button_text_2);
}

//takedown_win will detach all of the objects from the screen
void Game_window::takedown_win_2(){
	detach(summary_2);
	detach(summary1_2);
	detach(summary2_2);
	detach(summary3_2);
	detach(summary4_2);
	detach(summary5_2);
	detach(intro_2);
    detach(button_text_2);
    detach(button_cover_2);
    detach(next_button_2);
	detach(my_background_1);
    
}

void Game_window::next_2(){
    //removes all elements from win_2
	takedown_win_2();
    //set the styles for the second screen
    design_win_3();
    //attach the elements to the window
    build_win_3();
}

void Game_window::cb_next_2(Address, Address pw){
	reference_to<Game_window>(pw).next_2();
}

//---------------------------------------Screen 3 functions-------------------------------------
// Tyler's code
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

//--------------------------------------------------------------------------------------------------------
//design_win styles the objects for the screen
void Game_window::design_win_3(){
	backdrop_3.set_fill_color(Color::invisible);
    ifstream is{"high_scores.txt"};
    high_scores.set_font_size(140);
    high_scores.set_font(Graph_lib::Font::helvetica_bold);
    high_scores.set_color(Color::blue);
    read_initials_and_scores(scores, is);
    sort_scores(scores, initials_and_scores);
    for(int k = 0; k < initials_and_scores.size(); k++)
    {
        initials_and_scores[k]->set_color(Color::blue);
        initials_and_scores[k]->set_font_size(70);
        initials_and_scores[k]->set_font(Graph_lib::Font::helvetica_bold);
        attach(*(initials_and_scores[k]));
    }

}
//build_win attaches the objects
void Game_window::build_win_3(){
    attach(high_scores);
    attach(user_initials);
    attach(next_button_3);
    attach(button_cover_3);
    attach(button_text_3);
	//attach(backdrop_3);
}
//takedown_win will detach all of the objects from the screen
void Game_window::takedown_win_3(){
    detach(high_scores);
    detach(user_initials);
    detach(next_button_3);
    detach(button_cover_3);
    detach(button_text_3);    
}
//-----move to next screen----------
void Game_window::next_3(){
    //take old elements off of the screen
    takedown_win_3();
    design_win_4();
    build_win_4();

}

//callback function to next function above^^
void Game_window::cb_next_3(Address, Address pw){
    reference_to<Game_window>(pw).next_3();
    
}

//-------------------------------------------------Screen 4 Functions---------------------------------------------

void Game_window::level_2(){
    vector<Point>sattelites(2);
    next_4();
}

void Game_window::cb_level_2(Address, Address pw){
    reference_to<Game_window>(pw).level_2();
}

void Game_window::level_3(){
    vector<Point>sattelites(3);
    next_4();
}

void Game_window::cb_level_3(Address, Address pw){
    reference_to<Game_window>(pw).level_3();
}

void Game_window::level_4(){
    vector<Point>sattelites(4);
    next_4();
}

void Game_window::cb_level_4(Address, Address pw){
    reference_to<Game_window>(pw).level_4();
}

vector<Point> Game_window::level_5(){
    vector<Point>sattelites(5);
    next_4();
	return sattelites;
}

void Game_window::cb_level_5(Address, Address pw){
    reference_to<Game_window>(pw).level_5();
}

void Game_window::level_6(){
    vector<Point>sattelites(6);
    next_4();
}

void Game_window::cb_level_6(Address, Address pw){
    reference_to<Game_window>(pw).level_6();
}

void Game_window::level_7(){
    vector<Point>sattelites(7);
    next_4();
}

void Game_window::cb_level_7(Address, Address pw){
    reference_to<Game_window>(pw).level_7();
}

void Game_window::level_8(){
    vector<Point>sattelites(8);
    next_4();
}

void Game_window::cb_level_8(Address, Address pw){
    reference_to<Game_window>(pw).level_8();
}


void Game_window::design_win_4(){
    title_4.set_font_size(150);
}
void Game_window::build_win_4(){
    attach(my_background_1);
    attach(title_4);
    attach(level_2_button);
    attach(level_3_button);
    attach(level_4_button);
    attach(level_5_button);
    attach(level_6_button);
    attach(level_7_button);
    attach(level_8_button);
}

void Game_window::takedown_win_4(){
    detach(title_4);
    detach(level_2_button);
    detach(level_3_button);
    detach(level_4_button);
    detach(level_5_button);
    detach(level_6_button);
    detach(level_7_button);
    detach(level_8_button);
}

void Game_window::next_4(){
    takedown_win_4();
    hide();
}
