#include<iostream>
#include<vector>
using namespace std;

class solution{
    private:
    bool isSafe(int newx,int newy,vector<vector<int>> &arr,int n,vector<vector<int>> &vis){

        if((newx >= 0 && newx < n)&&( newy >= 0 && newy < n)&& vis[newx][newy] != 1 && arr[newx][newy] == 1){
            return true;
        }
        else{
            return false;
        }
    }
    void solve(int x,int y,vector<vector<int>> &arr,int n, vector<string> &ans,vector<vector<int>> &vis,string path){

        //base case
        if(x == n-1 && y == n-1){
            ans.push_back(path);
            return;
        }

        //mark visited position true
        vis[x][y] = 1;
        //All possible movement - D,L,R,U
        //Down
        if(isSafe(x+1,y,arr,n,vis)){
            solve(x+1,y,arr,n,ans,vis,path+"D");
        }

        if(isSafe(x,y-1,arr,n,vis)){
            solve(x,y-1,arr,n,ans,vis,path+"L");
        }

        if(isSafe(x,y+1,arr,n,vis)){
            solve(x,y+1,arr,n,ans,vis,path+"R");
        }

        if(isSafe(x-1,y,arr,n,vis)){
            solve(x-1,y,arr,n,ans,vis,path+"U");
        }

        vis[x][y] = 0; //backtracking
    }
    public:
    vector<string> searchMaze(vector<vector<int>> &arr ,int n){

        vector<string> ans;
        string path = "";
        if(arr[0][0] == 0){
            return ans;
        }
        //visited array
        vector<vector<int>> visited(n,vector<int> (n,0));
        solve(0,0,arr,n,ans,visited,path);

        return ans;
    }
};

int main(){
    //write your test code here
    vector<vector<int>> arr = {{1,0,0,0},{1,1,0,0},{1,1,0,0},{0,1,1,1}};
    int n = 4;

    solution sr;
    for(auto i:sr.searchMaze(arr,n)){
        cout<<i<<endl;
    }
    cout<<endl;

    return 0;
}