#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

bool isCyclicBFS(int src,unordered_map<int,list<int>> &adj,unordered_map<int,bool> &visited){

    unordered_map<int,int> parent;
    parent[src] = -1;
    visited[src] = true;
    queue<int> q;
    q.push(src);

    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(auto neighbour : adj[front]){
            //check cyclic condition
            if(visited[neighbour] == true && neighbour != parent[front]){
                return true;
            }
            else if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour] = front;
            }
        }
    }

    return false;
}

string cycleDetection(vector<vector<int>> &edge,int n,int m){

    //creating adjacency list
    unordered_map<int,list<int>> adj;
    for(int i = 0 ; i<m ; i++){
        //creating node
        int u = edge[i][0];
        int v = edge[i][1];

        //undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int,bool> visited;
    for(int i = 0 ; i<n ; i++){

        if(!visited[i]){
            bool ans = isCyclicBFS(i,adj,visited);
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