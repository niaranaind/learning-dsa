#include<iostream>
#include<vector>
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

    //destructor
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

/*-----------------------Approch - 1  --------------------------------------------------*/
bool checkPalindrome(vector<int> &arr){

    int s = 0;
    int e = arr.size()-1;
    while(s<=e){
        if(arr[s] != arr[e]){
            return false;
        }
        s++;
        e--;
    }
    return true;
}

bool isPalindrome(Node* head){

    //creating array or vector
    vector<int> arr;
    Node* temp = head;
    while(temp != NULL){//copying element in vector

        arr.push_back(temp->data);
        temp = temp->next;
    }

    return checkPalindrome(arr);

}

/*-----------------------Approch 2 -------------------------------------*/

Node* getMid(Node* head){

    Node* slow = head;
    Node* fast = head->next;

    while((fast != NULL) && (fast->next != NULL)){

        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Node* reverse(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool isPalindromeLinkedList(Node* head){

    //when list is empty or only one element is present
    if((head == NULL) || (head->next == NULL)){
        return true;
    }

    //step-1  find middle node
    Node* middle = getMid(head);

    //step-2  reverse the list after middle node
    Node* temp = middle->next;
    middle->next = reverse(temp);

    //step-3  compare both parts
    Node* head1 = head;
    Node* head2 = middle->next;
    while(head2 != NULL){
        
        if(head1->data != head2->data){
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    //step-4 repeat step-2 to make the linked list normal (optional step)
    temp = middle->next;
    middle->next = reverse(temp);

    return true;
}

void print(Node* head){

    if(head == NULL){
        cout<<"List is Empty Please try again!!.."<<endl;
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

    insertAtTail(tail,2);
    insertAtTail(tail,1);
    print(head);

    if(isPalindromeLinkedList(head)){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False "<<endl;
    }

    return 0;
}