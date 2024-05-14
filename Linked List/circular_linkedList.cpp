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

    //list is empty
    if(tail == NULL){
        Node* newNode = new Node(data);
        tail = newNode;
        newNode->next = newNode;
    }
    else{
        //non-empty list
        //Assuming that the element is present in the list
        Node *curr = tail;
        while(curr->data != element){
            curr=curr->next;
        }
        //element is found-> curr representing element wala node
        Node* temp = new Node(data);
        temp->next = curr->next;
        curr->next = temp;

    }
}

void deleteNode(Node* &tail,int value){
    //empty list
    if(tail == NULL){

        cout<<"list is empty , please check again "<<endl;
        return ;
    }
    else{
        //non-empty list
        //assuming that value is present in the list
        Node* pre = tail;
        Node* curr = pre->next;
        while(curr->data != value){
            pre = curr;
            curr = curr->next;
        }

        pre->next = curr->next;

        //ONLY  ONE node is present
        if(curr == pre){
            tail = NULL;
        }

        //more then or equal to 2 node is present
        else if(tail == curr){
            tail=pre;
        }

        curr->next = NULL;

        delete curr;
    }
}

void print(Node* &tail){

    Node* temp = tail;

    //empty list case
    if(temp == NULL){
        cout<<"list is empty "<<endl;
        return;
    }

    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp != tail);

    cout<<endl;
}


int main(){

    Node* tail = NULL;

    insertNode(tail,5,3);
    print(tail);


    deleteNode(tail,3);
    print(tail);

    return 0;
}