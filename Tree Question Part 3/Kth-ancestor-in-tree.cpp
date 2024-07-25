#include<iostream>
#include<queue>
#include<vector>
#include<limits.h>
using namespace std;

class Node{

    public:
    int data;
    Node* left;
    Node* right;

    //constructor
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

//building binary tree using level order traversal
void buldFromLevelOrder(Node* &root){

    cout<<"enter the data : "<<endl;
    queue<Node*> q;
    int data;
    cin>>data;
    root = new Node(data);
    q.push(root);

    while(!q.empty()){

        Node* temp = q.front();
        q.pop();

        cout<<"enter the data for left of : "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;
        if(leftdata != -1){
            temp->left = new Node(leftdata);
            q.push(temp->left);
        }

        cout<<"enter the data for right of : "<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;
        if(rightdata != -1){
            temp->right = new Node(rightdata);
            q.push(temp->right);
        }
    }

}

//printing the binary tree using level order traversal
void levelOrderTraversal(Node* root){

    queue<Node*> q;
    q.push(root);
    q.push(NULL); // null is used as seperator

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            //previous level is traversed 
            cout<<endl;
            if(!q.empty()){
                //queue has some child node
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }

            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

class solution{
    private:
    Node* solve(Node* root,int &k,int node){
        //base case
        if(root == NULL){
            return NULL;
        }

        if(root->data == node){
            return root;
        }

        //leftv and right recursive call
        Node* leftAns = solve(root->left,k,node);
        Node* rightAns = solve(root->right,k,node);
        
        if(leftAns != NULL && rightAns == NULL){
            k--;
            if(k<=0){
                k = INT_MAX;
                return root;
            }
            return leftAns;
        }

        if(leftAns == NULL && rightAns != NULL){
            k--;
            if(k<=0){
                k = INT_MAX;
                return root;
            }
            return rightAns;
        }

        return NULL; // when leftAns == NULL and rightAns == NULL
    }
    public:
    int kthAncestor(Node* root ,int k,int node){

        Node* ans = solve(root,k,node);
        if(ans == NULL || ans->data == node){
            return -1;
        }
        else{
            return ans->data;
        }
    }
};

int main(){
    
    //write your test case here
    Node* root = NULL;
    buldFromLevelOrder(root);

    cout<<"printing binary tree : "<<endl;
    levelOrderTraversal(root);

    int k ,node;
    cout<<"enter the value of k : ";
    cin>>k;
    cout<<"enter the value of node : ";
    cin>>node;

    solution s;
    cout<<"kth ancestor in binary tree is : "<<s.kthAncestor(root,k,node)<<endl;

    return 0;

}