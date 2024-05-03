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

class Dog: public Animal{ 

    public:
    string color;

    void talk(){
        cout<<" dog is talking "<<endl;
    }

};

class GermanShepherd: public Dog{ //multi level Inheritance

};

int main(){

    GermanShepherd g;

    g.speak();

    return 0;
}