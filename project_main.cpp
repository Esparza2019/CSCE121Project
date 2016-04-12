 #include "std_lib_facilities_4.h"
#include "Simple_window.h"
#include "Graph.h"
#include <FL/Fl_Multiline_Output.H>


int main()
try {
    using namespace Graph_lib;          //graphics
    
    Simple_window win0(Point(100,100),1500,900,"No Service");
    
    Image background{Point(0,0),"background.gif"};
    
    Text intro{Point(500,150),"No Service"};
    
    
    Text summary{Point(200,300), "No Service."};
    Text summary1{Point(200,400),"Today all connectivity was lost, our world's top minds are working hard to find a solution."};
    Text summary2{Point(200,500),"Normally this might've been an easy task, but without any communication its all up to you."};
    Text summary3{Point(200,600),"Our engineers have repaired some satelites and you need to place them and cover as many people as possible."};
    Text summary4{Point(200,700),"Click on any satellite to select it, and move it by pressing the movement buttons."};
    Text summary5{Point(200,800),"The game ends when no moves are left."};
        
    
    intro.set_color(Color::white);
    intro.set_font(FL_TIMES);
    intro.set_font_size(100);
    summary.set_color(Color::white);
    summary1.set_color(Color::white);
    summary2.set_color(Color::white);
    summary3.set_color(Color::white);
    summary4.set_color(Color::white);
    summary5.set_color(Color::white);
    
    summary.set_font_size(20);
    summary1.set_font_size(20);
    summary2.set_font_size(20);
    summary3.set_font_size(20);
    summary4.set_font_size(20);
    summary5.set_font_size(20);
    
    win0.attach(background);
    win0.attach(summary);
    win0.attach(summary1);
    win0.attach(summary2);
    win0.attach(summary3);
    win0.attach(summary4);
    win0.attach(summary5);
    win0.attach(intro);
    
    win0.wait_for_button();
    
   

return 0;
}
catch(exception& e) {
	cerr << "exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Some exception\n";
	return 2;
}
