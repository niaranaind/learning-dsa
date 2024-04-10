//fibonnacci series in c ++ program
/*
The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number 
is the sum of the two preceding ones, starting from 0 and 1. That is,

F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
Given n, calculate F(n).*/
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