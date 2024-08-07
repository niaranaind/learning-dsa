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

//preorder traversal of binary tree
void preorderTraversal(Node* root){

    //base case
    if(root == NULL){
        return;
    }

    //NLR
    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);

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
            //previous level is traversal is complete
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

//flattern binary tree into linked list
class solution{
    public:
    void flatten(Node* root){

        Node* curr = root;
        Node* pre; //predessor

        while(curr != NULL){

            if(curr->left){
                //find predessor
                pre = curr->left;
                while(pre->right != NULL){
                    pre = pre->right;
                }

                pre->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }

            curr = curr->right;
        }
    }
};

int main(){
    
    //write your test case here
    Node* root = NULL;
    buildFromLevelOrder(root);

    cout<<"printing binary tree : "<<endl;
    levelOrderTraversal(root);

    cout<<endl;
    preorderTraversal(root);

    cout<<endl;

    solution s;
    s.flatten(root);
    levelOrderTraversal(root);
    
    return 0;
}