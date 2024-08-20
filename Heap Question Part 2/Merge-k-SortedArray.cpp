#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class node{
    public:
    int data;
    int i;
    int j;

    //constructor
    node(int data,int row ,int col){
        this->data = data;
        this->i = row;
        this->j = col;
    }
};

class compare{
    public:
    bool operator()(node* a,node* b){
        return a->data > b->data;
    }
};

class solution{
    public:
    vector<int> mergeKSortedArray(vector<vector<int>> &kArray,int k){

        priority_queue<node*,vector<node*>,compare> minHeap;

        //step1: all the first elemnt of all arrays should be inserted in minHeap
        for(int i=0 ; i<k ; i++){
            node* temp = new node(kArray[i][0],i,0);
            minHeap.push(temp);
        }

        vector<int> ans;

        while(!minHeap.empty()){
            node* temp = minHeap.top();
            ans.push_back(temp->data);
            minHeap.pop();

            int i = temp->i;
            int j = temp->j;

            if(j+1 < kArray[i].size()){
                node* next = new node(kArray[i][j+1],i,j+1);
                minHeap.push(next);
            }
        }

        return ans;
    }
};

int main(){
    //write your test case here
    vector<vector<int>> arr = {{3,5,9},{1,2,3,8}};

    solution sr;
    vector<int> ans = sr.mergeKSortedArray(arr,2);

    for(auto i:ans){
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}