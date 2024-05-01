#include<iostream>
#include "villan.cpp"  //including external class file
using namespace std;

class Hero{

    //properties
    private:
    int health =100;

    public:
    char level ='A';

    //getter and setter function
    void sethealth(int h){
        health=h;
    }

    void setlevel(char ch){
        level=ch;
    }

    int gethealth(){
        return health;
    }

    char getlevel(){
        return level;
    }
};

int main(){

    //creation of object
    Hero h1;

    h1.sethealth(10); // setting the value at health private variable
    h1.level='A';

    cout<<"size is: "<<sizeof(h1)<<endl;

    cout<<"health is: "<<h1.gethealth()<<endl;
    cout<<"size is: "<<h1.level<<endl;

    //creating object
    villan v1;
    
    v1.health=10;
    v1.level='B';

    cout<<"size is: "<<sizeof(v1)<<endl;

    cout<<"health is: "<<v1.health<<endl;
    cout<<"level is: "<<v1.level<<endl;

    //static and dynamic memory allocation

    Hero h2;  //this is static allocation
    h2.sethealth(20);
    h2.setlevel('A');

    cout<<"health is: "<<h2.gethealth()<<endl;
    cout<<"level is: "<<h2.getlevel()<<endl;

    Hero *h3= new Hero;  //this dynamically allocation

    cout<<"health is: "<<(*h3).gethealth()<<endl;
    cout<<"level is: "<<(*h3).getlevel()<<endl;

    cout<<"health is: "<<h3->gethealth()<<endl;
    cout<<"level is: "<<h3->getlevel()<<endl;

    return 0;
}