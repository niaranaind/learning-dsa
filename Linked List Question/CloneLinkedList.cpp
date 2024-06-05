#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;


class Node{

    public:
    int data;
    Node* next;
    Node* random;

    //constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }
};

class solution{

    private:
    void insertAtTail(Node* &head,Node* &tail,int data){

        //creating new node
        Node* newNode = new Node(data);
        if(head == NULL){// when list is Empty
            head = newNode;
            tail = newNode;
            return;
        }
        else{
            //when list is non Empty
            tail->next = newNode;
            tail = newNode;
        }
    }

    public:
    Node* copyList(Node* head){

        //step-1 create a clone list
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        Node* temp = head;

        while(temp != NULL){
            insertAtTail(cloneHead,cloneTail,temp->data);
            temp = temp->next;
        }

        //step-2 create a map 
        unordered_map<Node*,Node*> oldToNew;
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        while(originalNode != NULL && cloneNode != NULL){
            oldToNew[originalNode] = cloneNode;
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }

        //step-3 arranging the random node
        originalNode = head;
        cloneNode = cloneHead;
        
        while(originalNode != NULL){
            cloneNode->random = oldToNew[originalNode->random];
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }
        
        return cloneHead;

    }
};