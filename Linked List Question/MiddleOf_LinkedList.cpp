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

/*-----------------Approach -1 ------------------------------*/
int getLength(Node* head){

    int cnt = 0;
    Node* temp = head;
    while(temp != NULL){
        temp = temp->next;
        cnt++;
    }

    return cnt;
}

Node *findMiddle(Node *head) {
    // Write your code here
    int len = getLength(head);
    int cnt = 0;
    Node* temp = head;
    while(cnt < len/2){
        temp = temp->next;
        cnt++;
    }
    return temp;
}

/*---------------------Approach -2 ------------------------*/

Node* getMiddle(Node* head){

    //edge case
    if(head == NULL || head->next == NULL){
        return head;
    }

    if(head->next->next == NULL){
        return head->next;
    }

    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL){

        fast = fast->next;
        if(fast!= NULL){
            fast = fast->next;
        }

        slow = slow->next;
    }
    return slow;
}

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

    //inserting at first or stating node
    if(position == 1){

        insertAtHead(head,data);
        return;
    }

    Node* temp = head;
    int cnt =1;

    while(cnt < position -1){
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL){

        insertAtTail(tail,data);
        return;
    }

    //insertion at middle 
    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
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

    Node* node1 = new Node(2);
    Node* head = node1;
    Node* tail = node1;

    insertAtHead(head,1);
    print(head);

    insertAtTail(tail,4);
    print(head);

    insertAtPosition(head,tail,3,3);
    print(head);

    insertAtTail(tail,5);
    print(head);


    cout<<"length of the linked list is: "<<getLength(head)<<endl;

    Node* middleNode = findMiddle(head);

    cout<<"middle node data: "<<middleNode->data<<endl;

    middleNode = getMiddle(head);

    cout<<"middle node data: "<<middleNode->data<<endl;

    return 0;

}