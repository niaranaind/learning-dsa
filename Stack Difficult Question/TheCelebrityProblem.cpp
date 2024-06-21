#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class solution{

    private:
    bool knows(vector<vector<int>> &M,int a,int b, int n){
        if(M[a][b] == 1){
            return true;
        }
        else{
            return false;
        }
    }

    public:
    int celebrity(vector<vector<int>> &M, int n){

        stack<int> s;
        //step 1 push all the element in stack
        for(int i =0; i< n ;i++){
            s.push(i);
        }

        //step 2 get 2 element and compare them 
        while(s.size() > 1){

            int a = s.top();
            s.pop();

            int b = s.top();
            s.pop();

            if(knows(M,a,b,n)){
                s.push(b);
            }
            else{
                s.push(a);
            }
        }

        int ans = s.top(); //potentail celebrity candidate

        //step 3 verify the potential celebrity candidate 
        // check row 
        int rowCount = 0;
        bool rowCheck = false;
        for(int i =0 ;i < n; i++){
            if(M[ans][i] == 0)
            rowCount++;
        }
        if(rowCount == n){
            rowCheck = true;
        }

        //column check
        int colCount = 0;
        bool colCheck = false;
        for(int i=0 ; i<n ; i++){
            if(M[i][ans] == 1)
            colCount++;
        }
        if(colCount == n-1){
            colCheck = true;
        }

        if(rowCheck == true && colCheck == true){
            return ans;
        }
        else{
            return -1;
        }
    }
};

int main(){

    //write your test case here
    return 0;
}