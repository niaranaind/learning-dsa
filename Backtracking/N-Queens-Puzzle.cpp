#include<iostream>
#include<vector>
using namespace std;

class solution{
    private:
    void addSolution(vector<vector<int>> &board , vector<vector<int>> &ans,int n){

        vector<int> temp;
        for(int i = 0;  i<n ; i++){
            for(int j = 0; j<n ; j++){
                temp.push_back(board[i][j]);
            }
        }
        ans.push_back(temp);
    }

    bool isSafe(int row,int col,vector<vector<int>> &boarad,int n){

        int x = row;
        int y = col;

        //row check
        while(y >= 0){
            if(boarad[x][y] == 1)
            return false;
            y--;
        }

        //diagonal check up and down
        x = row;
        y = col;
        while(x >= 0 && y >= 0){
            if(boarad[x][y] == 1)
            return false;
            x--;
            y--;
        }

        x = row;
        y = col;
        while(x < n && y >= 0){
            if(boarad[x][y] == 1)
            return false;
            x++;
            y--;
        }

        return true;
    }

    void solve(int col,vector<vector<int>> &board,vector<vector<int>> &ans,int n){
        //base case
        if(col == n){
            addSolution(board,ans,n);
            return;
        }

        //traversing all rows of first col
        for(int row = 0; row < n ; row++){
            
            if(isSafe(row,col,board,n)){
                //we can place queen
                board[row][col] = 1;
                solve(col+1 , board, ans, n);
                //backtracking
                board[row][col] = 0;
            }
        }
    }
    public:
    vector<vector<int>> nQueens(int n){

        vector<vector<int>> board(n, vector<int> (n,0));
        vector<vector<int>> ans;

        solve(0,board,ans,n);
        return ans;
    }
};

int main(){
    //write your test code here
    int n;
    cout<<"Enter the number of Queen : ";
    cin>>n;

    solution sr;
    vector<vector<int>> ans = sr.nQueens(n);
    
    for(int i = 0; i < ans.size() ; i++){

        for(int j = 0 ; j<ans[i].size() ; j++){

            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    return 0;
}