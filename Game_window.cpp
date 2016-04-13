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
	intro_2{Point(500,150),"No Service"},
	summary_2{Point(200,300), "No Service."},
	summary1_2{Point(200,400),"Today all connectivity was lost, our world's top minds are working hard to find a solution."},
	summary2_2{Point(200,500),"Normally this might've been an easy task, but without any communication its all up to you."},
    summary3_2{Point(200,600),"Our engineers have repaired some satelites and you need to place them and cover as many people as possible."},
    summary4_2{Point(200,700),"Click on any satellite to select it, and move it by pressing the movement buttons."},
    summary5_2{Point(200,800),"The game ends when no moves are left."},
	
	next_button_2(Point(x_max()-800, y_max()-200), 100, 50, "Continue", cb_next_2),
	button_cover_2(Point(x_max()-800, y_max()-200), 100, 50),
    button_text_2(Point(x_max()-796, y_max()-165), "Continue")
	
	
//-----------------------------Screen 3---------------------------------------------------------

	
//this initializes the window, first screen of the game(splash screen)
{
	design_win_1();
	build_win_1();
}

//design_win styles the objects for the screen
void Game_window::design_win_1(){
	button_cover_1.set_fill_color(Color::red);
	button_text_1.set_font_size(24);
	//button_text.set_font(Font::courier_bold_italic);
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
    
}

void Game_window::next_2(){
    //removes all elements from win_2
	takedown_win_2();
}

void Game_window::cb_next_2(Address, Address pw){
	reference_to<Game_window>(pw).next_2();
}








