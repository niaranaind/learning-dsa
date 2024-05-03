#include<iostream>
using namespace std;

class Animal{

    public:
    int age;
    int heigth;
    int weigth;

    void speak(){
        cout<<"speaking "<<endl;
    }
};

class Dog: public Animal{ // single Inheritance 

    public:
    string color;

    void talk(){
        cout<<" dog is talking "<<endl;
    }

};

int main(){

    Dog d;
    cout<<d.age<<endl;

    d.speak();

    return 0;
}