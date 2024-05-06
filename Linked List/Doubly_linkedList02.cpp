#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* prev;
    Node* next;

    //constructor for taking values and address
    Node(int data){

        this->data = data;
        this->prev = NULL;
        this->next = NULL;

    }

    //destructor
    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"memory is free for the node with data: "<<value<<endl;
    }
};

int getLength(Node* head){

    int len = 0;
    Node* temp = head;
    while(temp!= NULL){

        len++;
        temp = temp->next;
    }

    return len;
}

void print(Node* head){

    Node* temp = head;
    while(temp != NULL){

        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

//insertion at head or start node
void insertAtHead(Node* &head,Node* &tail,int data){

    if(head == NULL){

        Node* temp = new Node(data);
        head=temp;
        tail=temp;
    }
    else{
        Node* temp = new Node(data);

        temp->next = head;
        head->prev=temp;
        head=temp;
    }
  
}

//insertion at tail or end node
void insertAtTail(Node* &head,Node* &tail,int data){

    if(tail == NULL){

        Node* temp = new Node(data);
        tail=temp;
        head=temp;
    }
    else{
        Node* temp = new Node(data);

        tail->next = temp;
        temp->prev = tail;
        tail=temp;
    }

}

//insertion at any position

void insertAtPosition(Node* &head,Node* &tail,int position,int data){

    //insertion at start or head node
    if(position == 1){

        insertAtHead(head,tail,data);
        return ;
    }

    Node* temp=head;
    int cnt=1;
    while(cnt< position -1){

        temp=temp->next;
        cnt++;
    }

    //insertion at end or tail node
    if(temp->next == NULL){

        insertAtTail(head,tail,data);
        return;
    }

    //insertion at middle
    Node* nodeToInsert = new Node(data);

    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    nodeToInsert->prev = temp;
    temp->next = nodeToInsert;

}

void deleteNode(Node* &head,Node* &tail,int position){

    //deleting start or first node
    if(position == 1){

        Node* temp= head;
        temp->next->prev = NULL;
        head=temp->next;
        temp->next = NULL;

        delete temp;
    }
    else{
        
        Node* pre= NULL;
        Node* curr = head;
        int cnt=1;
        while(cnt < position){
            pre=curr;
            curr = curr->next;
            cnt++;
        }

        cout<<pre->data<<" "<<curr->data<<endl;

        //deleting middle or last node
        curr->prev = NULL;
        pre->next = curr->next;
         
         if(curr->next != NULL)
        curr->next->prev = pre;

        if(pre->next == NULL){
            tail=pre;
        }
        
        curr->next = NULL;

        delete curr;
    }
}

int main(){

    Node* head = NULL;
    Node* tail = NULL;

    print(head);

    insertAtHead(head,tail,11);
    print(head);

    insertAtHead(head,tail,13);
    print(head);

    insertAtHead(head,tail,8);
    print(head);

    insertAtTail(head,tail,25);
    print(head);

    insertAtPosition(head,tail,2,100);
    print(head);

    insertAtPosition(head,tail,1,101);
    print(head);

    insertAtPosition(head,tail,7,102);
    print(head);

    deleteNode(head,tail,7);
    print(head);

    cout<<"head data: "<<head->data<<"  tail data: "<<tail->data<<endl;

    return 0;
}