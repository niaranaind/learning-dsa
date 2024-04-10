/*Problem statement
You have been given a number of stairs. Initially, you are at the 0th stair, and you need to reach the Nth stair.



Each time, you can climb either one step or two steps.



You are supposed to return the number of distinct ways you can climb from the 0th step to the Nth step.*/
#include<iostream>
using namespace std;

class solution{

    public:

    int countDistinctWaysToClimbStairs(int n){

        //base case
        if(n<0)
        return 0;

        if(n==0){
            return 1;
        }

        //recursive relation
        int ans=countDistinctWaysToClimbStairs(n-1)+countDistinctWaysToClimbStairs(n-2);

        return ans;
    }
};

int main(){

    solution sr;

    int n;

    cout<<"enter the number of stairs: ";
    cin>>n;

    cout<<"the number of ways to climb is: "<<sr.countDistinctWaysToClimbStairs(n)<<endl;

    return 0;
}