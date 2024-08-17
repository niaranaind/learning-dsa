#include<iostream>
#include<queue>
using namespace std;

class solution{

    public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        priority_queue<int> pq;

        //step 1:
        for(int i = 0 ; i< k ; i++){
            pq.push(arr[i]);
        }

        //step 2:
        for(int i = k ; i < n; i++){
            if(arr[i] < pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }

        //step 3:
        int ans = pq.top();
        return ans;
    }
};

int main(){

    //write your test case here
    vector<int > arr = {7, 10 ,4,20,15};

    cout<<"enter the value of k : ";
    int k;
    cin>>k;

    solution sr;
    cout<<"kth smallest element in array is : "<<sr.kthSmallest(arr,k)<<endl;

    return 0;
}