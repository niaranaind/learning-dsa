#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<set>
#include<limits.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i = 0 ; i<edges ; i++){
        //create node
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        //unordered map
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    //creating distance array with infinite value initially
    vector<int> dist(vertices);
    for(int i = 0 ; i<vertices ; i++){
        dist[i] = INT_MAX;
    }

    //creation of set on basis of distance and node
    set<pair<int,int>> st;

    //initialise diatance and set with source node
    dist[source] = 0;
    st.insert(make_pair(0,source));

    while(!st.empty()){
        //fetch the top node
        auto top = *(st.begin());

        int nodeDistance = top.first;
        int topNode = top.second;

        //remove top record now
        st.erase(st.begin());

        //traverse the neighbour node
        for(auto neighbour : adj[topNode]){

            if(nodeDistance + neighbour.second < dist[neighbour.first]){

                //find the node in set and erase
                auto record = st.find(make_pair(dist[neighbour.first],neighbour.first));
                if(record != st.end()){
                    st.erase(record);
                }

                //distance update
                dist[neighbour.first] = nodeDistance + neighbour.second;
                //record push in set
                st.insert(make_pair(dist[neighbour.first],neighbour.first));
            }
        }
    }
    return dist;
    
}

int main(){
    //write your test code here
    vector<vector<int>> vec = {{0,1,5},{0,2,8},{1,2,9},{1,3,2},{2,3,6}};

    vector<int> distance = dijkstra(vec,4,5,0);

    for(auto i : distance){
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}