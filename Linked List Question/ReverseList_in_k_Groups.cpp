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
        cout<<"Memory is free for the node with data: "<<value<<endl;
    }
};

void insertAtHead(Node* &head,int data){

    //creating new node
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail,int data){

    //creating new node
    Node* temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void insertAtPosition(Node* &head,Node* &tail,int position,int data){

    //insert at first or starting node
    if(position == 1){

        insertAtHead(head,data);
        return;
    }

    Node* temp = head;
    int cnt = 1;
    while(cnt < position -1){
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL){

        insertAtTail(tail,data);
        return;
    }

    //inserting at middle node
    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;

}

/*Problem statement
You are given a linked list of 'n' nodes and an integer 'k', where 'k' is less than or equal to 'n'.



Your task is to reverse the order of each group of 'k' consecutive nodes, if 'n' is not divisible by 'k',
 then the last group of nodes should remain unchanged.



For example, if the linked list is 1->2->3->4->5, and 'k' is 3, we have to reverse the first three elements,
 and leave the last two elements unchanged. Thus, the final linked list being 3->2->1->4->5.



Implement a function that performs this reversal, and returns the head of the modified linked list.*/

//solution code

int getLength(Node* head){

    Node* temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

Node*  kReverse(Node* head, int k){

    //base case
    if(head == NULL){
        return NULL;
    }

    int len = getLength(head);
    if(k>len){
        return head;
    }

    //step-1 solve first case using iteration
    Node* prev = NULL;
    Node* next = NULL;
    Node *curr = head;
    int count = 0;
    
    while(curr != NULL && count < k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    //step-2 recursive call will return the head of reversed list and attach it to first section
    if(next != NULL){
        head->next = kReverse(next,k);
    }

    return prev;
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

    Node* node1 = new Node(8);
    Node* head = node1;
    Node* tail = node1;

    print(head);

    insertAtPosition(head,tail,1,3);
    print(head);

    insertAtPosition(head,tail,2,7);
    print(head);

    insertAtTail(tail,11);
    insertAtTail(tail,17);
    insertAtTail(tail,2);
    print(head); 


    head = kReverse(head,2);
    cout<<"Reverse list in k groups: "<<endl;

    print(head);   



    return 0;
}