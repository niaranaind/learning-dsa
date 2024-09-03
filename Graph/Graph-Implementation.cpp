#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;

class graph{
    public:
    unordered_map<int,list<int>> adj;

    //insertion in graph
    void addEdge(int u,int v,bool direction){
        //direction = 0 ->undirected graph
        //direction = 1-> directed graph
        adj[u].push_back(v);
        if(direction == 0){
            adj[v].push_back(u);
        }
    }

    //printing graph
    void printAdjList(){

        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }
};

vector<vector<int>> printAdjacency(int n, int m, vector < vector < int >> & edges){

    vector<int> ans[n];
    for(int i = 0 ; i<m ; i++){
        //creating node
        int u = edges[i][0];
        int v = edges[i][1];

        //undirected graph
        ans[u].push_back(v);
        ans[v].push_back(u);
    }

    vector<vector<int>> adj(n);
    for(int i = 0 ; i<n ; i++){
        adj[i].push_back(i);
        for(int j = 0 ; j<ans[i].size() ; j++){
            adj[i].push_back(ans[i][j]);
        }
    }

    return adj;
}

int main(){
    int n;
    cout<<"enter the number of node : ";
    cin>>n;

    int m;
    cout<<"enter the number of edge : ";
    cin>>m;

    graph g;

    for(int i = 0; i<m ; i++){
        int u,v;
        cin>>u>>v;
        //creating a undirected graph
        g.addEdge(u,v,0);
    }

    //printing graph
    g.printAdjList();

    vector<vector<int>> edge = {{0,1},{1,2},{2,3},{3,1},{3,4},{4,0}};

    vector<vector<int>> ans = printAdjacency(5,6,edge);

    for(auto i:ans){

        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}