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
    title_4(Point(60, 200), "Please Select a Difficulty Level"),
    level_2_button(Point(w/6, h/2), 150, 75, "Level 2", cb_level_2),
    level_3_button(Point(w*2/6, h/2), 150, 75, "Level 3", cb_level_3),
    level_4_button(Point(w*3/6, h/2), 150, 75, "Level 4", cb_level_4),
    level_5_button(Point(w*4/6, h/2), 150, 75, "Level 5", cb_level_5),
    level_6_button(Point(w/5, h*1/3+350), 150, 75, "Level 6", cb_level_6),
    level_7_button(Point(w*2/5, h*1/3+350), 150, 75, "Level 7", cb_level_7),
    level_8_button(Point(w*3/5, h*1/3+350), 150, 75, "Level 8", cb_level_8),
	
//---------------------------------Screen 5----------------------------------------

//points used to calculate score
	p1(sattelite_1.center()), p2(sattelite_2.center()), p3(sattelite_3.center()), p4(sattelite_4.center()), 
	p5(sattelite_5.center()), p6(sattelite_6.center()), p7(sattelite_7.center()), p8(sattelite_8.center()),
	
	sattelite_1(Point(250, 250), 15),
	sattelite_2(Point(600,680), 15),
	sattelite_3(Point(300,400), 15),
	sattelite_4(Point(220,800), 15),
	sattelite_5(Point(600,350), 15),
	sattelite_6(Point(700,825), 15),
	sattelite_7(Point(550,550), 15),
	sattelite_8(Point(240,600), 15),
	
//these bools are used to notify when to move the sattelite
	sat_1_pressed{false}, sat_2_pressed{false}, sat_3_pressed{false}, sat_4_pressed{false},
	sat_5_pressed{false}, sat_6_pressed{false}, sat_7_pressed{false}, sat_8_pressed{false},
	
	moves_remaining{50},
	
	//north_pressed{false}, south_pressed{false}, east_pressed{false}, west_pressed{false},
	
	mercator_map(Point(0,0), "rsz_equirectangular.jpg"),

//buttons for screen 5
	sattelite_1_button(Point(p1.x-15, p1.y-15), 100, 50, "Sattelite 1\n(Red)", cb_sat_1),
	sattelite_2_button(Point(1200, 120), 100, 50, "Sattelite 2\n(Blue)", cb_sat_2),
	sattelite_3_button(Point(1400, 120), 100, 50, "Sattelite 3\n(Green)", cb_sat_3),
	sattelite_4_button(Point(1000, 250), 100, 50, "Sattelite 4\n(Yellow)", cb_sat_4),
	sattelite_5_button(Point(1200, 250), 100, 50, "Sattelite 5\n(Cyan)", cb_sat_5),
	sattelite_6_button(Point(1400, 250), 100, 50, "Sattelite 6\n(White)", cb_sat_6),
	sattelite_7_button(Point(1100, 400), 100, 50, "Sattelite 7\n(Black)", cb_sat_7),
	sattelite_8_button(Point(1325, 400), 100, 50, "Sattelite 8\n(Magenta)", cb_sat_8),
	
	north_button(Point(1200, 600), 100, 50, "Move North", cb_north),
	south_button(Point(1200, 700), 100, 50, "Move South", cb_south),
	east_button(Point(1250, 650), 100, 50, "Move East", cb_east),
	west_button(Point(1150, 650), 100, 50, "Move West", cb_west)
	

    
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
    next_4();
	design_sattelites();
	attach(sattelite_1);
	attach(sattelite_2);
	attach(sattelite_1_button);
	attach(sattelite_2_button);
}

void Game_window::cb_level_2(Address, Address pw){
    reference_to<Game_window>(pw).level_2();
}

void Game_window::level_3(){
    next_4();
	design_sattelites();
	attach(sattelite_1);
	attach(sattelite_2);
	attach(sattelite_3);
	attach(sattelite_1_button);
	attach(sattelite_2_button);
	attach(sattelite_3_button);

}

void Game_window::cb_level_3(Address, Address pw){
    reference_to<Game_window>(pw).level_3();
}

void Game_window::level_4(){
    next_4();
	design_sattelites();
	attach(sattelite_1);
	attach(sattelite_2);
	attach(sattelite_3);
	attach(sattelite_4);
	attach(sattelite_1_button);
	attach(sattelite_2_button);
	attach(sattelite_3_button);
	attach(sattelite_4_button);
}

