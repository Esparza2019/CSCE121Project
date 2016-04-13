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

struct Game_window : Graph_lib::Window
{
	Game_window(Point p, int w, int h, String name);
	
private:

	In_box user_initials;
	vector<Text*> initials_and_scores;
	vector<high_score> scores;
	Button continue_button;
	Text high_scores;
	Image background;
	
	void next_button();
	void read_initials_and_scores(vector<high_score>& s, istream& is);
	void sort_scores(vector<high_score>& s, vector<Text*>& t);
};