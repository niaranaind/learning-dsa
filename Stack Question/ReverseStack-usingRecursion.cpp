#include<iostream>
#include<stack>
using namespace std;

class solution{

    private:
    void insertAtBottom(stack<int> &s,int x){

        //base case
        if(s.empty()){
            s.push(x);
            return;
        }

        //store the top element 
        int num = s.top();
        s.pop();

        //recursive call
        insertAtBottom(s,x);

        //back tracking 
        s.push(num);
    }

    public:
    void reverseStack( stack<int> &stack){

        //base case
        if(stack.empty()){
            return;
        }

        //store the top element
        int num = stack.top();
        stack.pop();

        //reversive call
        reverseStack(stack);

        //insert at bottom of stack
        insertAtBottom(stack,num);
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

    stack<int> st;
    st.push(9);
    st.push(7);
    st.push(4);
    st.push(3);

    print(st);

    solution sol;
    //reversing the stack using recursion
    sol.reverseStack(st);

    print(st);

    return 0;

}