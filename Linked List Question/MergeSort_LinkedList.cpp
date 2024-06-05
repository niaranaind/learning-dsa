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

    //creating new Node
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

void insertAtPosition(Node* &head,Node* &tail,int position,int data){

    if(position == 1){ //insertion at head 
        insertAtHead(head,data);
        return;
    }

    Node* temp = head;
    int cnt = 1;
    while(cnt < position-1){
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL){ //insertion at tail

        insertAtTail(tail,data);
        return;
    }

    //inserting node at middle range
    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deleteNode(Node* &head,Node* &tail,int position){

    if(position == 1){

        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else{
        //deleting last or middle node
        Node* prev = NULL;
        Node* curr = head;
        int cnt = 1;
        while(cnt < position){

            prev = curr;
            curr = curr->next;
            cnt++;
        }

        prev->next = curr->next;
        if(prev->next == NULL){
            tail = prev;
        }

        curr->next = NULL;
        delete curr;
    }
}

void print(Node* head){

    if(head == NULL){
        cout<<"List is Empty please try Again !!!"<<endl;
        return;
    }

    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

class solution{

    private:
    Node* findMid(Node* head){

        Node* slow = head;
        Node* fast = head->next;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    Node* merge(Node* &left,Node* &right){

        if(left == NULL){ //left part is empty
            return right;
        }

        if(right == NULL){ //right part is empty
            return left;
        }

        //merge two sorted linked list
        Node* ans = new Node(-1);
        Node* temp = ans;
        while(left != NULL && right != NULL){

            if(left->data < right->data){
                
                temp->next = left;
                temp = left;
                left = left->next;
            }
            else{
                temp->next = right;
                temp = right;
                right = right->next;
            }
        }

        //remaining part of left list
        while(left != NULL){
            temp->next = left;
            temp = left;
            left = left->next;
        }

        //remaining part of right list
        while(right != NULL){
            temp->next = right;
            temp = right;
            right = right->next;
        }

        ans = ans->next;
        return ans;
    }

    public:
    Node* mergeSort(Node* &head){

        //base case
        if(head == NULL || head->next == NULL){
            return head;
        }

        //step-1  find mid 
        Node* mid = findMid(head);

        //step-2  break link list into two part or create left and rigth part linked list
        Node* left = head;
        Node* right = mid->next;
        mid->next = NULL;

        //step-3  sort left and right part using recursion
        left = mergeSort(left);
        right = mergeSort(right);

        //step-4 merge two sorted linked list
        Node* result = merge(left,right);

        return result;
    }
};

int main(){

    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail,4);
    insertAtTail(tail,5);
    insertAtTail(tail,2);
    insertAtTail(tail,-1);
    print(head);

    solution sr;
    head = sr.mergeSort(head);

    print(head);

    return 0;
}