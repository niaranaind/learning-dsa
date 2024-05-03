#include<iostream>
using namespace std;

class A{

    public:
    void sayHallo(){
        cout<<"My name is niaran "<<endl;
    }

    int  sayHallo(string name,int n){
        cout<<"My name is niaran "<<endl;
        return n;
    }

    void sayHallo(string name){
        cout<<"My name is "<<name<<endl;
    }
};

class B{

    public:
    int a;
    int b;

    public:
    int add(){
        return a+b;
    }

    void operator+ (B &obj){
        int value1=this->a;
        int value2=obj.a;

        cout<<"output :"<<value1-value2<<endl;
    }

    void operator() (){

        cout<<"ya bracket hai"<<endl;
    }


};

int main(){

    A obj;
    obj.sayHallo();

    B obj1,obj2;
    obj1.a=7;
    obj2.a=4;

    obj1+obj2;

    obj1();

    return 0;
}