#include "Simple_window.h"
#include "Window.h"
#include "Graph.h"
#include "std_lib_facilities_4.h"
#include "GUI.h"
#include "Point.h"

using namespace Graph_lib;

//use the .h to declare everything that will be attached in the window, as well as any functions to be used on that window
//each screen should be labeled with its objects, widgets, and functions in its section

struct high_score
{
    high_score(String n, int s):initials{n},score{s}{}
    high_score():initials{""},score{0}{}
    
    string initials;
    int score;
    
    void set_initials(String s);
    void set_score(int p);
    
    String get_initials();
    int get_score();
};

struct Game_window : Graph_lib::Window{
	Game_window(Point xy, int w, int h, const string& title);
	
//-------------------------Screen 1----------------------------------------------------------
	
	Image my_background_1;
	Rectangle button_cover_1;
	Rectangle text_backdrop_1;
	Rectangle backdrop_outline_1;
	Text button_text_1;
	Text team_name_1;
	Text game_name_1;
	Text names_1;
	
	void design_win_1();
	void build_win_1();
	void takedown_win_1();
	
private:
	//widgets
	Button next_button_1;
	//actions
	void next_1();
	//callbacks
	static void cb_next_1(Address, Address);
	
//--------------------------Screen 2----------------------------------------------------
public:
	Text intro_2;
	Text summary_2;
	Text summary1_2;
	Text summary2_2;
	Text summary3_2;
	Text summary4_2;
	Text summary5_2;
	
	Rectangle button_cover_2;
	Text button_text_2;
	
	void design_win_2();//gives the style to the elements in the window
	void build_win_2();
	void takedown_win_2();
	
private:
	Button next_button_2;
	void next_2();
	static void cb_next_2(Address, Address);
	
//---------------------------Screen 3-----------------------------------------------------
public:
    
    Rectangle button_cover_3;
    Text button_text_3;
    
    void design_win_3();//gives the style to the elements in the window
    void build_win_3();
    void takedown_win_3();
    
    
private:
    
    In_box user_initials;
    vector<Text*> initials_and_scores;
    vector<high_score> scores;
    //Button continue_button;
    Text high_scores;
    Image background;
    
    
    
    
    //void next_button(); // was originally here, make sure to switch all next_button to next_button_3
   
    void read_initials_and_scores(vector<high_score>& s, istream& is);
    void sort_scores(vector<high_score>& s, vector<Text*>& t);
    
    Button next_button_3;
    void next_3();
    static void cb_next_3(Address, Address);
    
    
};

