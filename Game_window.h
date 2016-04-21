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
	Rectangle backdrop_3;
    
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

//----------------------------------------------Screen 4-----------------------------------------------------

    Text title_4;
    Button level_2_button;
    Button level_3_button;
    Button level_4_button;
    Button level_5_button;
    Button level_6_button;
    Button level_7_button;
    Button level_8_button;

    void level_2();
    void level_3();
    void level_4();
    void level_5();
    void level_6();
    void level_7();
    void level_8();
    void next_4();
    static void cb_level_2(Address, Address);
    static void cb_level_3(Address, Address);
    static void cb_level_4(Address, Address);
    static void cb_level_5(Address, Address);
    static void cb_level_6(Address, Address);
    static void cb_level_7(Address, Address);
    static void cb_level_8(Address, Address);
    
public: 
    
    void build_win_4();
    void design_win_4();
    void takedown_win_4();
	
//----------------------------------------Screen 5---------------------------------

	Circle sattelite_1;
	Circle sattelite_2;
	Circle sattelite_3;
	Circle sattelite_4;
	Circle sattelite_5;
	Circle sattelite_6;
	Circle sattelite_7;
	Circle sattelite_8;
	
	Point p1;
	Point p2;
	Point p3;
	Point p4;
	Point p5;
	Point p6;
	Point p7;
	Point p8;
	
	Image mercator_map;
	
	Button sattelite_1_button;
	Button sattelite_2_button;
	Button sattelite_3_button;
	Button sattelite_4_button;
	Button sattelite_5_button;
	Button sattelite_6_button;
	Button sattelite_7_button;
	Button sattelite_8_button;
	
	void reset_sat_bools();
	
	bool sat_1_pressed;
	bool sat_2_pressed;
	bool sat_3_pressed;
	bool sat_4_pressed;
	bool sat_5_pressed;
	bool sat_6_pressed;
	bool sat_7_pressed;
	bool sat_8_pressed;
	
	Button north_button;
	Button south_button;
	Button east_button;
	Button west_button;
	
//	bool north_pressed;
//	bool south_pressed;
//	bool east_pressed;
//	bool west_pressed;

	void sattelite_1_chosen();
	void sattelite_2_chosen();
	void sattelite_3_chosen();
	void sattelite_4_chosen();
	void sattelite_5_chosen();
	void sattelite_6_chosen();
	void sattelite_7_chosen();
	void sattelite_8_chosen();
	
	void move_north();
	void move_south();
	void move_east();
	void move_west();
	
	void wraparound_check(Point& p, Circle& c, Widget& w);
	
	void shift_up(Shape& c, Widget& w);
	void shift_down(Shape& c, Widget& w);
	void shift_right(Shape& c, Widget& w);
	void shift_left(Shape& c, Widget& w);
	
	int moves_remaining;
	
	static void cb_sat_1(Address, Address);
	static void cb_sat_2(Address, Address);
	static void cb_sat_3(Address, Address);
	static void cb_sat_4(Address, Address);
	static void cb_sat_5(Address, Address);
	static void cb_sat_6(Address, Address);
	static void cb_sat_7(Address, Address);
	static void cb_sat_8(Address, Address);
	
	static void cb_north(Address, Address);
	static void cb_south(Address, Address);
	static void cb_east(Address, Address);
	static void cb_west(Address, Address);

	void design_sattelites();
	void design_win_5();
	void build_win_5();
};