#include<iostream>
#include<queue>
using namespace std;

class node{

    public:
    int data;
    node* left;
    node* right;

    //constrcutor
    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(node* root){

    cout<<"enter the data"<<endl;
    int data;
    cin>>data;
    root = new node(data);

    //base case
    if(data == -1){
        return NULL;
    }

    cout<<"enter data for inserting in left "<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"enter data for inserting in right "<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraversal(node* root){

    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){

        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            //previous level traversing is complete
            cout<<endl;
            if(!q.empty()){
                //queue contining some child element 
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

void inorder(node* root){
    //base case
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(node* root){
    //base case
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root){
    //base case
    if(root == NULL){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main(){

    node* root = NULL;
    root = buildTree(root);
    cout<<"printing level order traversal : "<<endl;
    levelOrderTraversal(root);

    cout<<"inorder traversal: ";
    inorder(root);

    cout<<"preorder traversal: ";
    preorder(root);

    cout<<"postorder traversal: ";
    postorder(root);

    return 0;
}