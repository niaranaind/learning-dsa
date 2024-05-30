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

    ~Node(){
        int value = this->data;
        while(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"Memory is deleted for the node with data: "<<value<<endl;
    }
};

void insertAtHead(Node* &head,int data){
    //creating a new node
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail,int data){

    //creating a new node
    Node* temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void insertAtPosition(Node* &head,Node* &tail,int position,int data){

    //insertion at first position 
    if(position == 1){

        insertAtHead(head,data);
        return;
    }

    Node* temp = head;
    int cnt = 1;
    while(cnt < position-1){
        temp = temp->next;
        cnt++;
    }

    //insertion at last node
    if(temp->next == NULL){
        insertAtTail(tail,data);
        return ;
    }

    //insert at middle position
    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deleteNode(Node* &head,Node* &tail,int position){

    //deleting first or start node
    if(position==1){
        Node* temp= head;
        head= head->next;

        //memory free
        temp->next=NULL;
        delete temp;

    }
    else{
        //deleting middle node or last node
        Node* prv=NULL;
        Node* curr=head;
        int cnt=1;

        while(cnt < position){
            prv=curr;
            curr=curr->next;
            cnt++;
        }

        prv->next=curr->next;
        if(prv->next == NULL){
            tail=prv;
        }
        curr->next=NULL;
        //memory frere

        delete curr;

    }
}

bool detectNode(Node* head){

    //list is empty
    if(head == NULL)
    return false;

    map<Node*,bool> visited;
    Node* temp = head;

    while(temp != NULL){

        //cycle is present
        if(visited[temp] == true){
            cout<<"Present on element: "<<temp->data<<endl;
            return true;
        }

        visited[temp] = true;
        temp = temp->next;
    }

    return false;
}

Node* floydDetectLoop(Node* head){

    //list is empty
    if(head == NULL){
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL){
        slow = slow->next; //moving slow by one step

        fast = fast->next;
        if(fast != NULL){
            fast = fast->next; //moving fast by two steps
        }

        if(slow == fast){ //cycle is present
        cout<<" present at: "<<slow->data<<endl;
            return slow;
        }
    }
    return NULL;
}

Node* getStartingNode(Node* head){

    //if list is empty
    if(head == NULL){
        return NULL;
    }

    //intersecting node where slow and fast pointer are meeting
    Node* intersectNode = floydDetectLoop(head);
    Node* slow = head;

    while(slow != intersectNode){
        slow = slow->next;
        intersectNode = intersectNode->next;
    }

    //out of the loop when slow = intersetnode

    return slow;
}

void removeLoop(Node* head){

    //if list is empty
    if(head == NULL){
        return;
    }

    Node* startOfloop = getStartingNode(head);
    Node* temp = startOfloop;

    while(temp->next != startOfloop){
        temp = temp->next;
    }

    //temp is pointing to previous node of startofloop
    temp->next = NULL;
}

void print(Node* &head){

    Node* temp= head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){

    Node* node1=new Node(10);
    Node* head=node1;
    Node* tail=node1;

    insertAtTail(tail,12);
    print(head);

    insertAtTail(tail,15);
    print(head);

    insertAtPosition(head,tail,1,22);
    print(head);

    tail->next = head->next;
    //print(head);
    if(detectNode(head)){
        cout<<" cycle is Present "<<endl;
    }
    else{
        cout<<" cycle is NOT Present "<<endl;
    }

    //detedting loop using floyd detection algorithm 
    if(floydDetectLoop(head) != NULL){
        cout<<"cycle is Present "<<endl;
    }
    else{
        cout<<"cycle is NOT Present "<<endl;
    }

    cout<<"begining node of cycle is: "<<getStartingNode(head)->data<<endl;

    removeLoop(head);
    print(head);

    cout<<"head data: "<<head->data<<endl;
    cout<<"tail data: "<<tail->data<<endl;

    return 0;
}