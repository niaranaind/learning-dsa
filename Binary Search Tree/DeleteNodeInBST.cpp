#include<iostream>
#include<queue>
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

/*---------------minimum and maximum value in a Binary Search Tree -------------------------------------*/
Node* minValue(Node* root){

    Node* temp = root;
    while(temp->left != NULL){

        temp = temp->left;
    }
    return temp;
}

Node* maxValue(Node* root){

    Node* temp = root;
    while(temp->right != NULL){

        temp = temp->right;
    }
    return temp;
}

/*--------------------------deletion of Node in binary search tree---------------------------------------*/

Node* deleteFromBST(Node* root,int val){

    if(root == NULL){
        return root;
    }

    if(root->data == val){

        // 0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        //1 child 
        //left child case
        if(root->left != NULL && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }

        //right child case
        if(root->left == NULL && root->right != NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }

        //2 child case
        if(root->left != NULL && root->right != NULL){
            int mini = minValue(root->right)->data;
            root->data = mini;
            root->right = deleteFromBST(root->right,mini);
            return root;
        }

    }
    else if(root->data > val){
        //left part mai jao
        root->left = deleteFromBST(root->left,val);
        return root;
    }
    else{
        //right part mai jao
        root->right = deleteFromBST(root->right,val);
        return root;
    }
}

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

    cout<<"min value of BST : "<<minValue(root)->data<<endl;
    cout<<"max value of BST : "<<maxValue(root)->data<<endl;

    //deletion
    int nodeToDelete;
    cout<<"enter the node data you want to delete : ";
    cin>>nodeToDelete;

    deleteFromBST(root,nodeToDelete);
    cout<<endl;

    cout<<"BST after deletion "<<endl;
    levelOrderTraversal(root);


    return 0;
}