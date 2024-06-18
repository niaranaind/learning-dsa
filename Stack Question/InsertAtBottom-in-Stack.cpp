#include<iostream>
#include<stack>
using namespace std;

class solution{

    private:
    void solve(stack<int> &myStack, int x){

        //base case
        if(myStack.empty()){
            myStack.push(x);
            return;
        }

        int num = myStack.top();
        myStack.pop();

        //recursive call
        solve(myStack,x);

        myStack.push(num);
    }

    public:
    stack<int> pushAtBottom (stack<int> &myStack, int x){
        // x is the element that you need to insert
        solve(myStack,x);
        return myStack;
    }
};

void print(stack<int> s){

    while(!s.empty()){
        int top = s.top();
        cout<<top<<" ";
        s.pop();
    }
    cout<<endl;
}

int main(){

    stack<int> s;
    s.push(5);
    s.push(4);
    s.push(1);
    s.push(7);

    cout<<"size of stack: "<<s.size()<<endl;

    print(s);

    int x;
    cout<<"enter the element that you want to insert: ";
    cin>>x;

    solution sol;

    //insertion a bottom of the stack;
    stack<int> ans = sol.pushAtBottom(s,x);

    print(ans);

    return 0;
}