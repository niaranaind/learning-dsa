#include<iostream>
#include<vector>
#include<stack>
#include<climits>
#define MAX 1000
using namespace std;

class solution{

    private:
    vector<int> nextSmallerElement(int *arr, int n){

        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i = n-1 ; i>=0 ;i++ ){
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerElement(int *arr,int n){

        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i = n-1 ; i>=0 ;i++ ){
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    int largestRectangleArea(int *heights ,int n){

        vector<int> next(n);
        next = nextSmallerElement(heights,n);

        vector<int> prev(n);
        prev = prevSmallerElement(heights,n);

        int area = INT_MIN;
        for(int i=0 ; i< n ;i++ ){

            int l = heights[i];
            if(next[i] == -1){
                next[i] = n;
            }
            int b = next[i] - prev[i] - 1;
            int newArea = l*b;

            area = max(area,newArea);
        }
        return area;
    }

    public:
    int maxArea(int M[MAX][MAX] ,int n,int m){

        //empty matrix case
        if(n == 0 || m == 0)
        return 0;
        
        //step 1 compute area for first row
        int area = largestRectangleArea(M[0],m);

        //step 2 for remaining row
        for(int i = 1; i<n ; i++ ){
            for(int j = 0 ; j<n ;j++){

                //row updating 
                if(M[i][j] != 0){
                    M[i][j] = M[i][j] + M[i-1][j];
                }
                else{
                    M[i][j] = 0;
                }
            }
            //entire row is update now 
            //calculate new area
            int newArea = largestRectangleArea(M[i],m);
            area = max(area,newArea);
        }
        return area;
    }
};

int main(){

    //write your test case here
    return 0;
}