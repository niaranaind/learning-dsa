#include<iostream>
#include<vector>
using namespace std;

class solution{
    private:
    void heapify(vector<int> &arr,int n,int i){

        int largest = i;
        int left = 2*i+1;
        int right = 2*i+2;

        if(left < n && arr[largest] < arr[left]){
            largest = left;
        }

        if(right < n && arr[largest] < arr[right]){
            largest = right;
        }

        if(largest != i){
            swap(arr[largest],arr[i]);
            heapify(arr,n,largest);
        }
    }
    public:
    vector<int> mergeHeaps(vector<int> &a,vector<int> &b ,int n,int m){
        //step 1: merge both array into one
        vector<int> ans;
        for(auto i:a){
            ans.push_back(i);
        }

        for(auto i:b){
            ans.push_back(i);
        }

        int size = ans.size();
        for(int i = size/2-1 ; i>=0 ; i--){
            heapify(ans,size,i);
        }

        return ans;
    }
};

int main(){
    //write your test case here
    vector<int> a = {10,5,6,2};
    vector<int> b = {12,7,9};

    solution sr;
    vector<int> ans = sr.mergeHeaps(a,b,a.size(),b.size());

    for(auto i:ans){
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}