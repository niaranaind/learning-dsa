#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
#include<algorithm>
using namespace std;

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// Write your code here
    unordered_map<int,list<int>> adj;
    for(int i = 0 ; i<m ; i++){
        //create node
        int u = edges[i].first;
        int v = edges[i].second;

        //directed graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //do BSF
    unordered_map<int,bool> visited;
    unordered_map<int,int> parent;
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(auto i:adj[front]){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
                parent[i] = front;
            }
        }
    }

    //shortest path
    vector<int> ans;
    int currentNode = t;
    ans.push_back(t);
    while(currentNode != s){
        currentNode = parent[currentNode];
        ans.push_back(currentNode);
    }
	
    reverse(ans.begin(),ans.end());

    return ans;
}

int main(){
    //write your test case here
    vector<pair<int,int>> edge = {{1,2},{2,3},{3,4},{1,3}};

    vector<int> ans = shortestPath(edge,4,4,1,4);

    for(auto i : ans){
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}