#include<iostream>
using namespace std;

class solution{

    public:

    int powerofinteger(int a,int b){  //using loop approach

        int ans=1;
        for(int i=0;i<b;i++){

            ans=ans*a;
        }
        return ans;
    }

    int PowerOfIntegerRECURSION(int a,int b){ //using recursive approach

        //base case
        if(b==0){
            return 1;
        }

        if(b==1){
            return a;
        }

        int ans=PowerOfIntegerRECURSION(a,b/2); //recursive call

        if(b%2==0){
            //even power case
            return ans*ans;
        }
        else{
            //odd power case
            return a*ans*ans;
        }
    }
};

int main(){

    int a,b;

    cout<<"enter the a and b: ";
    cin>>a>>b;

    solution sr;

    cout<<"the power(a,b) is: "<<sr.powerofinteger(a,b)<<endl;

    cout<<"the power(a,b) is: "<<sr.PowerOfIntegerRECURSION(a,b)<<endl;

    return 0;
}