#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
using namespace std;

void dfs(int node,unordered_map<int,list<int>> &adj,unordered_map<int,bool> &visited,vector<int> &component){

    //store ans
    component.push_back(node);
    //make visited true
    visited[node] = true;

    //recursive call for all connected node
    for(auto i: adj[node]){
        if(!visited[i]){
            dfs(i,adj,visited,component);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V,int E,vector<vector<int>> &edge){

    unordered_map<int,list<int>> adj;
    for(int i = 0 ; i < edge.size() ; i++){
        //create node
        int u = edge[i][0];
        int v = edge[i][1];

        //undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> ans;
    unordered_map<int,bool> visited;

    for(int i = 0 ; i < V; i++){
        if(!visited[i]){
            vector<int> component;
            dfs(i,adj,visited,component);
            ans.push_back(component);
        }
    }

    return ans;
}

int main(){
    //write your test case here
    int n;
    cout<<"enter the number of node : ";
    cin>>n;

    int m;
    cout<<"enter the number of edge : ";
    cin>>m;

    vector<vector<int>> edge = {{0,2},{0,1},{1,2},{3,4}};

    vector<vector<int>> ans  = depthFirstSearch(n,m,edge);

    for(auto i : ans){
        for(auto j : i){
            cout<<j<<" ";
        }
    }cout<<endl;

    return 0;
}