#include<iostream>
#include<map>
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
        cout<<"Memory is deleted for node with data: "<<value<<endl;
    }
};

void insertAtHead(Node* &head,int data){

    //create a new node
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

    //insertion at head
    if(position == 1){

        insertAtHead(head,data);
        return;
    }

    Node* curr = head;
    int cnt =1;
    while(cnt < position -1){
        curr = curr->next;
        cnt++;
    }

    if(curr->next == NULL){

        insertAtTail(tail,data);
        return;
    }

    //insertion at middle of linked list
    Node* temp = new Node(data);
    temp->next = curr->next;
    curr->next = temp;
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
        while(cnt < position){
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        prev->next = curr->next;
        if(prev->next == NULL){ //curr is pointing to last node
            tail = prev;
        }

        curr->next = NULL;
        delete curr;
    }
}

Node* sortList(Node* head){
    //count for 0,1,2
    int countzero = 0;
    int countone = 0;
    int counttwo = 0;

    Node* temp = head;
    while(temp != NULL){
        
        if(temp->data == 0){
            countzero++;
        }
        else if(temp->data == 1){
            countone++;
        }
        else if(temp->data == 2){
            counttwo++;
        }
        temp = temp->next;
    }

    temp = head;
    while(temp != NULL){

        if(countzero != 0){
            temp->data = 0;
            countzero--;
        }
        else if(countone != 0){
            temp->data = 1;
            countone--;
        }
        else if(counttwo != 0){
            temp->data = 2;
            counttwo--;
        }

        temp = temp->next;
    }
    return head;
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

    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail,0);
    insertAtTail(tail,2);
    insertAtTail(tail,1);
    insertAtTail(tail,2);
    print(head);

    head = sortList(head);
    print(head);

    return 0;
}