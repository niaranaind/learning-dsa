//head ans tail recursion in c++ program

#include<iostream>
using namespace std;

class solution{

    public:
    //printing counting 
    void print(int n){       //tail recursion

        if(n==0){  //base case

            return;
        }

        cout<<n<<" ";   //processing part

        print(n-1);    //recursive relation

    }

    //printing counting 
    void print02(int n){      //head recursion

        if(n==0){  //base case

            return;
        }

        print02(n-1);    //recursive relation

         cout<<n<<" ";   //processing part

    }
};

int main(){

    int n;
    cout<<"enter the number: ";
    cin>>n;

    solution sr;

    sr.print(n);

    cout<<endl;

    sr.print02(n);

    return 0;
}