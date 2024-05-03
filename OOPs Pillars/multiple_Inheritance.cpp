#include<iostream>
using namespace std;

class Animal{

    public:
    int age;
    int heigth;
    int weigth;

    void bark(){
        cout<<" barking "<<endl;
    }
};

class Human{

    public:
    string color;

    void speak(){
        cout<<" speaking "<<endl;
    }
};

//Multiple Inheritance
class Hybrid: public Animal, public Human{

};

int main(){

    Hybrid obj1;

    obj1.bark();
    obj1.speak();

    return 0;
}