#include<iostream>
#include<queue>
using namespace std;

class Node{

    public:
    int data;
    Node* left;
    Node* right;

    //contructor
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree(Node* root){

    cout<<"enter the data: "<<endl;
    int data;
    cin>>data;
    root = new Node(data);

    //base case
    if(data == -1){
        return NULL;
    }

    cout<<"enter the data for left of "<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"enter the data for right of "<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}

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

        cout<<"enter the data for left of "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;
        if(leftdata != -1){
            temp->left = new Node(leftdata);
            q.push(temp->left);
        }

        cout<<"enter the data for right of "<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;
        if(rightdata != -1){
            temp->right = new Node(rightdata);
            q.push(temp->right);
        }
    }
}

void levelOrderTraversal(Node* root){

    queue<Node*> q;
    q.push(root);
    q.push(NULL); //null is used as seperator

    while(!q.empty()){
        Node* temp = q.front();
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

/*------------------------solution for isIdentical function-----------------------------*/
class solution{
    public:
    //function to check if two tree are identical
    bool isIdentical(Node* r1,Node* r2){
        //base case
        if(r1 == NULL && r2 == NULL){
            return true;
        }

        if(r1 == NULL && r2 != NULL){
            return false;
        }

        if(r1 != NULL && r2 == NULL){
            return false;
        }

        //if both the node is not null
        bool left = isIdentical(r1->left,r2->left);
        bool right = isIdentical(r1->right,r2->right);
        bool value = r1->data == r2->data; //comparison for current node

        if(left && right && value){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){

    Node* root1 = NULL;
    root1 = buildTree(root1);

    Node* root2 = NULL;
    buildFromLevelOrder(root2);

    cout<<"printint both tree "<<endl;
    levelOrderTraversal(root1);
    levelOrderTraversal(root2);

    solution s;
    if(s.isIdentical(root1,root2)){
        cout<<"trees are identical "<<endl;
    }
    else{
        cout<<"trees are not identical "<<endl;
    }

    return 0;
}