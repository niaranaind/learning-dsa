#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    //constructor for tree
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

//building tree using level order traversal
void buildTreeFromLevelOrder(Node* &root){

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
            //previous level is traversal is complete
            if(!q.empty()){
                //queue has some child element
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
    int findPosition(int in[],int element,int n){

        for(int i=0;i<n;i++){
            if(in[i] == element){
                return i;
            }
        }
        return -1;
    }
    Node* solve(int in[],int pre[],int &index,int inorderStart,int inorderEnd,int n){

        //base case
        if(index >= n || inorderStart >inorderEnd){
            return NULL;
        }

        int element = pre[index++];
        Node* root = new Node(element);
        int position = findPosition(in,element,n);

        //recursive call
        root->left = solve(in,pre,index,inorderStart,position-1,n);
        root->right = solve(in,pre,index,position+1,inorderEnd,n);

        return root;
    }
    public:
    Node* buildTrees(int in[],int pre[],int n){
        int preOrderIndex = 0;
        Node* ans = solve(in,pre,preOrderIndex,0,n-1,n);
        return ans;
    }
};

class solution2{
    private:
    void createMapping(int in[],map<int,int> &nodeToIndex,int n){

        for(int i=0;i<n;i++){
            nodeToIndex[in[i]] = i;
        }
    }
    Node* solve(int in[],int pre[],int &index,int inorderStart,int inorderEnd,int n,map<int,int> &nodeToIndex){

        //base case
        if(index >= n || inorderStart >inorderEnd){
            return NULL;
        }

        int element = pre[index++];
        Node* root = new Node(element);
        int position = nodeToIndex[element];

        //recursive call
        root->left = solve(in,pre,index,inorderStart,position-1,n,nodeToIndex);
        root->right = solve(in,pre,index,position+1,inorderEnd,n,nodeToIndex);

        return root;
    }
    public:
    Node* buildTrees(int in[],int pre[],int n){
        int preOrderIndex = 0;
        //creating map
        map<int,int> nodeToIndex;
        createMapping(in,nodeToIndex,n);
        Node* ans = solve(in,pre,preOrderIndex,0,n-1,n,nodeToIndex);
        return ans;
    }
};

void postOrder(Node* root){
    //base case
    if(root == NULL){
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

int main(){
    //write your test case here
    int in[] = {1,6,8,7};
    int pre[] = {1,6,7,8};

    solution s;
    Node* root = s.buildTrees(in,pre,4);

    postOrder(root);
    cout<<endl;
    
    solution2 sr;
    Node* root1 = sr.buildTrees(in,pre,4);

    postOrder(root1);
    return 0;
}