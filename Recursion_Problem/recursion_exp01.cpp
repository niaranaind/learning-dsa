//program to move from home to destination
#include<iostream>
using namespace std;

class solution{

    public:

    void reachHome(int src,int dest){

        cout<<"source "<<src<<" "<<"destination "<<dest<<endl;  //checking

        if(src==dest){//base case

            cout<<"reached home "<<endl;
            return ;
        }

        src++;  //processing part

        reachHome(src,dest); //recursive call
    }
};

int main(){

    solution sr;

    int src=1;
    int dest=10;

    cout<<endl;

    sr.reachHome(src,dest);

    return 0;


}