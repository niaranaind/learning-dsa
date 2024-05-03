#include<iostream>
using namespace std;

class human{

    public:
    int heigth;
    int weigth;

    private:
    int age;

    public:
    int getage(){
        return this->age;
    }

    void setweigth(int w){
        this->weigth=w;
    }
};

class male:public human{

    public:
    string color;

    void sleep(){
        cout<<"male sleeping "<<endl;
    }

};

class female:protected human{

    public:
    string color;

    void sleep(){
        cout<<"female is sleeping"<<endl;
    }

    int getheigth(){
        return this->heigth;
    }
};

class trans: private human{

    public:
    string color;

    void sleep(){
        cout<<"trans is sleeping "<<endl;
    }

    int getheigth(){
        return this->heigth;
    }
};

int main(){

    male m1;
    cout<<m1.heigth<<endl;

    female f1;
    // cout<<f1.heigth<<endl;  this line shows error 
    cout<<f1.getheigth()<<endl;

    trans t1;
    // cout<<t1.heigth<<endl;  this line shows error


    // male object1;
    // cout<<object1.age<<endl;
    // cout<<object1.weigth<<endl;
    // cout<<object1.heigth<<endl;

    // cout<<object1.color<<endl;
    // object1.setweigth( 84);
    // cout<<object1.weigth<<endl;
    // object1.sleep();

    return 0;
}