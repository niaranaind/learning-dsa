#include<iostream>
#include<queue>
#include<vector>
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

Node* insertIntoBST(Node* &root, int data){

    if(root == NULL){
        root = new Node(data);
        return root;
    }

    if(data > root->data){
        //right part mai insert karo
        root->right = insertIntoBST(root->right,data);
    }
    else{
        //left part mai insert karo
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
    void inorder(Node* root,vector<int> &in){
        //base case
        if(root == NULL){
            return ;
        }
        //LNR
        inorder(root->left,in);
        in.push_back(root->data);
        inorder(root->right,in);
    }

    void fillPreorder(Node* root,vector<int> &inorder,int &index){

        if(root == NULL){
            return;
        }

        //NLR
        root->data = inorder[index++];
        fillPreorder(root->left,inorder,index);
        fillPreorder(root->right,inorder,index);
    }

    public:
    Node* BSTintoMinHip(Node* root){

        vector<int> arr;
        inorder(root,arr);

        int index = 0;
        fillPreorder(root,arr,index);

        return root;
    }
};

int main(){
    //write your test case here
    Node* root = NULL;
    cout<<"Enter data to create BST : "<<endl;
    takeInput(root);

    cout<<"printing the BST : "<<endl;
    levelOrderTraversal(root);

    solution sr;
    sr.BSTintoMinHip(root);

    cout<<"printing min heap : "<<endl;
    levelOrderTraversal(root);

    return 0;
}