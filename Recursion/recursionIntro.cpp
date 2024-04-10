#include<iostream>
using namespace std;

/*recursion is function  that call itself 
another approach is that if we have a bigger problem set and its solution depend on smaller problem then 
here we can use recursion 

recursion mainly consist of three parts
1-> base case
2-> recursive relation
3-> processing part*/

class solution{

    public:
        //factorial of a number using recursion 
        int factorial(int n){

        //base case
        if(n==0){

        return 1;
      }
    
        //recursive relation
        int ans = n * factorial(n-1);

       return ans;
    }
      
      //power of a number using recursion
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

