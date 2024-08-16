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

/*-----------------------------------Largest BST in Binary Tree ---------------------------------------------*/

//build binary tree using level order traversal
void buildFromLevelOrder(Node* &root){

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

class solution{
    private:
    class info{

        public:
        int maxi;
        int mini;
        bool isBST;
        int size;
    };

    info solve(Node* root,int &ans){

        //base case
        if(root == NULL){

            return {INT_MIN,INT_MAX,true,0};
        }

        //recursive call
        info left = solve(root->left,ans);
        info right = solve(root->right,ans);

        info currNode ;
        currNode.maxi = max(root->data,right.maxi);
        currNode.mini = min(root->data,left.mini);
        currNode.size = left.size + right.size + 1;

        if(left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini)){
            currNode.isBST = true;
        }
        else{
            currNode.isBST = false;
        }

        //answer update
        if(currNode.isBST){
            ans = max(currNode.size,ans);
        }

        return currNode;
    }

    public:
    int largestBST(Node* root){

        int maxSize = 0;
        info temp = solve(root,maxSize);
        return maxSize;
    }

};

int main(){

    //write your test case here
    Node* root = NULL;

    cout<<"Enter data to create Binary tree : "<<endl;
    buildFromLevelOrder(root);

    cout<<"printing the BST : "<<endl;
    levelOrderTraversal(root);

    cout<<endl;

    solution sr;
    cout<<"largest BST size in binary tree is : "<<sr.largestBST(root)<<endl;

    return 0;
}