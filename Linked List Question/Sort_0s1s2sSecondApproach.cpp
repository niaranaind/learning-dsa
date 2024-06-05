#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* next;

    //constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    //distructor
    ~Node(){
        int value = this->data;
        while(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"Memory is deleted for the Node with data: "<<value<<endl;
    }
};

void insertAtHead(Node* &head,int data){

    //creating new node to insert
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

    //insertion at head position
    if(position == 1){

        insertAtHead(head,data);
        return;
    }

    Node* temp = head;
    int cnt =1;
    while(cnt < position-1){
        temp = temp->next;
        cnt++;
    }
    //insertion at tail position
    if(temp->next == NULL){
        insertAtTail(tail,data);
        return;
    }
    //insertion at middle position
    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deleteNode(Node* &head,Node* &tail,int position){
    //deleting first node
    if(position == 1){

        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else{
        //deleting middle or last node
        Node* prev = NULL;
        Node* curr = head;
        int cnt = 1;
        while(cnt < position ){
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        prev->next = curr->next;
        if(prev->next == NULL){//deleting last node
            tail = prev;
        }

        curr->next = NULL;
        delete curr;
    }
}

//sorting 0s,1s,2s in linked list -> second approach
void insertattail(Node* &tail,Node* curr){

    tail->next = curr;
    tail = curr;
}

Node* sortlinkedList(Node* head){

    //creating dummy nodes
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* curr = head;
    while(curr != NULL){//creating seperate list for 0s,1s,2s
        int value = curr->data;
        if(value == 0){
            insertattail(zeroTail,curr);
        }
        else if(value == 1){
            insertattail(oneTail,curr);
        }
        else if(value == 2){
            insertattail(twoTail,curr);
        }
        curr = curr->next;
    }

    //merging 3 nodes(0s, 1s, 2s)
    if(oneHead->next != NULL){//list is not empty
        zeroTail->next = oneHead->next;
    }
    else{//list is empty
        zeroTail->next = twoHead->next;
    }
    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    //set up head 
    head = zeroHead->next;
    //delete dummy nodes
    zeroHead->next = NULL;
    delete zeroHead;
    oneHead->next = NULL;
    delete oneHead;
    twoHead->next = NULL;
    delete twoHead;

    return head;
}

void print(Node* head){

    if(head == NULL){
        cout<<"list is empty Please try again!!!"<<endl;
        return;
    }

    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){

    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail,0);
    insertAtTail(tail,2);
    insertAtTail(tail,1);
    insertAtTail(tail,2);
    print(head);

    head = sortlinkedList(head);
    print(head);

    return 0;
}