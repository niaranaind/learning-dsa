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

//building tree using level order traversal
void buildFromlevelOrderTraversal(Node* &root){

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

//printing tree using recursion inorder traversal

void inorderTraversal(Node* root){
    //base case
    if(root == NULL){
        return;
    }

    //LNR 
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

void MorrisTraversal(Node* root){

    if(root == NULL){
        return;
    }

    // current pointer and predecessor pointer
    Node* current;
    Node* pre;

    current = root;
    while(current != NULL){

        if(current->left == NULL){
            cout<<current->data<<" ";
            current = current->right;
        }
        else{
            //find predessor
            pre = current->left;
            while(pre->right != NULL && pre->right != current){
                pre = pre->right;
            }

            if(pre->right == NULL){
                //create temperory link
                pre->right = current;
                current = current->left;
            }
            else{
                //remove temperary link 
                pre->right = NULL;
                cout<<current->data<<" ";
                current = current->right;
            }
        }
    }
}

int main(){
    //write your test case here
    Node* root = NULL;
    buildFromlevelOrderTraversal(root);

    cout<<"inorder traversal : "<<endl;
    inorderTraversal(root);

    cout<<endl;
    
    cout<<"morris traversal : "<<endl;
    MorrisTraversal(root);

    return 0;
}