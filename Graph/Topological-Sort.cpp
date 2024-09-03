#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
#include<list>
using namespace std;

void topoSort(int node,vector<bool> &visited, stack<int> &s,unordered_map<int,list<int>> &adj){

    visited[node] = true;

    for(auto neighbour : adj[node]){

        if(!visited[neighbour])
        topoSort(neighbour,visited,s,adj);
    }

    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    unordered_map<int,list<int>> adj;
    for(int i = 0 ; i<e ; i++){
        //create node
        int u = edges[i][0];
        int v = edges[i][1];

        //directed graph
        adj[u].push_back(v);
    }

    vector<bool> visited(v);
    stack<int> s;
    for(int i = 0 ; i<v ; i++){
        if(!visited[i]){
            topoSort(i,visited,s,adj);
        }
    }

    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}

int main(){
    //write your test case here
    vector<vector<int>> edge = {{0,1},{0,3},{1,2},{3,2}};

    vector<int> ans = topologicalSort(edge,4,4);

    for(auto i: ans){
        cout<<i<<" ";
    }

    return 0;
}