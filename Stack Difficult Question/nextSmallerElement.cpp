#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class solution{

    public:
    vector<int> nextSmallerElement(vector<int> &arr,int n){
        // n is the size of vector
        stack<int> stack;
        stack.push(-1);
        vector<int> ans(n);
        for(int i=n-1 ; i>=0 ; i--){

            int currElement = arr[i];
            while(stack.top() >= currElement){

                stack.pop();
            }
            ans[i] = stack.top();
            stack.push(currElement);

        }
        return ans;
    }
};

int main(){

    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<endl;

    solution sol;
    vector<int> ans = sol.nextSmallerElement(arr,n);

    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}