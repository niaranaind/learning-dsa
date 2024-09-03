#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
  unordered_map<int,list<int>> adj;
    for(int i = 0; i<edges.size() ; i++){
        //create node
        int u = edges[i].first-1;
        int v = edges[i].second-1;

        //directed graph
        adj[u].push_back(v);
    }

    //indegree of all node
    vector<int> indegree(n);
    for(auto i :adj){

        for(auto j : i.second){
            indegree[j]++;
        }
    }

    //push 0 indegree node in queue
    queue<int> q;
    for(int i = 0; i<n ; i++){
        if(indegree[i] == 0)
        q.push(i);
    }

    //do BFS
    int cnt = 0;
    while(!q.empty()){
        int front = q.front();
        q.pop();

        //count
        cnt++;
        for(auto neighbour : adj[front]){

            indegree[neighbour]--;
            if(indegree[neighbour] == 0)
            q.push(neighbour);
        }
    }
    
    if(cnt == n){
      return false;
    }
    else{
      return true;
    }
}

int main(){
    //write your test code here 
    vector<pair<int,int>> edges = {{1,2},{4,1},{2,4},{3,4},{5,2},{1,3}};

    cout<<"cycle detection in directed graph : "<<detectCycleInDirectedGraph(5,edges)<<endl;

    return 0;
}