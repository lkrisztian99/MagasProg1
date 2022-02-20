#include "Simple_window.h"
#include "Graph.h"

double one(double) { return 1; }

double square(double x) { return x*x; }



int main(){

using namespace Graph_lib;


    int xmax = 1000;
    int ymax = 800;

    int x_grid=100;
    int y_grid=100;
    int x_size=800;
    int y_size=800;
    Lines grid;

    for(int x=x_grid;x<x_size+1;x+=x_grid){

        grid.add(Point(x,0),Point(x,y_size));
    }
    for(int y=y_grid;y<y_size;y+=y_grid){

        grid.add(Point(0,y),Point(x_size,y));
    }
  


   Vector_ref<Rectangle> vr;
    

    Simple_window win {Point{100,100}, xmax, ymax, "Canvas"};

     

    
        for (int j = 0; j<8; ++j) {
        vr.push_back(new Rectangle{Point{j*100,j*100},100,100});
        vr[vr.size()-1].set_fill_color(Color::red);
        win.attach(vr[vr.size()-1]);
        }

        Image miez {Point{0,200},"200.jpg"};
       Image miez1 {Point{0,400},"200.jpg"};
       Image miez4 {Point{0,600},"200.jpg"};
        win.attach(miez);
        win.attach(miez1);
        win.attach(miez4);

    win.attach(grid);

    int me=0;
    Image micsoda {Point{0,0},"100.jpg"};
       win.attach(micsoda);
    while(win.wait_for_button()){
       if(me==0){ micsoda.move(400,300); me=1;}
        else{micsoda.move(-400,-300);me=0;}
       

       
    }
    

}