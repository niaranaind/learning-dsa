#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<unordered_map>
using namespace std;

bool isCyclicDFS(int node,int parent,unordered_map<int,bool> &visited,unordered_map<int,list<int>> &adj){

    visited[node] = true;

    for(auto neighbour : adj[node]){
        if(!visited[neighbour]){
            bool cycleDetection = isCyclicDFS(neighbour,node,visited,adj);
            if(cycleDetection)
            return true;
        }
        else if(neighbour != parent){
            //cycle present
            return true;
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    unordered_map<int,list<int>> adj;
    for(int i = 0 ; i<m ; i++){
        //creating node
        int u = edges[i][0];
        int v = edges[i][1];

        //undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int,bool> visited;
    for(int i = 0 ; i<n ; i++){
        if(!visited[i]){
            bool ans = isCyclicDFS(i,-1,visited,adj);
            if(ans == true)
            return "Yes";
        }
    }
    return "No";
}

int main(){
    //write your test case here
    int n,m;

    cout<<"enter the number of node : ";
    cin>>n;

    cout<<"enter the number of edge : ";
    cin>>m;

    vector<vector<int>> edge  = {{1,2},{2,3}};

    cout<<"cyclic is present : "<<cycleDetection(edge,n,m)<<endl;

    return 0;
}