#include<iostream>
using namespace std;

class CircularQueue{

    int *arr;
    int front;
    int rear;
    int size;

    public:
    //constructor
    CircularQueue(int n){
        //initialize circular queue data structure
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    //front position
    int frontIndex(){
        return front;
    }

    //rear position
    int rearIndex(){
        return rear;
    }

    //push or insertion operation for circular queue
    bool enqueue(int data){
        //check whether queue is full for not
        if((front == 0 && rear == size -1) || (rear == (front - 1)%(size - 1))){
            cout<<"queue is full "<<endl;
            return false;
        }
        else if(front == -1 ){ // inserting first element
            front = 0;
            rear = 0;
            arr[rear] = data;
        }
        else if((front != 0) && (rear == size-1)){ //to main cyclic nature
            rear = 0;
            arr[rear] = data;
        }
        else{ //normal case
            rear++;
            arr[rear] = data;
        }
        return true;
    }

    //pop or remove operation for circular queue
    int dequeue(){

        //check whether queue is empty or not
        if(front == -1){
            cout<<"queue is empty "<<endl;
            return -1;
        }

        int ans = arr[front];
        arr[front] = -1;
        if(front == rear){ // when single element is present in queue
            front = -1;
            rear = -1;
        }
        else if(front == size - 1){ //to maintain cyclic nature 
            front = 0;
        }
        else{ //normal case
            front++;
        }
    }

    void print(){
        for(int i=0 ; i<size ; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){

    CircularQueue c(6);

    c.enqueue(10);
    c.enqueue(11);
    c.enqueue(12);

    c.print();
    cout<<" front index "<<c.frontIndex()<<"  rear index "<<c.rearIndex()<<endl;

    c.enqueue(13);
    c.enqueue(14);
    c.enqueue(15);

    c.print();
    cout<<" front index "<<c.frontIndex()<<"  rear index "<<c.rearIndex()<<endl;

    c.dequeue();
    c.dequeue();
    c.print();
    cout<<" front index "<<c.frontIndex()<<"  rear index "<<c.rearIndex()<<endl;

    c.dequeue();
    c.enqueue(16);
    c.print();
    cout<<" front index "<<c.frontIndex()<<"  rear index "<<c.rearIndex()<<endl;
    




    return 0;

}