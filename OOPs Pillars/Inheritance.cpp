#include<iostream>
using namespace std;

/* when base class data member is public and inheritance mode is public/protected/private  */
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

class male:public human{  //inhertiance mode is public

    public:
    string color;

    void sleep(){
        cout<<"male sleeping "<<endl;
    }

};

class female:protected human{  //inhertiance mode is protected
 
    public:
    string color;

    void sleep(){
        cout<<"female is sleeping"<<endl;
    }

    int getheigth(){
        return this->heigth;
    }
};

class trans: private human{  //inhertiance mode is pivate

    public:
    string color;

    void sleep(){
        cout<<"trans is sleeping "<<endl;
    }

    int getheigth(){
        return this->heigth;
    }
};

/*when base class data member is priavte and inheritance mode is public /protected /private */

class human1{

    protected:
    int heigth;

    public:
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

class male1:public human1{  //inhertiance mode is public

    public:
    string color;

    void sleep(){
        cout<<"male sleeping "<<endl;
    }

};

class female1:protected human1{  //inhertiance mode is protected
 
    public:
    string color;

    void sleep(){
        cout<<"female is sleeping"<<endl;
    }

    int getheigth(){
        return this->heigth;
    }
};

class trans1: private human1{  //inhertiance mode is pivate

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

    male1 m; 
    // cout<<m.heigth<<endl;  shows error because heigth is in protected mode

    female1 f;
    // cout<<f1.heigth<<endl; shows error because heigth is in protected mode

    trans1 t;
    // cout<<t.heigth<<endl; shows error because heigth is in private mode

    return 0;
}