#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* next;

    //constructor to set value and next pointer
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

void insertAtHead(Node* &head,int data){

    //create a new node
    Node* temp= new Node(data);
    temp->next=head;
    head=temp;
}

void insertAtTail(Node* &tail,int data){

    //create a new node
    Node* temp= new Node(data);

    tail->next=temp;
    tail=temp;
}

void insertAtPosition(Node* &head,Node* &tail,int position,int data){

    //insertion at first position
    if(position==1){

        insertAtHead(head,data);
        return;
    }

    Node* temp=head;
    int cnt=1;
    // traverse to n-1 position
    while(cnt < position-1){

        temp=temp->next;
        cnt++;
    }

    //insertion at last position
    if(temp->next == NULL){

        insertAtTail(tail,data);
        return;
    }

    //creating insertion node
    Node* NodeToInsert= new Node(data);

    NodeToInsert->next= temp->next;
    temp->next= NodeToInsert;

}

void print(Node* &head){

    Node* temp= head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){

    Node* node1=new Node(10);
    Node* head=node1;
    Node* tail=node1;

    insertAtTail(tail,12);
    print(head);

    insertAtTail(tail,15);
    print(head);

    insertAtPosition(head,tail,1,22);
    print(head);

    return 0;
}