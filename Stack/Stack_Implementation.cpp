#include<iostream>
#include<limits.h>
using namespace std;

class Stack{

    private:
    //properties
    int size;
    int* arr;
    int top;

    //constructor
    public:
    Stack(int size){
        this->size = size;
        arr = new int[size];
        this->top = -1;
    }

    //stack operation

    void push(int data){

        if(this->top == this->size -1){
            cout<<"stack overflow "<<endl;
            return ;
        }

        this->top++;
        this->arr[this->top] = data;
    }

    void pop(){

        if(this->top == -1){
            cout<<"stack underflow "<<endl;
        }

        cout<<"pop element: "<<this->arr[top]<<endl;
        this->top--;
    }

    int getTop(){
        
        if(this->top == -1){
            cout<<"stack underflow "<<endl;
            return INT_MIN;
        }

        return this->arr[this->top];
    }

    bool isEmpty(){
        if(this->top == -1){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){

    Stack s(5);

    s.push(1);
    s.push(2);
    s.push(3);

    cout<<"top element "<<s.getTop()<<endl;
    s.push(4);
    s.push(5);
    cout<<"top element "<<s.getTop()<<endl;
    s.push(6);

    s.pop();
    s.pop();
    cout<<"top element "<<s.getTop()<<endl;

    return 0;

}