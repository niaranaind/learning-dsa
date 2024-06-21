#include<iostream>
using namespace std;

class Deque{

    int *arr;
    int size;
    int front;
    int rear;

    public:
    //constructor
    Deque(int n){
        //initialize deque data structor
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    //push front operation
    bool pushFront(int data){
        //check whether queue is full or not
        if((front == 0 && rear == size -1) || (front != 0 && rear == (front-1)%(size-1))){
            cout<<"queue is full "<<endl;
            return false;
        }
        else if(front == -1){ //single element in present in queue
            front = 0;
            rear = 0;
            arr[front] = data;
        }
        else if (front == 0 && rear != size - 1){ //to main cyclic nature
            front = size - 1;
            arr[front] = data;
        }
        else{ //normal case
            front--;
            arr[front] = data;
        }
        return true;
    }

    //push rear - > push data in the back of the deque.
    bool pushRear(int data){
        //check whether array is full or not
        if((front == 0 && rear == size -1) || (front != 0 && rear == (front-1)%(size-1))){
            cout<<"queue is Full "<<endl;
            return false;
        }
        else if(front == -1){ //single element in queue
            front = 0;
            rear = 0;
        }
        else if(front != 0 && rear == size-1){ // to maintain cyclic nature 
            rear = 0;
        }
        else{ // normal case
            rear++;
        }
        arr[rear] = data;
        return true;
    }

    //pop element from the front of the deque
    int popFront(){
        //check whether queue is empty or not
        if(front == -1){
            cout<<" queue is empty "<<endl;
            return -1;
        }

        int ans = arr[front];
        arr[front] = -1;

        if(front == rear){ //single element is present
            front = -1;
            rear = -1;
        }
        else if(front == size -1 ){ //to maintain cyclic nature
            front = 0;
        }
        else{//normal case
            front++;
        }
        return ans;
    }

    //pop an element from the back of the queue 
    int popRear(){
        //check whether queue is empty or not
        if(front == -1){
            cout<<"queue is empty "<<endl;
            return -1;
        }
        int ans = arr[rear];
        arr[rear] = -1;

        if(front == rear){ // single element is present 
            front = -1;
            rear = -1;
        }
        else if(rear == 0){//
            rear = size -1;
        }
        else{
            rear--;
        }
        return ans;
    }

    //returning the front element of deque
    int getFornt(){
        if(isEmpty()){
            return -1;
        }
        return arr[front];
    }

    //returning the last element of deque
    int getRear(){
        if(isEmpty()){
            return -1;
        }
        return arr[rear];
    }

    //return true if the deque is empty .otherwise return false
    bool isEmpty(){

        if(front == -1){
            return true;
        }
        else{
            return false;
        }
    }

    //return trur if the deque is full . otherwise return false
    bool isFull(){

        if((front == 0 && rear == size -1) || (front != 0 && rear == (front-1)%(size-1))){
            return true;
        }
        else{
            return false;
        }
    }
};