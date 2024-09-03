#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    unordered_map<int,list<int>> adj;
    for(int i = 0; i<e ; i++){
        //create node
        int u = edges[i][0];
        int v = edges[i][1];

        //directed graph
        adj[u].push_back(v);
    }

    //indegree of all node
    vector<int> indegree(v);
    for(auto i :adj){

        for(auto j : i.second){
            indegree[j]++;
        }
    }

    //push 0 indegree node in queue
    queue<int> q;
    for(int i = 0; i<v ; i++){
        if(indegree[i] == 0)
        q.push(i);
    }

    //do BFS
    vector<int> ans;
    while(!q.empty()){
        int front = q.front();
        q.pop();

        //store  ans
        ans.push_back(front);
        for(auto neighbour : adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour] == 0)
            q.push(neighbour);
        }
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