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

Node* solve(Node* first,Node* second){

    //if only one element is present in the first list
    if(first->next == NULL){
        first->next = second;
        return first;
    }

    Node* curr1 = first;
    Node* next1 = curr1->next;
    Node* curr2 = second;
    Node* next2 = curr2->next;

    while(next1 != NULL && curr2 != NULL){

        if((curr2->data >= curr1->data) && (curr2->data <= next1->data)){
            //adding node in the first list
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;

            //update pointer
            curr1 = curr2;
            curr2 = next2;
        }
        else{

            //updating pointer 
            curr1 = next1;
            next1 = next1->next;
            if(next1 == NULL){
                curr1->next = curr2;
                return first;
            }
        }
    }
    return first;
}

Node* sortTwoLists(Node* &first,Node* &second){
    //if first list is empty
    if(first == NULL){
        return second;
    }

    //if second list is empty
    if(second == NULL){
        return first;
    }

    //identify which list should be first list
    if(first->data <= second->data ){
        return solve(first,second);
    }
    else{
        return solve(second,first);
    }

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

    Node* first = new Node(1);
    Node* firstHead = first;
    Node* firstTail = first;
    insertAtTail(firstTail,4);
    insertAtTail(firstTail,5);
    
    print(firstHead);
    
    Node* second = new Node(2);
    Node* secondHead = second;
    Node* secondTail = second;
    insertAtTail(secondTail,3);
    insertAtTail(secondTail,5);
    
    print(secondHead);

    Node* head = sortTwoLists(firstHead,secondHead);
    print(head);

    return 0;
}