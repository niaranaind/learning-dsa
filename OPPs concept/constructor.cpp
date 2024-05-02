#include<iostream>
#include<string.h>
using namespace std;

class Hero{

    private:
    int health;

    public:
    char *name;
    char level;

    void print(){
        cout<<endl;
        cout<<"[ name: "<<this->name<<" ,";
        cout<<"health is: "<<this->health<<" ,";
        cout<<"level is: "<<this->level<<" ]";
        cout<<endl;
    }

    Hero(){
        cout<<"simple constructor is called "<<endl;
        name= new char[7];
    }

    //parameterised constructor
    Hero(int health){
        cout<<"this-> "<<this<<endl;
        this->health=health;
    }

    Hero(int health,int level){
        this->health=health;
        this->level=level;
    }

    //creating copy constructor
    Hero(Hero &temp){

        char *ch= new char[strlen(temp.name)+1];
        strcpy(ch,temp.name);
        this->name=ch;
        
        cout<<"copy constructor is called "<<endl;
        this->health=temp.health;
        this->level=temp.level;
    }

    //getter and setter function for peivate data member
    void sethealth(int h){
        health=h;
    }

    int gethealth(){
        return health;
    }

    void setlevel(char ch){
        level=ch;
    }

    char getlevel(){
        return level;
    }

    void setname(char name[]){
        strcpy(this->name,name);
    }

    
};

int main(){

    //creation of object
    Hero h;

    Hero *h1=new Hero();  //dynamically alloaction

    Hero ramesh(10);

    cout<<"address of ramesh "<<&ramesh<<endl;

    ramesh.gethealth();

    Hero *h3 =new Hero(10);

    h3->gethealth();
    h3->print();

    Hero temp(30,'C');
    temp.print();

    //copy constructor
    Hero suresh(20,'k');
    suresh.print();

    Hero r(suresh); //copy constructor is called
    // r.sethealth(suresh.gethealth());
    // r.level=suresh.level;  here we are copying the constructor
    r.print();

    Hero hero1;
    hero1.sethealth(20);
    hero1.setlevel('D');
    char name[7]="Babbar";
    hero1.setname(name);

    hero1.print();

    //call default copy constructor
    Hero hero2(hero1);

    hero2.print(); 
    //hero2 = hero1

    hero1.name[0]='G';
    hero1.print();


    hero2.print(); //here we can see shallow copy

    hero1=hero2;

    hero1.print();
    hero2.print();

    



    return 0;

}