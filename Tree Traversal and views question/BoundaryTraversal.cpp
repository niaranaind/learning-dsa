#include<iostream>
#include<queue>
#include<vector>
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

Node* buildTree(Node* root){

    cout<<"enter the data : "<<endl;
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

//printing tree using level order traversal
void levelOrderTraverse(Node* root){

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
    private:
    void traverseLeft(Node* root,vector<int> &ans){

        //base case
        if(root == NULL){
            return;
        }
        //exculde the leaf node
        if(root->left == NULL && root->right == NULL){
            return;
        }

        ans.push_back(root->data);
        if(root->left){
            traverseLeft(root->left,ans);
        }
        else{
            traverseLeft(root->right,ans);
        }
    }

    void traverseLeaf(Node* root,vector<int> &ans){

        //base case
        if(root == NULL){
            return;
        }
        //leaf node condition
        if(root->left == NULL && root->right == NULL){
            ans.push_back(root->data);
            return;
        }

        traverseLeaf(root->left,ans);
        traverseLeaf(root->right,ans);
    }

    void traverseRight(Node* root,vector<int> &ans){
        //base case
        if(root == NULL){
            return;
        }
        //excuding the leaf node
        if(root->left == NULL && root->right == NULL){
            return;
        } 

        if(root->right){
            traverseRight(root->right,ans);
        }
        else{
            traverseRight(root->left,ans);
        }
        //wapas aagye
        ans.push_back(root->data);
    }

    public:
    vector<int> boundary(Node* root){

        vector<int> ans;
        if(root == NULL){
            return ans;
        }

        //store or print the root node value
        ans.push_back(root->data); 

        //left part print/store
        traverseLeft(root->left,ans);

        //leaf node traverse
        traverseLeaf(root->left,ans);
        traverseLeaf(root->right,ans);

        //right part print/store
        traverseRight(root->right,ans);

        return ans;
    }

};

int main(){

    //write your test case here 
    Node* root = NULL;
    buildFromLevelOrder(root);

    cout<<"printing tree : "<<endl;
    levelOrderTraverse(root);

    solution s;
    vector<int> ans = s.boundary(root);
    for(int i=0 ; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}