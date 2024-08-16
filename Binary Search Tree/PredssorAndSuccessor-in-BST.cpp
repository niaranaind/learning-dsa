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
        this->data  = data;
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

    if(root->data > data){
        //left part main insert karo
        root->left = insertIntoBST(root->left,data);
    }
    else{
        //right part main insert karo
        root->right = insertIntoBST(root->right,data);
    }
    return root;
}

void takeInput(Node* &root){

    int data;
    cin>>data;

    while(data != -2){
        root = insertIntoBST(root,data);
        cin>>data;
    }
}

//finding predecessor and successor for the key in binary tree
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key){

    if(root == NULL){
        return;
    }

    if(root->data == key){

        //the maximum value of left subtree is predessor
        if(root->left != NULL){
            Node* temp = root->left;
            while(temp->right){
                temp = temp->right;
            }
            pre = temp;
        }

        //the minimum value of right subtree is succesor
        if(root->right != NULL){
            Node* temp = root->right;
            while(temp->left){
                temp = temp->left;
            }
            suc = temp;
        }

        return;
    }

    if(root->data > key){
        //left part mai jao
        suc = root;
        findPreSuc(root->left,pre,suc,key);
    }

    if(root->data < key){
        //right part main jao
        pre = root;
        findPreSuc(root->right,pre,suc,key);
    }
}

//printing binary tree using level order traversal
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
                //queue has some child element
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

int main(){

    //write your test cas here
    Node* root = NULL;
    cout<<"enter the list of data : "<<endl;
    takeInput(root);

    cout<<"printing binary search tree "<<endl;
    levelOrderTraversal(root);

    Node* pre = NULL;
    Node* suc = NULL;
    int key ;
    cout<<"enter the key : ";
    cin>>key;

    findPreSuc(root,pre,suc,key);

    cout<<"predessor is : "<<pre->data<<endl;
    cout<<"successor is : "<<suc->data<<endl;

    return 0;
}