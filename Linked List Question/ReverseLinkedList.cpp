#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"Memory is free for Node with data: "<<value<<endl;
    }
};

void insertAthead(Node* &head,int data){

    //creating new node
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail,int data){

    //creating new Node
    Node* temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

//Given a singly linked list of integers. Your task is to return the head of the reversed linked list.

/*--------------Approach-1  ---------------------------------------------------------*/
Node* ReverseLinkedList(Node* &head){

    //empty list and single list case
    if(head == NULL || head->next == NULL){

        return head;
    }

    Node* prev = NULL;
    Node* curr = head;
    Node* forward = curr->next;
    
    while(curr != NULL){

        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;       
    }

    return prev;
}

/*--------------------Approach-2  -------------------------------------------------*/

void reverseLinkedList(Node* &head,Node* curr,Node* prev){

    //base case
    if(curr == NULL){
        head = prev;
        return;
    }

    Node* forward = curr->next;
    curr->next = prev;
    prev = curr;
    curr = forward;
    reverseLinkedList(head,curr,prev);
}

/*--------------------Approach-3  ---------------------------------------------*/

Node* Reverse(Node* head){

    //base case
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* chotahead = Reverse(head->next);

    head->next->next = head;
    head->next = NULL;

    return chotahead;
}

void print(Node* head){

    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){

    Node* node1 = new Node(10);
    Node* head = node1;

    insertAthead(head,11);
    insertAthead(head,12);
    insertAthead(head,13);
    insertAthead(head,14);

    print(head);

    //head = ReverseLinkedList(head);

    //print(head);

    Node* curr = head;
    Node* prev = NULL;

    reverseLinkedList(head,curr,prev);  //recursive solution

    print(head);

    head = Reverse(head);

    print(head);

    return 0;
}