#include<iostream>
using namespace std;

//Hybrid Inheritance
class A{

    public:
    void func1(){
        cout<<"Inside function 1 "<<endl;
    }
};

class F{

    public:
    void func2(){
        cout<<"Inside function 2 "<<endl;
    }
};

class B: public A,public F{ //multiple inheritance 

    public:
    void func3(){
        cout<<"Inside function 3 "<<endl;
    }
};

class C: public A{ //hierarchical inheritance

    public:
    void func4(){
        cout<<"Inside function 4 "<<endl;
    }
};

class D: public C{ //multi level inheritance

    public:
    void func5(){
        cout<<"Inside function 5 "<<endl;
    }
};

class E: public C{

    public:
    void func6(){
        cout<<"Inside function 6 "<<endl;
    }
};

int main(){

    D object1;
    object1.func1();
    object1.func4();
    object1.func5();


    E object2;
    object2.func1();
    object2.func4();

    B object3;
    object3.func1();
    object3.func2();

    return 0;


}