#include<iostream>
using namespace std;

 class Node {
   public:
 		int data;
 		Node *next;
  		Node *child;
 		Node() : data(0), next(nullptr), child(nullptr){};
 		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
  };
 
Node* merge(Node* left,Node* right){

	if(left == NULL){
		return right;
	}

	if(right == NULL){
		return left;
	}

	Node* ans = new Node(-1);
	Node* temp = ans;
	while(left != NULL && right != NULL){

		if(left->data < right-> data){
			temp->child = left;
			temp = left;
			left = left->child;
		}
		else{
			temp->child = right;
			temp = right;
			right = right->child;
		}

	}

	while(left != NULL){
		temp->child = left;
		temp = left;
		left = left->child;
	}

	while(right != NULL){
		temp->child = right;
		temp = right;
		right = right->child;
	}

	ans = ans->child;
	return ans;
}

Node* flattenLinkedList(Node* head) 
{
	if(head==NULL || head->next == NULL)
	return head;
	// Write your code here
	Node* down = head;
	Node* right = flattenLinkedList(head->next);
	down->next = NULL;

	Node* ans1 = merge(down,right);
	return ans1;

}