#include<iostream>
#include<string.h>
using namespace std;

class Hero{

    private:
    int health;

    public:
    char level;
    char *name;
    static int timeToComplete;  //static data type decleration

    Hero(){
        cout<<"simple constrcutor called "<<endl;
        name= new char[100];
    }
    
    //parameterised constructor 
    Hero(char name[],int health,char level){

        this->name=new char[100];
        strcpy(this->name,name);

        this->health=health;
        this->level=level;
    }

    void print(){
        cout<<endl;
        cout<<"[ Name: "<<this->name<<" ,";
        cout<<"health: "<<this->health<<" ,";
        cout<<"level: "<<this->level<<" ]";
        cout<<endl;
    }

    ~Hero(){
        cout<<"destructor is called "<<endl;
    }

    static int random(){ //static function can access only static member
        return timeToComplete;
    }

};

int Hero::timeToComplete=5; // static data member initialisation

int main(){

    char name1[7]="Babbar";
    Hero hero1(name1,20,'D');
    hero1.print();

    char name2[7]="Gabbar";
    Hero hero2(name2,30,'C');
    hero2.print();

    // copy assignment operator '='

    hero1=hero2;
    hero1.print();
    hero2.print();

    Hero a;  //static 

    Hero *b= new Hero();  //dynamic

    delete b; //manually destructor is called for dynamic memeory

    cout<<Hero:: timeToComplete<<endl; 

    cout<<Hero::random()<<endl;

    return 0;
}