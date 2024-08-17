#include<iostream>
#include<queue>
using namespace std;

class solution{
    public:
    long long minCost(long long arr[], long long n){

        priority_queue<long long,vector<long long>,greater<long long>> pq;
        for(int i = 0 ; i < n ; i++){
            pq.push(arr[i]);
        }

        long long cost = 0;
        while(pq.size()> 1){

            long long a = pq.top();
            pq.pop();

            long long b = pq.top();
            pq.pop();

            long long sum = a+b;
            cost += sum;

            pq.push(sum);
        }

        return cost;
    }
};

int main(){
    //write your test case here 
    long long arr[] = {4,3,2,6};
    long long n = 4;

    solution sr;
    cout<<"Minimum cost to build a rope is : "<<sr.minCost(arr,n)<<endl;

    return 0;
}