#include<iostream>
#include<queue>
using namespace std;

int main(){

    queue<int> q;

    q.push(12);
    q.push(11);
    q.push(13);

    cout<<"front of queue is: "<<q.front()<<endl;

    cout<<"size of queue is : "<<q.size()<<endl;

    q.pop();
    q.pop();
    cout<<"size of queue is : "<<q.size()<<endl;

    cout<<"front of queue is : "<<q.front()<<endl;

    if(q.empty()){
        cout<<"queue is empty "<<endl;
    }
    else{
        cout<<"queue is NOT empty "<<endl;
    }

    return 0;   
}