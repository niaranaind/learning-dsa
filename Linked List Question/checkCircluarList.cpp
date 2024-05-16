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
        cout<<"Memory is free for node with data: "<<value<<endl;
    }
};

void insertNode(Node* &tail,int element,int data){

    //empty list
    if(tail == NULL){
        //creating new node
        Node* newNode = new Node(data);
        tail = newNode;
        newNode->next = newNode;
    }
    else{
        //list is non-empty
        //assuming data is present in the list
        Node* curr = tail;
        while(curr->data != element){
            curr = curr->next;
        }

        //curr is pointing to element wala node
        Node* temp = new Node(data);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void deleteNode(Node* &tail,int value){
    //list is empty
    if(tail == NULL){
        cout<<"List is empty please check again !!"<<endl;
        return;
    }
    else{
        //when list is non-empty 
        //assuming value is present in the list 
        Node* prev = tail;
        Node* curr = prev->next;

        while(curr->data != value){
            prev = curr;
            curr = curr->next;
        }

        //curr is pointing value wala node
        prev->next = curr->next;

        if(prev == curr) //single node case
        tail=NULL;

        if(tail == curr){  //when deleting node which is pointed by tail
            tail = prev;
        }

        curr->next = NULL;

        delete curr;
    }
}

bool isCircularList(Node* head){

    //when list is empty
    if(head == NULL)
    return true;

    Node* temp = head->next;
    while( temp != NULL && temp != head){
        temp = temp->next;
    }

    if(temp == NULL){ //case of linear linked list
        return false;
    }

    if(temp == head){ //case of circluar linked list
        return true;
    }
}

void print(Node* tail){

    if(tail == NULL){
        cout<<" list is Empty "<<endl;
        return;
    }

    Node* temp = tail;
    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp != tail);
    cout<<endl;
}

int main(){

    Node* tail = NULL;
    insertNode(tail,3,3);
    print(tail);

    insertNode(tail,3,5);
    print(tail);

    if(isCircularList(tail)){

        cout<<"linked list is circular in nature "<<endl;
    }
    else{
        cout<<"Linked list is not circular in bature "<<endl;
    }

    return 0;
}
