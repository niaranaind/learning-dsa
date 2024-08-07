#include<iostream>
#include<queue>
#include<map>
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

//creating tree using level order traversal 
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

//printing tree using level order traversal
void levelOrderTraversal(Node* root){

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            //previous level is traversed
            cout<<endl;
            if(!q.empty()){
                //queue has some child node
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(root->left){
                q.push(root->left);
            }
            if(root->right){
                q.push(root->right);
            }
        }
    }
}

class solution{
    private:
    void creatMapping(int in[],map<int,int> &nodeToIndex,int n ){

        for(int i=0 ; i<n ; i++){
            nodeToIndex[in[i]] = i;
        }
    }
    Node* solve(int in[],int post[],int &index,int inorderStart,int inorderEnd,int n,map<int,int> &nodeToIndex){
        //base case
        if(index < 0 || inorderStart > inorderEnd){
            return NULL;
        }

        int element = post[index--];
        Node* root = new Node(element);
        int position = nodeToIndex[element];

        //recursive call
        root->right = solve(in,post,index,position+1,inorderEnd,n,nodeToIndex);
        root->left = solve(in,post,index,inorderStart,position-1,n,nodeToIndex);

        return root;
    }
    public:
    Node* buildtree(int in[],int post[],int n){
        int postOrderIndex = n-1;
        //creating mapping
        map<int,int> nodeToIndex;
        creatMapping(in,nodeToIndex,n);
        Node* ans = solve(in,post,postOrderIndex,0,n-1,n,nodeToIndex);
        return ans;
    }
};

void preOrderTraversal(Node* root){
    //base case
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

int main(){
    //write your test case here
    int in[] = {4, 8, 2, 5, 1, 6, 3, 7};
    int post[] = {8, 4, 5, 2, 6, 7, 3, 1};

    solution s;
    Node* root = s.buildtree(in,post,8);

    preOrderTraversal(root);
    return 0;
}