#include<iostream>
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
        if(head == NULL){// when List is Empty
            head = newNode;
            tail = newNode;
            return;
        }
        else{
            //when list is non-Empty
            tail->next = newNode;
            tail = newNode;
        }
    }

    public:
    Node* cloneList(Node* head){

        //step-1 create a clone list
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        Node* temp = head;

        while(temp != NULL){
            insertAtTail(cloneHead,cloneTail,temp->data);
            temp = temp->next;
        }

        //step-2 clone node is  added in between original list
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        while(originalNode != NULL && cloneNode != NULL){
            Node* next = originalNode->next;
            originalNode->next = cloneNode;
            originalNode = next;

            next = cloneNode->next;
            cloneNode->next = originalNode;
            cloneNode = next;
        }

        //step-3 arraging random node
        temp = head;
        while(temp != NULL){

            if(temp->next != NULL){

                if(temp->random != NULL){
                    temp->next->random = temp->random->next;
                }
                else{
                    temp->next->random = temp->random;
                }
            }
            temp = temp->next->next;
            
        }

        //step-4 reverting step-2 
        originalNode = head;
        cloneNode = cloneHead;
        while(originalNode != NULL && cloneNode != NULL){
            
            originalNode->next = cloneNode->next;
            originalNode = originalNode->next;

            if(originalNode != NULL){
                cloneNode->next = originalNode->next;
            }
            cloneNode = cloneNode->next;
        }

        //step-5 return head pointer of clone list
        return cloneHead;
    }
};