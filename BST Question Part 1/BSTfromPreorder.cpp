#include<iostream>
#include<queue>
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

Node* insertIntoBST(Node* root,int data){

    //base case
    if(root == NULL){
        root = new Node(data);
        return root;
    }

    if(data > root->data){
        //right wale part mai insert karo
        root->right = insertIntoBST(root->right,data);
    }
    else{
        //left wale part mai insert karo
        root->left = insertIntoBST(root->left,data);
    }

    return root;
}

void takeInput(Node* &root){

    int data;
    cin>>data;

    while(data != -1){
        root = insertIntoBST(root,data);
        cin>>data;
    }
}

void levelOrderTraversal(Node* root){

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){

        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            //previous level traversal is complete
            cout<<endl;
            if(!q.empty()){
                //queue has some child nodes
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

void inorderTraversal(Node* root){

    //base case
    if(root == NULL){
        return ;
    }

    //LNR
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

class solution{
    private:
    Node* solve(vector<int> &preorder,int min,int max,int &i){

        //base case
        if(i >= preorder.size()){
            return NULL;
        }

        if(preorder[i] < min || preorder[i] > max){
            return NULL; //out of range case
        }

        Node* root = new Node(preorder[i++]);
        //recursive call
        root->left = solve(preorder,min,root->data,i);
        root->right = solve(preorder,root->data,max,i);

        return root;
    }

    public:
    Node* preorderToBST(vector<int> &preorder){

        int min = INT_MIN;
        int max = INT_MAX;
        int i = 0;
        return solve(preorder,min,max,i);
    }
};

int main(){

    //write your test case here
    Node* root = NULL;

    cout<<"Enter data to create BST : "<<endl;
    takeInput(root);

    cout<<"printing the BST : "<<endl;
    levelOrderTraversal(root);

    cout<<endl;
    cout<<"inorder traversal of BST "<<endl;
    inorderTraversal(root);

    cout<<endl;

    solution sr;
    vector<int> preorder{20,10,5,15,13,35,30,42};

    levelOrderTraversal(sr.preorderToBST(preorder));

    return 0;
}