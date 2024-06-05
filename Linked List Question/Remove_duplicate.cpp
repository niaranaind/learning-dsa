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

Node* uniqueSortedList(Node* head){

    //if list is empty
    if(head == NULL){
        return NULL;
    }

    Node* curr = head;

    while(curr != NULL){

        if((curr->next != NULL) && (curr->data == curr->next->data)){

            Node* next_next = curr->next->next;
            Node* nodeToDelete = curr->next;
            nodeToDelete->next = NULL;
            delete nodeToDelete;
            curr->next = next_next;
        }
        else{
            //not equal to condition
            curr = curr->next;
        }
    }
    return head;
}

Node* uniqueUnsortedList(Node* &head){

    if(head == NULL)
    return NULL;

    Node* temp = head;

    while(temp != NULL){
        Node* prev = temp;
        Node* curr = prev->next;

        while(curr != NULL){

            if(temp->data == curr->data){
                //delete curr wala node
                Node* nodeToDelete = curr;
                prev->next = curr->next;
                curr = prev->next;
                nodeToDelete->next = NULL;
                delete nodeToDelete;
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }
        temp = temp->next;
    }
    return head;
}

Node* uniqueUnsortedListMap(Node* head){

    if(head == NULL)
    return NULL;

    map<int,bool> visited;

    Node* prev = NULL;
    Node* curr = head;

    while(curr != NULL){

        if(visited[curr->data] == true){
            //delete curr wala node
            Node* nodeToDelete = curr;
            prev->next = curr->next;
            curr = curr->next;
            nodeToDelete->next = NULL;
            delete nodeToDelete;
            continue;
        }

        visited[curr->data] = true;
        prev = curr;
        curr = curr->next;
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

    insertAtTail(tail,2);
    insertAtTail(tail,2);
    insertAtTail(tail,3);
    insertAtTail(tail,3);
    insertAtTail(tail,3);
    insertAtTail(tail,3);
    insertAtTail(tail,3);
    insertAtTail(tail,4);

    print(head);

    head = uniqueSortedList(head);
    print(head);

    Node* node2 = new Node(4);
    Node* head2 = node2;
    Node* tail2 = node2;

    insertAtTail(tail2,2);
    insertAtTail(tail2,5);
    insertAtTail(tail2,4);
    insertAtTail(tail2,2);
    insertAtTail(tail2,2);
    insertAtTail(tail2,1);
    print(head2);

    // head2 = uniqueUnsortedList(head2);
    // print(head2);

    head2 = uniqueUnsortedListMap(head2);
    print(head2);

 

    return 0;
}