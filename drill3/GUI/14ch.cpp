/*

g++ 14ch.cpp  -o ch14  && ./ch14
*/
#include "std_lib_facilities.h"
//1
class B1{
    public:
        void f(){
            cout << "B1::f()"<< endl;
        }

        void vf(){
            cout << "B1::vf()"<< endl;
        }

        void pvf(){
            cout << "B1::pvf()"<< endl;
        }



};
//2
class D1: public B1{

public:
    void f(){
            cout << "D1::f()"<< endl;
        }

    void vf(){
        cout << "D1::vf()" << endl;

    }

    //5
    void pvf(){
        cout << "D1::pvf()"<<endl;
    }

    

};

class D2: public D1{
    public:
        void pvf()  {
            cout << "D2::pvf()"<< endl;
        }
};



class B2{
    public:
    virtual void pvf() =0;
};

class D21:public B2{
    public:
    string data1;
    void pvf() override{
        cout << data1 << endl;
    }
};


class D22:public B2{
    public:
        int data2int;
        void pvf() override{
            cout << data2int << endl;

        }

        void f(B2& ref){
            ref.pvf();
        }

};

int main(){
    //1
    cout << "1. feladat B1" << endl;
    B1 b1_obj;
    b1_obj.f();
    b1_obj.vf();

    //5
    b1_obj.pvf();
   
   //2
   cout << "2. feladat D1" << endl;
    D1 d1_obj;
    d1_obj.f();
    d1_obj.vf();
    
    cout << "b1ref" << endl;
    B1& b1_ref_obj=d1_obj;
    b1_ref_obj.f();
    b1_ref_obj.vf();

    //5
    cout << "5. feladat b1,d1,b1ref" << endl;
    b1_obj.pvf();
    d1_obj.pvf();
    b1_ref_obj.pvf();


    //6
    cout << "6. feladat D2" << endl;
    D2 d2_obj;
    d2_obj.pvf();
    d2_obj.vf();
    d2_obj.f();

    //7
    cout << "7 feladat D21,D22 pvf" << endl;
    D21 d21_obj;
    d21_obj.pvf();
    D22 d22_obj;
    d22_obj.pvf();

    d21_obj.data1="String override";
    d22_obj.data2int=22;

    d22_obj.f(d21_obj);
    d22_obj.f(d22_obj);

return 0;
    
}