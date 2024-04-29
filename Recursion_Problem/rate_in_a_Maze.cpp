#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class solution{

    private:
    bool isSafe(int x,int y,int n,vector<vector<int>> visited,vector<vector<int>> &m){

        if((x>=0 && x<n)&&(y>=0 && y<n) && (visited[x][y] == 0) && (m[x][y] == 1)){

            return true;
        }
        else{

            return false;
        }
    }
    void solve(vector<vector<int>> &m,int n,vector<string> &ans,int x,int y, vector<vector<int>> visited,string path){

        //base case
        if(x==n-1 && y==n-1){
            ans.push_back(path);
            return;
        }

        //you are in position (x,y)
        visited[x][y]=1;

        //possible movement D/L/R/U
        //Down
        int newx=x+1;
        int newy=y;
        if(isSafe(newx,newy,n,visited,m)){

            path.push_back('D');
            solve(m,n,ans,newx,newy,visited,path);
            path.pop_back(); //backtracking
        }

        //Left
        newx=x;
        newy=y-1;
        if(isSafe(newx,newy,n,visited,m)){

            path.push_back('L');
            solve(m,n,ans,newx,newy,visited,path);
            path.pop_back(); //backtracking
        }

        //Rigth
        newx=x;
        newy=y+1;
        if(isSafe(newx,newy,n,visited,m)){

            path.push_back('R');
            solve(m,n,ans,newx,newy,visited,path);
            path.pop_back(); //backtracking
        }

        //Up
        newx=x-1;
        newy=y;
         if(isSafe(newx,newy,n,visited,m)){

            path.push_back('U');
            solve(m,n,ans,newx,newy,visited,path);
            path.pop_back(); //backtracking
        }

        visited[x][y]=0; //backtracking


    }

    public:

    vector<string> findPath(vector<vector<int>> &m,int n){

        vector<string> ans;

        if(m[0][0]== 0){

            return ans;
        }

        int srcx=0;
        int srcy=0;

        string path="";

        vector<vector<int>> visited=m;
        for(int i=0;i<n;i++){

            for(int j=0;j<n;j++){

                visited[i][j]=0;
            }
        }

        solve(m,n,ans,srcx,srcy,visited,path);

        sort(ans.begin(),ans.end());

        return ans;
    }

};

int main(){
    int n;
    cout<<"enter the size of 2d vector: ";
    cin>>n;

    vector<vector<int>> m(n,vector<int>(n));

    //taking input in vector m
    for(int i=0;i<n;i++){

        for(int j=0;j<n;j++){
            cin>>m[i][j];
        }
    }cout<<endl;

    for(int i=0;i<n;i++){

        for(int j=0;j<n;j++){

            cout<<m[i][j]<<" ";
 
        }cout<<endl;
    }

    solution sr;

    vector<string> ans = sr.findPath(m,n);

    // printing ans
    for(int i=0;i<ans.size();i++){

        cout<<ans[i]<<" ";
    }cout<<endl;

    return 0;
}