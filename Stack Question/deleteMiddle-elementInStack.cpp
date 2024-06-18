#include<iostream>
#include<stack>
using namespace std;

class solution{

    private:
    void solve(stack<int> &inputStack,int count,int size){

        //base case
        if(count == size/2){
            inputStack.pop();
            return;
        }

        //storing the pop element
        int num = inputStack.top();
        inputStack.pop();

        //recursive call 
        solve(inputStack,count+1,size);

        //back tracking process
        inputStack.push(num);

    }

    public:
    void deleteMiddle(stack<int> &inputStack,int n){

        int count = 0;
        // n is the size of the stack
        solve(inputStack,count,n);
    }
};

void print(stack<int> st){

    while(!st.empty()){
        int k = st.top();
        cout<<k<<" ";
        st.pop();
    }
    cout<<endl;
}

int main(){

    stack<int> st;
    st.push(3);
    st.push(5);
    st.push(9);
    st.push(2);
    st.push(4);

    cout<<"size of the stack is: "<<st.size()<<endl;

    print(st);

    //deleting the middle element
    solution s;
    s.deleteMiddle(st,st.size());

    print(st);


    return 0;
}