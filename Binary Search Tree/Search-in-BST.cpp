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

    if(root->data > data){
        //left part mai insert karo
        root->left = insertIntoBST(root->left,data);
    }
    else{
        //right part mai insert karo
        root->right = insertIntoBST(root->right,data);
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

//printing binary search tree using level order traversal 
void levelOrderTraversal(Node* root){

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){

        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            //previous traversal is complete
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

    public:
    bool searchInBST_Recursion(Node* root,int x){

        //base case
        if(root == NULL){
            return false;
        }

        if(root->data == x){
            return true;
        }

        //recursive call 
        if(root->data > x){
            //left part main search karo
            return searchInBST_Recursion(root->left,x);
        }
        else{
            //right part main search karo
            return searchInBST_Recursion(root->right,x);
        }
    }

    bool searchInBST_iteration(Node* root,int x){

        Node* temp = root;

        while(temp != NULL){

            if(temp->data == x){
                return true;
            }

            if(temp->data > x){
                //left part main search karo
                temp = temp->left;
            }
            else{
                //right part main search karo
                temp = temp->right;
            }
        }
        return false;
    }
};

int main(){

    //write your test case here
    Node* root = NULL;
    cout<<"Enter the data to create BST "<<endl;
    takeInput(root);

    cout<<"printing BST : "<<endl;
    levelOrderTraversal(root);

    int x;
    cout<<"enter the target element : ";
    cin>>x;

    solution sr;
    if(sr.searchInBST_Recursion(root,x)){
        cout<<"element is present "<<endl;
    }
    else{
        cout<<"element is NOT present "<<endl;
    }

    if(sr.searchInBST_iteration(root,x)){
        cout<<"element is present "<<endl;
    }
    else{
        cout<<"element is NOT present "<<endl;
    }
}