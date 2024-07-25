#include<iostream>
#include<vector>
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

//buildine tree using level order traversal
void buildFromLevelOrder(Node* &root){

    queue<Node*> q;
    cout<<"enter the data : "<<endl;
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

//printing binary tree using level order traversal 
void levelOrderTraversal(Node* root){

    queue<Node*> q;
    q.push(root);
    q.push(NULL); //null is used as seperator

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            //previous level is traversed
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

class solution{
    public:
    Node* lca(Node* root,int n1,int n2){

        //base case
        if(root == NULL){
            return NULL;
        }

        if(root->data == n1 || root->data == n2){
            return root;
        }

        //left and right recursive call
        Node* leftAns = lca(root->left,n1,n2);
        Node* rightAns = lca(root->right,n1,n2);

        if(leftAns != NULL && rightAns != NULL){
            return root;
        }
        else if(leftAns != NULL && rightAns == NULL){
            return leftAns;
        }
        else if(leftAns == NULL && rightAns != NULL){
            return rightAns;
        }
        else{
            return NULL;
        }
    }
      
};

int main(){

    //write your test case here
    Node* root = NULL;
    buildFromLevelOrder(root);

    cout<<"printing binary tree "<<endl;
    levelOrderTraversal(root);

    int n1,n2;

    cout<<"enter the n1 value : ";
    cin>>n1;

    cout<<"enter the n2 value : ";
    cin>>n2;

    solution s;

    cout<<"lowest common Ancestor of binary tree is : "<<s.lca(root,n1,n2)->data<<endl;

    return 0;
}