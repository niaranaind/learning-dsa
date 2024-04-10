//fibonnacci series in c ++ program
#include<iostream>
using namespace std;

class solution{

    public:

    int fibonnacciElement(int n){

        if(n==0)  //base case
        return 0;

        if(n==1)  //2nd base case
        return 1;

        int ans =fibonnacciElement(n-1)+fibonnacciElement(n-2); //recursive relation

        return ans;
    }
};

int main(){

    solution sr;

    int n;
    cout<<"enter the index: ";
    cin>>n;

    cout<<"the term at nth index is: "<<sr.fibonnacciElement(n)<<endl;   

    return 0;
}