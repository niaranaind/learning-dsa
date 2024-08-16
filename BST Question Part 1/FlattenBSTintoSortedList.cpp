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

/*----------------------Flettern BST to a sorted list------------------------------------------*/
class solution{
    private:
    void inorder(Node* root,vector<Node*> &in){

        //base case
        if(root == NULL){
            return;
        }

        //LNR
        inorder(root->left,in);
        in.push_back(root);
        inorder(root->right,in);

    }
    public:
    Node* flattern(Node* root){

        //step 1: create a inorder list from BST
        vector<Node*> inorderNode;
        inorder(root,inorderNode);

        //step 2: using loop make the sorted list
        Node* newRoot =  inorderNode[0];
        Node* curr = newRoot;

        for(int i = 1 ; i < inorderNode.size()-1 ; i++){
            Node* temp = inorderNode[i];
            curr->left = NULL;
            curr->right = temp;
            curr = temp;
        }

        //step 3:  last node left and right pointer point to null
        curr->left = NULL;
        curr->right = NULL;

        return newRoot;
    }

    void inorder2(Node* root,vector<int> &in){
        //base case
        if(root == NULL){
            return;
        }

        //LNR
        inorder2(root->left,in);
        in.push_back(root->data);
        inorder2(root->right,in);
    }

    Node* flattern2(Node* root){

        //step 1: creating inorder list from BST
        vector<int> inorderVal;
        inorder2(root,inorderVal);

        //step 2: creating sorted list using loops
        Node* newNode = new Node(inorderVal[0]);
        Node* curr = newNode;

        for(int i = 1;i < inorderVal.size() ; i++){
            Node* temp = new Node(inorderVal[i]);
            curr->left = NULL;
            curr->right = temp;
            curr = temp;
        }

        //step 3: last node left & right pointer point to NULL
        curr->left = NULL;
        curr->right = NULL;

        return newNode;
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
    solution sr;
    // cout<<"flattern BST is : "<<endl;
    // levelOrderTraversal(sr.flattern(root));

    cout<<endl;
    cout<<"flattern BST is : "<<endl;
    levelOrderTraversal(sr.flattern2(root));

    return 0;
}