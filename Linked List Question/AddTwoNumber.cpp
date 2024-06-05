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
        cout<<"Memory is deleted for node with data: "<<value<<endl;
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

    //insertion at head position
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

    //insertion at tail position
    if(temp->next == NULL){
        insertAtTail(tail,data);
        return;
    }

    //inserting a middle position
    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deleteNode(Node* &head,Node* &tail,int position){

    //deleting head or first node
    if(position == 1){

        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else{
        //deleting mid node or last node
        Node* prev = NULL;
        Node* curr = head;
        int cnt = 1;
        while(cnt < position ){
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        //deleting curr wala node
        prev->next = curr->next;
        if(prev->next = NULL){ //curr is pointing to last node
            tail = prev;
        }

        curr->next = NULL;
        delete curr;
    }
}

/*-------------------------adding two number represented by linked list -----------------*/

Node* reverse(Node* head){

    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void insertattail(Node* &head,Node* &tail,int val){

    //creating node
    Node* temp = new Node(val);
    if(head == NULL){ //list is empty
        head = temp;
        tail = temp;
        return;
    }
    else{
        //when list is non-empty 
        tail->next = temp;
        tail = temp;
    }
}

Node* add(Node* first,Node* second){

    int carry = 0;
    Node* ansHead = NULL;
    Node* ansTail = NULL;
    while(first != NULL && second != NULL){
        
        int sum = carry + first->data + second->data;
        int digit = sum % 10;
        //creating node and inserting digit in that node
        insertattail(ansHead,ansTail,digit);
        carry = sum/10;
        first = first->next;
        second = second->next; 
    }

    //when first list is remaining 
    while(first != NULL){
        int sum = carry + first->data;
        int digit = sum%10;
        insertattail(ansHead,ansTail,digit);
        carry = sum/10;
        first = first->next;
    }

    //when second list is remaining
    while(second != NULL){
        int sum = carry + second->data;
        int digit = sum%10;
        insertattail(ansHead,ansTail,digit);
        carry = sum/10;
        second = second->next;
    }

    //when carry is not 0
    while(carry != 0){
        int sum = carry;
        int digit = sum%10;
        insertattail(ansHead,ansTail,digit);
        carry = sum/10;
    }

    return ansHead;
}

Node* addTwoLists(Node* first,Node* second){

    //step-1 reverse the input linked list
    first = reverse(first);
    second = reverse(second);

    //step-2 add two linked list
    Node* ans = add(first,second);

    //reverse the ans list
    ans = reverse(ans);

    return ans;
}

void print(Node* head){

    //list is empty
    if(head == NULL){
        cout<<"List is Empty Please check Again!!"<<endl;
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

    // test case are written here
    Node* first = new Node(4);
    Node* head = first;
    Node* tail = first;
    insertAtTail(tail,5);
    print(head);

    Node* second = new Node(3);
    Node* head1 = second;
    Node* tail1 = second;
    insertAtTail(tail1,4);
    insertAtTail(tail1,5);
    print(head1);

    Node* ans = addTwoLists(head,head1);
    print(ans);

    return 0;
}