#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<list>
using namespace std;

void createEdge(unordered_map<int,list<int>> &edgeList,vector<vector<int>> &adj){

    for(int i = 0; i<adj.size(); i++){
        //create node
        int u = adj[i][0];
        int v = adj[i][1];

        //directed graph
        edgeList[u].push_back(v);
    }
}

void bfs(unordered_map<int,list<int>> &edgeList,unordered_map<int,bool> &visited,vector<int> &ans,int node){

    queue<int> q;
    q.push(node);
    visited[node] = true;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        //insert in ans vector
        ans.push_back(frontNode);
        for(auto i : edgeList[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    // Write your code here.
    unordered_map<int,list<int>> edgeList;
    vector<int> ans;
    unordered_map<int,bool> visited;

    createEdge(edgeList,adj);

    for(int i = 0 ; i<n ; i++){
        if(!visited[i]){
            bfs(edgeList,visited,ans,i);
        }
    }

    return ans;
}

int main(){

    vector<vector<int>> edge = {{0,1},{0,2},{0,3},{1,4},{1,7},{2,5},{3,6}};

    vector<int> ans = bfsTraversal(8,edge);

    for(auto i:ans){
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}