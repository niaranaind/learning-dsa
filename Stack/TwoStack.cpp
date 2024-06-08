
#include<iostream>
using namespace std;

class TwoStack{

    int* arr;
    int top1;
    int top2;
    int size;

    public:
    //constrcutor
    TwoStack(int size){
        this->size = size;
        arr = new int[size];
        this->top1 = -1;
        this->top2 = size;
    }

    //push operation for stack 1
    void push1(int data){

        if(top2 - top1 > 1){
            top1++;
            arr[top1] = data;
        }
        else{
            cout<<"stack 1 overflow "<<endl;
        }
    }

    //push operation for stack 2
    void push2(int data){

        if(top2 - top1 > 1){
            top2--;
            arr[top2] = data;
        }
        else{
            cout<<"stack 2 overflow "<<endl;
        }
    }

    //pop operation for stack 1
    int pop1(){

        if(top1 == -1){
            cout<<"stack 1 underflow "<<endl;
            return -1;
        }

        int ans = arr[top1];
        top1--;
        return ans;
    }

    //pop operation for stack 2
    int pop2(){

        if(top2 == size){
            cout<<"stack 2 underflow "<<endl;
            return -1;
        }

        int ans = arr[top2];
        top2++;
        return ans;
    }

    //print stack1
    void printstack1(){

        if(top1 == -1){
            cout<<"stack is empty"<<endl;
            return;
        }

        for(int i=0;i<=top1;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    //print stack2
    void printstack2(){

        if(top2 == size){
            cout<<"stack is empty "<<endl;
            return;
        }

        for(int i=top2;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){

    //write your test case here
    TwoStack st(6);

    st.push1(1);
    st.push1(2);
    st.push1(3);
    st.push2(5);
    st.push2(4);

    st.push1(6);
    st.push1(7);
    st.printstack1();
    st.printstack2();

    cout<<"stack 1 pop element: "<<st.pop1()<<endl;
    cout<<"stack 2 pop element: "<<st.pop2()<<endl;

    return 0;

}