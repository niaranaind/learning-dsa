#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node *next;

    //constractur
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

void insertAtHead(Node* &head,int data){

        //create new node
        Node *temp= new Node(data);
        temp->next=head;
        head=temp;
}

void insertAtTail(Node* &tail,int data){

    //create new node
    Node* temp= new Node(data);
    tail->next=temp;
    tail=temp;

}

void insertAtPosition(Node* &head,Node* &tail,int position,int data){
    
    //inserting at First Position
    if(position==1){

        insertAtHead(head,data);
        return;
    }
    Node* temp=head;
    int cnt=1;

    while(cnt < position-1){
        temp=temp->next;
        cnt++;
    }

    //inserting at Last Position
    if(temp->next == NULL){

        insertAtTail(tail,data);
        return;
    }

    Node* NodeToInsert = new Node(data);

    NodeToInsert->next=temp->next;
    temp->next=NodeToInsert;
}

void print(Node* &head){

    Node* temp=head;

    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){

    //creating node odject dynamically
    Node *node1= new Node(10);

    cout<<node1->data<<endl;
    cout<<node1->next<<endl;

    Node *head=node1;
    Node *tail=node1;
    
    insertAtTail(tail,12);
    print(head);

    insertAtTail(tail,15);
    print(head);

    insertAtPosition(head,tail,4,22);
    print(head);

    return 0;
}