#include<iostream>
#include<limits.h>
using namespace std;

class Node{

    public:
    int data;
    Node* next;

    //contructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class Stack{
    //properties
    Node* head;
    int size;
    int currSize;

    public:
    Stack(int size){
        this->size = size;
        this->currSize = 0;
        head = NULL;
    }

    //stack operation
    bool isEmpty(){
        return this->head == NULL;
    }

    bool isFull(){
        return this->currSize == this->size;
    }

    void push(int data){

        if(this->currSize == this->size){
            cout<<"stack overflow "<<endl;
            return;
        }

        Node* newNode = new Node(data);
        newNode->next = this->head; //insertion at head
        this->head = newNode;
        this->currSize++;
    }

    int pop(){

        if(this->head == NULL){
            cout<<"stack underflow "<<endl;
            return INT_MIN;
        }

        Node* newHead = this->head->next;
        this->head->next = NULL;
        Node* toRemove = this->head;
        int result = toRemove->data;
        delete toRemove;
        this->head = newHead;
        this->currSize--;
        return result;
    }

    int getTop(){

        if(head == NULL){
            cout<<"stack underflow "<<endl;
            return INT_MIN;
        }

        return this->head->data;
    }

    int getSize(){
        return currSize;
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

    cout<<"pop element: "<<s.pop()<<endl;
    cout<<"pop element: "<<s.pop()<<endl;
    cout<<"top element "<<s.getTop()<<endl;

    return 0;

}