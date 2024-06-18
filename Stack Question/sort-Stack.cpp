#include<iostream>
#include<stack>
using namespace std;

class solution{

    private:
    void insertSortedWay(stack<int> &s,int num){

        //base case
        if(s.empty() || s.top() < num){
            s.push(num);
            return;
        }

        //store the top element
        int n = s.top();
        s.pop();

        //recursive call
        insertSortedWay(s,num);

        //back tracking 
        s.push(n);
    }

    public:
    void sortStack(stack<int> &stack){
        //base case
        if(stack.empty()){
            return;
        }

        //store the top element
        int num = stack.top();
        stack.pop();

        //recursive call
        sortStack(stack);

        insertSortedWay(stack,num);
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
    st.push(3);
    st.push(-7);
    st.push(9);
    st.push(-2);
    st.push(5);
    
    cout<<"size of the stack is : "<<st.size()<<endl;
    print(st);

    solution sol;
    //sorting stack using recursion
    sol.sortStack(st);

    print(st);

    return 0;
}