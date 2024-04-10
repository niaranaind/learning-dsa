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