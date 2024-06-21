#include<iostream>
using namespace std;

class Queue{

    int *arr;
    int size;
    int front;
    int rear;

    public:
    //constructor 
    Queue(){
        size  = 10001;
        arr = new int[size];
        front  = 0;
        rear = 0;
    }

    //queue operations
    bool isEmpty(){
        if(front == rear){
            return true;
        }
        else{
            return false;
        }
    }

    //size of queue
    int getsize(){
        return rear - front;
    }

    //push or insert operation in queue is known as enqueue operation
    void enqueue(int data){
        //check queue is full or not
        if(rear == size){
            cout<<"queue is FULL "<<endl;
            return;
        }
        else{
            arr[rear] = data;
            rear++;
        }
    }

    //pop or remove opearation in queue is known as dequeue operation
    int dequeue(){
        //check if queue is empty or not
        if(front == rear){
            cout<<"queue is empty "<<endl;
            return -1;
        }
        else{
            int ans = arr[front];
            arr[front] = -1;
            front++;
            if(front == rear){
                front = 0;
                rear = 0;
            }
            return ans;
        }
    }

    //front operation in queue
    int frontElement(){
        //check whether queue is empty or not
        if(front == rear){
            return -1;
        }
        else{
            return arr[front];
        }

    }
};

int main(){

    Queue q;

    q.enqueue(12);
    q.enqueue(11);
    q.enqueue(13);

    cout<<"front of queue is: "<<q.frontElement()<<endl;

    cout<<"size of queue is : "<<q.getsize()<<endl;

    q.dequeue();
    q.dequeue();
    cout<<"size of queue is : "<<q.getsize()<<endl;

    cout<<"front of queue is : "<<q.frontElement()<<endl;

    if(q.isEmpty()){
        cout<<"queue is empty "<<endl;
    }
    else{
        cout<<"queue is NOT empty "<<endl;
    }

    return 0;   
}