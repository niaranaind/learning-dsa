#include<iostream>
using namespace std;

class student{

    private:  //since all the data member are private security is achieved 
    string name;
    int age;
    int height;

    public:
    int getage(){
        return age;
    }

};

int main(){

    student first; //object is created 

    cout<<"everything  is running good "<<endl;

    return 0;
}