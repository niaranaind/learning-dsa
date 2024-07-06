#include<iostream>
#include<queue>
using namespace std;

class node{

    public:
    int data;
    node* left;
    node* right;

    //constructor
    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(node* root){

    cout<<"enter the data: ";
    int data;
    cin>>data;
    root = new node(data);

    //base case
    if(data == -1){
        return NULL;
    }

    cout<<"enter data for inserting left "<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"enter data fro inserting right "<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraverse(node* root){

    queue<node*> q;
    q.push(root);
    q.push(NULL); //NULL is used as seperator

    while(!q.empty()){

        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            //previous level traversal is complete
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

void buildFromLevelOrder(node* &root){

    queue<node*> q;
    cout<<"enter data for root node "<<endl;
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout<<"enter left node for: "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;
        if(leftdata != -1){
            temp->left = new node(leftdata);
            q.push(temp->left);
        }

        cout<<"enter right node for: "<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;
        if(rightdata != -1){
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
}

int main(){

    node* root = NULL;
    buildFromLevelOrder(root);
    levelOrderTraverse(root);

    return 0;
}