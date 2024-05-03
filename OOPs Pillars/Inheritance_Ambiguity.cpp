#include<iostream>
using namespace std;

class A{

    public:
    void func(){
        cout<<" Im in class A "<<endl;
    }
};

class B{

    public:
    void func(){
        cout<<" Im in class B "<<endl;
    }
};

class C: public A,public B{

    
};

int main(){

    C obj;
   // obj.func();//error func is ambiguous

   obj.A::func();  // scope resolution operator to solve inheritance ambiguity

   obj.B::func();

    return 0;
}