void Game_window::cb_level_4(Address, Address pw){
    reference_to<Game_window>(pw).level_4();
}

void Game_window::level_5(){
    next_4();
	design_sattelites();
	attach(sattelite_1);
	attach(sattelite_2);
	attach(sattelite_3);
	attach(sattelite_4);
	attach(sattelite_5);
	attach(sattelite_1_button);
	attach(sattelite_2_button);
	attach(sattelite_3_button);
	attach(sattelite_4_button);
	attach(sattelite_5_button);
}

void Game_window::cb_level_5(Address, Address pw){
    reference_to<Game_window>(pw).level_5();
}

void Game_window::level_6(){
    next_4();
	design_sattelites();
	attach(sattelite_1);
	attach(sattelite_2);
	attach(sattelite_3);
	attach(sattelite_4);
	attach(sattelite_5);
	attach(sattelite_6);
	attach(sattelite_1_button);
	attach(sattelite_2_button);
	attach(sattelite_3_button);
	attach(sattelite_4_button);
	attach(sattelite_5_button);
	attach(sattelite_6_button);
}

void Game_window::cb_level_6(Address, Address pw){
    reference_to<Game_window>(pw).level_6();
}

void Game_window::level_7(){
    next_4();
	design_sattelites();
	attach(sattelite_1);
	attach(sattelite_2);
	attach(sattelite_3);
	attach(sattelite_4);
	attach(sattelite_5);
	attach(sattelite_6);
	attach(sattelite_7);
	attach(sattelite_1_button);
	attach(sattelite_2_button);
	attach(sattelite_3_button);
	attach(sattelite_4_button);
	attach(sattelite_5_button);
	attach(sattelite_6_button);
	attach(sattelite_7_button);
}

void Game_window::cb_level_7(Address, Address pw){
    reference_to<Game_window>(pw).level_7();
}

void Game_window::level_8(){
    next_4();
	design_sattelites();
	attach(sattelite_1);
	attach(sattelite_2);
	attach(sattelite_3);
	attach(sattelite_4);
	attach(sattelite_5);
	attach(sattelite_6);
	attach(sattelite_7);
	attach(sattelite_8);
	attach(sattelite_1_button);
	attach(sattelite_2_button);
	attach(sattelite_3_button);
	attach(sattelite_4_button);
	attach(sattelite_5_button);
	attach(sattelite_6_button);
	attach(sattelite_7_button);
	attach(sattelite_8_button);
}

void Game_window::cb_level_8(Address, Address pw){
    reference_to<Game_window>(pw).level_8();
}


void Game_window::design_win_4(){
    title_4.set_font_size(100);
	title_4.set_color(Color::red);
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
	design_win_5();
	build_win_5();

}

//----------------------------------Screen 5 Functions---------------------------------------------

void Game_window::design_sattelites(){
	sattelite_1.set_fill_color(Color::red);
	sattelite_2.set_fill_color(Color::blue);
	sattelite_3.set_fill_color(Color::green);
	sattelite_4.set_fill_color(Color::yellow);
	sattelite_5.set_fill_color(Color::cyan);
	sattelite_6.set_fill_color(Color::white);
	sattelite_7.set_fill_color(Color::black);
	sattelite_8.set_fill_color(Color::magenta);
}

void Game_window::design_win_5(){
}

void Game_window::build_win_5(){
	attach(mercator_map);
	attach(north_button);
	attach(south_button);
	attach(east_button);
	attach(west_button);
}

//sattelite button functions

void Game_window::sattelite_1_chosen(){
	sat_1_pressed=true;
	sat_2_pressed=false;
	sat_3_pressed=false;
	sat_4_pressed=false;
	sat_5_pressed=false;
	sat_6_pressed=false;
	sat_7_pressed=false;
	sat_8_pressed=false;
}

void Game_window::sattelite_2_chosen(){
	sat_1_pressed=false;
	sat_2_pressed=true;
	sat_3_pressed=false;
	sat_4_pressed=false;
	sat_5_pressed=false;
	sat_6_pressed=false;
	sat_7_pressed=false;
	sat_8_pressed=false;
}

void Game_window::sattelite_3_chosen(){
	sat_1_pressed=false;
	sat_2_pressed=false;
	sat_3_pressed=true;
	sat_4_pressed=false;
	sat_5_pressed=false;
	sat_6_pressed=false;
	sat_7_pressed=false;
	sat_8_pressed=false;
}

