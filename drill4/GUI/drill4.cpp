
/*
    g++ drill4.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill4 `fltk-config --ldflags --use-images` -std=c++11 && ./drill4
*/


#include "Simple_window.h"
#include "Graph.h"

double one(double){return 1;}

double slope(double x){return x/2;}

double square(double x){return x*x;}
 
double sloping_cos(double x) {return cos(x)+slope(x);};


int main(){

    using namespace Graph_lib;

    int xmax=600;
    int ymax=600;

    Simple_window win{Point{100,100},xmax,ymax, "Funtion Graphs"};

    int x_orig=xmax/2;
    int y_orig=ymax/2;

    Point orig{x_orig,y_orig};

    int r_min=-10;
    int r_max=11;

    int x_scale=20;
    int y_scale=20;
    int n_points=400;



    int xlength = xmax-200; // make the axis a bit smaller than the window
    int ylength = ymax-200;
    Axis x {Axis::x,Point{100,y_orig},
    xlength, xlength/x_scale, "1 == 20 pixels"};
    Axis y {Axis::y,Point{x_orig, ylength+100},
    ylength, ylength/y_scale, "1 == 20 pixels"};

    y.set_color(Color::red);
    x.set_color(Color::red);

    Function s {one,r_min,r_max,orig,n_points,x_scale,y_scale};
    Function s2 {slope,r_min,r_max,orig,n_points,x_scale,y_scale};
    Function s3 {square,r_min,r_max,orig,n_points,x_scale,y_scale};

    
    Text ts2 {Point{100,y_orig+y_orig/2-20},"x/2"};

    Function parabola(square,r_min,r_max,orig,n_points,x_scale,y_scale);

    Function cosine{cos,r_min,r_max,orig,n_points,x_scale,y_scale};
    cosine.set_color(Color::blue);

    Function sloping_cosine{sloping_cos,r_min,r_max,orig,n_points,x_scale,y_scale};
    
    
    
    
    win.attach(ts2);
    

    win.attach(y);
    win.attach(x);
    win.attach(s);
    win.attach(s2);
    win.attach(s3);
    win.attach(parabola);
    win.attach(cosine);
    win.attach(sloping_cosine);
    win.wait_for_button();

}