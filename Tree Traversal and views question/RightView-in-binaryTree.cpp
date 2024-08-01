#include<iostream>
#include<vector>
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

//buildine tree using level order traversal
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
            //previous level is traversed
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
    void solve(Node* root,vector<int> &ans,int level){
        //base case
        if(root == NULL){
            return;
        }

        //condition for first node from right
        if(level == ans.size()){
            ans.push_back(root->data);
        }

        //right and left node recursive call
        solve(root->right,ans,level+1);
        solve(root->left,ans,level+1);
    }

    public:
    vector<int> rightView(Node* root){

        vector<int> ans;
        solve(root,ans,0);
        return ans;
    }
};

int main(){

    //write your test case here
    Node* root = NULL;
    buildFromLevelOrder(root);

    cout<<"printing binary tree "<<endl;
    levelOrderTraversal(root);

    solution s;
    vector<int> ans = s.rightView(root);
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}