void Game_window::sattelite_4_chosen(){
	sat_1_pressed=false;
	sat_2_pressed=false;
	sat_3_pressed=false;
	sat_4_pressed=true;
	sat_5_pressed=false;
	sat_6_pressed=false;
	sat_7_pressed=false;
	sat_8_pressed=false;
}

void Game_window::sattelite_5_chosen(){
	sat_1_pressed=false;
	sat_2_pressed=false;
	sat_3_pressed=false;
	sat_4_pressed=false;
	sat_5_pressed=true;
	sat_6_pressed=false;
	sat_7_pressed=false;
	sat_8_pressed=false;
}

void Game_window::sattelite_6_chosen(){
	sat_1_pressed=false;
	sat_2_pressed=false;
	sat_3_pressed=false;
	sat_4_pressed=false;
	sat_5_pressed=false;
	sat_6_pressed=true;
	sat_7_pressed=false;
	sat_8_pressed=false;
}

void Game_window::sattelite_7_chosen(){
	sat_1_pressed=false;
	sat_2_pressed=false;
	sat_3_pressed=false;
	sat_4_pressed=false;
	sat_5_pressed=false;
	sat_6_pressed=false;
	sat_7_pressed=true;
	sat_8_pressed=false;
}

void Game_window::sattelite_8_chosen(){
	sat_1_pressed=false;
	sat_2_pressed=false;
	sat_3_pressed=false;
	sat_4_pressed=false;
	sat_5_pressed=false;
	sat_6_pressed=false;
	sat_7_pressed=false;
	sat_8_pressed=true;
}

void Game_window::cb_sat_1(Address, Address pw){
	reference_to<Game_window>(pw).sattelite_1_chosen();
}
void Game_window::cb_sat_2(Address, Address pw){
	reference_to<Game_window>(pw).sattelite_2_chosen();
}
void Game_window::cb_sat_3(Address, Address pw){
	reference_to<Game_window>(pw).sattelite_3_chosen();
}
void Game_window::cb_sat_4(Address, Address pw){
	reference_to<Game_window>(pw).sattelite_4_chosen();
}
void Game_window::cb_sat_5(Address, Address pw){
	reference_to<Game_window>(pw).sattelite_5_chosen();
}
void Game_window::cb_sat_6(Address, Address pw){
	reference_to<Game_window>(pw).sattelite_6_chosen();
}
void Game_window::cb_sat_7(Address, Address pw){
	reference_to<Game_window>(pw).sattelite_7_chosen();
}
void Game_window::cb_sat_8(Address, Address pw){
	reference_to<Game_window>(pw).sattelite_8_chosen();
}

//NSEW button functions

void Game_window::move_north(){
	
	redraw();
}
void Game_window::move_south(){
	redraw();
	
	
}
void Game_window::move_east(){
	if (sat_1_pressed==true){
		shift_right(sattelite_1, sattelite_1_button);
		p1 = sattelite_1.center();
	}
//	else if(sat_2_pressed==true)
//		shift_right(sattelite_2);
//	else if(sat_3_pressed==true)
//		shift_right(sattelite_3);
//	else if(sat_4_pressed==true)
//		shift_right(sattelite_4);
//	else if(sat_5_pressed==true)
//		shift_right(sattelite_5);
//	else if(sat_6_pressed==true)
//		shift_right(sattelite_6);
//	else if(sat_7_pressed==true)
//		shift_right(sattelite_7);
//	else if(sat_8_pressed==true)
//		shift_right(sattelite_8);
	moves_remaining-=1;
	redraw();
}
void Game_window::move_west(){
	
}
//callbacks
void Game_window::cb_north(Address, Address pw){
	reference_to<Game_window>(pw).move_north();
}
void Game_window::cb_south(Address, Address pw){
	reference_to<Game_window>(pw).move_south();
}
void Game_window::cb_east(Address, Address pw){
	reference_to<Game_window>(pw).move_east();
}
void Game_window::cb_west(Address, Address pw){
	reference_to<Game_window>(pw).move_west();
}

void Game_window::shift_right(Shape& c, Widget& w){
	c.move(10,0);
	w.move(10,0);
}


//void Game_window::reset_sat_bools(){
	//sat_1_pressed=false;
	//sat_2_pressed=false;
//	sat_3_pressed=false;
//	sat_4_pressed=false;
//	sat_5_pressed=false;
//	sat_6_pressed=false;
//	sat_7_pressed=false;
//	sat_8_pressed=false;
//}

