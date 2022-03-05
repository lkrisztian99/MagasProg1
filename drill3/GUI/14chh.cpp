/*

g++ 14chh.cpp  -o ch14  && ./chh14
*/
#include "std_lib_facilities.h"

struct B1 {
    public:
    virtual void vf() const { cout << "B1::vf()"<< endl;}
    void f() const {  cout << "B1::f()"<< endl;}

};

struct D1: B1{

};



int main(){

    B1 b_obj;
    b_obj.vf();
    b_obj.f();

    return 0;
}

