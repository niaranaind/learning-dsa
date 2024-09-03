#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
#include<list>
#include<limits.h>
using namespace std;

class Graph{
    public:
    unordered_map<int,list<pair<int,int>>> adj;
    void addEdges(int u,int v , int weight){
        pair<int,int> p = make_pair(v,weight);

        //directed acyclic graph
        adj[u].push_back(p);
    }

    void printAdj(){
        for(auto i : adj){
            cout<<i.first<<"->";
            for(auto j : i.second){
                cout<<"("<<j.first<<","<<j.second<<"),";
            }
            cout<<endl;
        }
    }

    //topological sort
    void dfs(int node,unordered_map<int,bool> &visited,stack<int> &topo){
        visited[node] = true;

        for(auto neightbour : adj[node]){
            if(!visited[neightbour.first]){
                dfs(neightbour.first,visited,topo);
            }
        }
        topo.push(node);
    }

    //sortest path
    void getSortestPath(int src,vector<int> &dist,stack<int> &topo){
        dist[src] = 0;

        while(!topo.empty()){
            int top = topo.top();
            topo.pop();

            if(dist[top] != INT_MAX){
                for(auto i : adj[top]){
                    if(dist[top] + i.second < dist[i.first]){
                        dist[i.first] = dist[top] + i.second;
                    }
                }
            }
        }
    }
};

int main(){

    Graph g;
    g.addEdges(0,1,5);
    g.addEdges(0,2,3);
    g.addEdges(1,2,2);
    g.addEdges(1,3,6);
    g.addEdges(2,3,7);
    g.addEdges(2,4,4);
    g.addEdges(2,5,2);
    g.addEdges(3,4,-1);
    g.addEdges(4,5,-2);

    g.printAdj();

    unordered_map<int,bool> visited;
    stack<int> s;
    int n = 6;
    for(int i = 0 ; i<n ; i++){
        if(!visited[i]){
            g.dfs(i,visited,s);
        }
    }

    int src = 1;
    vector<int> dist(n);
    for(int i = 0 ; i<n ; i++)
    dist[i] = INT_MAX;

    g.getSortestPath(src,dist,s);

    cout<<"Print answer : ";
    for(int i = 0; i<dist.size() ; i++){
        cout<<dist[i]<<" ";
    }cout<<endl;

    return 0;
}