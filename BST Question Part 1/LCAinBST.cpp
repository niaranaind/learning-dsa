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

/*-------------------------------Lowest commen Ancestor in BST ------------------------------------------------------*/
class solution{
    public:
    //Approach 1 :
    Node* LCAinaBST(Node* root,Node* P,Node* Q){

        //base case
        if(root == NULL){
            return NULL;
        }

        if(root->data > P->data && root->data > Q->data){
            //left part mai jao
            return LCAinaBST(root->left,P,Q);
        }

        if(root->data < P->data && root->data < Q->data){
            //right part mai jao
            return LCAinaBST(root->right,P,Q);
        }

        return root;
    }

    //Approach 2 : 
    Node* LCAinaBST2(Node* root,Node* P,Node* Q){

        while(root != NULL){

            if(root->data > P->data && root->data > Q->data){
                //left part mai jap
                root = root->left;
            }
            else if(root->data < P->data && root->data < Q->data){
                //right part mai jao
                root = root->right;
            }
            else{
                return root;
            }
        }
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

    return 0;
}