#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;

bool checkCycleDFS(int node,unordered_map<int,bool> &visited,unordered_map<int,bool> &dfsvisited,unordered_map<int,list<int>> &adj){

    visited[node] = true;
    dfsvisited[node] = true;

    for(auto neighbour : adj[node]){
        if(!visited[neighbour]){
            bool cycleDetect = checkCycleDFS(neighbour,visited,dfsvisited,adj);
            if(cycleDetect)
            return true;
        }
        else if(dfsvisited[neighbour]){
            //here visited[neighbour] = true
            return true;
        }
    }

    dfsvisited[node] = false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
  unordered_map<int,list<int>> adj;
  for(int i = 0 ; i<edges.size() ; i++){
    //creating node
    int u = edges[i].first;
    int v = edges[i].second;

    //directed graph
    adj[u].push_back(v);
  }

  //call dfs for all component
  unordered_map<int,bool> visited;
  unordered_map<int,bool> dfsvisited;
  for(int i = 0; i<n ; i++){
    if(!visited[i]){
        bool cycleFound = checkCycleDFS(i,visited,dfsvisited,adj);
        if(cycleFound)
        return true;
    }
  }
  return false;
}

int main(){
    //write your test code here 
    vector<pair<int,int>> edges = {{1,2},{4,1},{2,4},{3,4},{5,2},{1,3}};

    cout<<"cycle detection in directed graph : "<<detectCycleInDirectedGraph(5,edges)<<endl;

    return 0;
}