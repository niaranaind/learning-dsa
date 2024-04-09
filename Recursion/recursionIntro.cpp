#include<iostream>
using namespace std;

class solution{

    public:
        //factorial of a number
        int factorial(int n){

        //base case
        if(n==0){

        return 1;
      }
    
        //recursive relation
        int ans = n * factorial(n-1);

       return ans;
    }
      
      //power of a number
      int powerOfTwo(int n){

       //base case
       if(n==0){

        return 1;
       }

       //recursive relation
        int ans=2*powerOfTwo(n-1);

        return ans;
    }

};

int main(){

    solution sr;

    int n;
    cout<<"enter the number:";
    cin>>n;

    int ans =sr.factorial(n);

    cout<<"factorial of given number is: "<<ans<<endl;

    cout<<"power of two(2^n) is: "<<sr.powerOfTwo(n)<<endl;

    return 0;
}

