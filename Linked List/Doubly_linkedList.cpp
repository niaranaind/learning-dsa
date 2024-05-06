#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* prev;
    Node* next;

    //constrauctor
    Node(int data){
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }
};

void print(Node* head){

    Node* temp=head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int getLength(Node* head){

    int len=0;
    Node* temp=head;

    while(temp != NULL){
        len++;
        temp=temp->next;
    }

    return len;
}

void insertAtHead(Node* &head,Node* &tail,int data){

    if(head == NULL){ // empty list case 

        Node* temp = new Node(data);
        head=temp;
        tail=temp;
    }
    else{
        Node* temp = new Node(data);

        temp->next= head;
        head->prev= temp;
        head=temp;

    }

    
}

void insertAtTail(Node* &head,Node* &tail,int data){

    if(tail == NULL){ //empty list case

        Node* temp = new Node(data);
        tail=temp;
        head=temp;
    }
    else{
        Node* temp= new Node(data);

        tail->next=temp;
        temp->prev =tail;
        tail=temp;
    }
 
}

void insertAtPosition(Node* &head,Node* &tail,int position ,int data){

    //inserting at start or first node
    if(position == 1){

        insertAtHead(head,tail,data);
        return;
    }

    Node* temp=head;
    int cnt=1;
    while(cnt < position -1){
        temp=temp->next;
        cnt++;
    }

    //insertion at tail or last node
    if(temp->next == NULL){

        insertAtTail(head,tail,data);
        return;
    }

    //inserting at middle
    Node* nodeToInsert= new Node(data);
    nodeToInsert->next=temp->next;
    temp->next->prev=nodeToInsert;
    temp->next=nodeToInsert;
    nodeToInsert->prev=temp;
}

int main(){

    Node* head = NULL;
    Node* tail = NULL;
    print(head);

    //cout<<getLength(head)<<endl;

    insertAtHead(head,tail,11);
    print(head);

    insertAtHead(head,tail,13);
    print(head);

    insertAtHead(head,tail,8);
    print(head);

    insertAtTail(head,tail,25);
    print(head);

    insertAtPosition(head,tail,2,100);
    print(head);

    insertAtPosition(head,tail,1,101);
    print(head);

    insertAtPosition(head,tail,7,102);
    print(head);

    return 0;

}