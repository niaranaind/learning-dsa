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

class solution{
    private:
    void inorder(Node* root,vector<int> &in){
        //base case
        if(root == NULL){
            return ;
        }
        //LNR
        inorder(root->left,in);
        in.push_back(root->data);
        inorder(root->right,in);
    }

    Node* solve(Node* root,vector<int> &in,int i,int j){

        if(i>j){
            return NULL;
        }

        int mid = i+(j-i)/2;
        root = new Node(in[mid]);

        //recursive call
        root->left = solve(root->left,in,i,mid-1);
        root->right = solve(root->right,in,mid+1,j);

        return root;
    }

    public:
    Node* balancedBST(Node* root){

        //step 1 : creating inorder list from BST
        vector<int> inorderval;
        inorder(root,inorderval);

        int s = 0;
        int e = inorderval.size() - 1;

        return solve(root,inorderval,s,e);

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
    levelOrderTraversal(sr.balancedBST(root));

    return 0;
}