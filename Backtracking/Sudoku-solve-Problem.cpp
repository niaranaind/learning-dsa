#include<iostream>
#include<vector>
using namespace std;

class solution{
    private:
    bool isSafe(int row ,int col , vector<vector<int>>& board, int val){

        for(int i = 0 ; i< board.size(); i++){
            //check row
            if(board[row][i] == val){
                return false;
            }

            //check column
            if(board[i][col] == val){
                return false;
            }
            //3x3 box check
            if(board[3*(row/3)+i/3][3*(col/3)+i%3] == val){
                return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<int>>& board){

        int n = board[0].size();
        for(int row = 0; row < n ; row++){

            for(int col = 0; col < n ; col++){

                if(board[row][col] == 0){
                    for(int val = 1 ; val <= n ; val++){
                        if(isSafe(row,col,board,val)){
                            //insert the value
                            board[row][col] = val;
                            bool nextSolution = solve(board);
                            if(nextSolution){
                                return true;
                            }
                            else{
                                //backtracking
                                board[row][col] = 0;
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    public:
    void solveSudoku(vector<vector<int>>& sudoku){

        solve(sudoku);
    }
};

int main(){
    //write your test case here
    vector<vector<int>> sudoku  = {{3, 0 ,6 ,5, 0, 8, 4 ,0 ,0},{5 ,2, 0 ,0 ,0 ,0 ,0 ,0 ,0},
    {0, 8, 7, 0, 0, 0, 0, 3, 1},{0 ,0,3,0,1,0,0,8, 0},{9 ,0, 0, 8, 6, 3 ,0, 0 ,5},{0, 5 ,0 ,0 ,9 ,0 ,6 ,0 ,0},{1, 3 ,0 ,0, 0 ,0 ,2 ,5, 0},
    {0, 0, 0, 0, 0, 0 ,0, 7, 4},{0, 0, 5 ,2, 0 ,6, 3, 0, 0}};

    solution sr;
    sr.solveSudoku(sudoku);

    for(int i = 0 ; i<9 ; i++){
        for(int j = 0; j<9 ; j++){
            cout<<sudoku[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}