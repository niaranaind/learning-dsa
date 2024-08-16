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

/*-------------------------------------kth Smallest element in BST ----------------------------------*/

class solution{
    public:
        int solve(Node* root,int &i,int k){
        //base case
        if(root == NULL){
            return -1;
        }

        //L
        int left = solve(root->left,i,k);

        if(left != -1){
            return left;
        }

        //N
        i++;
        if(i == k){
            return root->data;
        }

        //R
        return solve(root->right,i,k);
    }

    int KthSmallestInBST(Node* root,int k){

        int i = 0;
        return solve(root,i,k);
    }

    //kth largest element in BST 
    int solve2(Node* root,int &i,int k){

        //base case 
        if(root == NULL){
            return -1;
        }

        //L
        int left = solve2(root->left,i,k);

        if(left != -1){
            return left;
        }

        //N
        i++;
        if(i == k){
            return root->data;
        }

        //R
        return solve2(root->right,i,k);
    }

    int KthLargestElementInBST(Node* root,int k,int n){
        int i = 0;
        k = (n-k)+1;
        return solve2(root,i,k);
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

    int k;
    cout<<"enter the kth value : ";
    cin>>k;

    solution sr;
    cout<<"Kth smallest element in BST is : "<<sr.KthSmallestInBST(root,k)<<endl;

    int n;
    cout<<"enter the no of nodes in BST : ";
    cin>>n;
    cout<<"enter the kth value : ";
    cin>>k;
    cout<<"Kth largest element in BST is: "<<sr.KthLargestElementInBST(root,k,n)<<endl;

    return 0;
}