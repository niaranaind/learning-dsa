#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

class solution{
    public:
    //Approach 1
    int getKthLargest(vector<int> &arr,int k){

        vector<int> sumStore;
        int n = arr.size();
        for(int i = 0; i< n ; i++){
            int sum = 0;
            for(int j = i; j<n ; j++){

                sum+=arr[j];
                sumStore.push_back(sum);
            }
        }

        sort(sumStore.begin(),sumStore.end());
        return sumStore[sumStore.size()-k];
    }

    //Approach 2
    int getKthLargest2(vector<int> &arr,int k){

        priority_queue<int,vector<int>,greater<int>> minHeap;

        int n = arr.size();

        for(int i = 0 ; i<n ; i++){
            int sum = 0;
            for(int j = i ; j<n ; j++){

                sum+=arr[j];
                if(minHeap.size()<k){
                    minHeap.push(sum);
                }
                else{
                    if(sum > minHeap.top()){
                        minHeap.pop();
                        minHeap.push(sum);
                    }
                }
                
            }
        }
        return minHeap.top();
    }
};

int main(){
    //write your test case here
    vector<int> arr = {1, -2, 3, -4, 5};
    solution sr;

    cout<<"kth largest sum sub array is : "<<sr.getKthLargest2(arr,2)<<endl;
    
    cout<<"kth largest sum sub array is : "<<sr.getKthLargest(arr,2)<<endl;

    return 0;

}

