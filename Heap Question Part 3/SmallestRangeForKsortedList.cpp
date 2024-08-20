#include<iostream>
#include<vector>
#include<limits.h>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    int row;
    int col;

    node(int d,int i,int j){
        data = d;
        row = i;
        col = j;
    }
};

class compare{
    public:
    bool operator()(node* a,node* b){
        return a->data > b->data;
    }
};


int kSorted(vector<vector<int>> &a,int k ,int n) {
    // Write your code here.
    priority_queue<node*,vector<node*>,compare> minHeap;
    int mini = INT_MAX ;
    int maxi = INT_MIN;

    for(int i = 0 ; i<k ; i++){
        int element = a[i][0];
        mini = min(mini,element);
        maxi = max(maxi,element);
        minHeap.push(new node(element,i,0));
    }

    int start = mini, end = maxi;

    while(!minHeap.empty()){
        //min fetch
        node* temp = minHeap.top();
        minHeap.pop();

        mini = temp->data;

        if(maxi - mini < end - start){
            start = mini;
            end = maxi;
        }

        if(temp->col + 1 < n){
            maxi = max(maxi,a[temp->row][temp->col+1]);
            minHeap.push(new node(a[temp->row][temp->col+1],temp->row,temp->col +1));
        }
        else{
            break;
        }
    }

    return end-start+1;
}

int  main(){
    
    vector<vector<int>> a = {{1, 10, 11}, {2, 3, 20}, {5, 6, 12} };
    
    cout<<kSorted(a,3,3)<<endl;
    
    return 0;
}