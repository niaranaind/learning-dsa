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

//printing the binary tree using level order traversal 
void levelOrderTraversal(Node* root){

    queue<Node*> q;
    q.push(root);
    q.push(NULL);// null is used as seperator

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

        //when entered into new level
        if(level == ans.size()){
            ans.push_back(root->data);
        }

        //left and right recursive call
        solve(root->left,ans,level+1);
        solve(root->right,ans,level+1);
    }

    public:
    vector<int> leftView(Node* root){
        vector<int> ans;
        solve(root,ans,0);
        return ans;
    }
};

int main(){

    //write your test case here 
    Node* root = NULL;
    buildFromLevelOrder(root);

    cout<<"printing the binary tree : "<<endl;
    levelOrderTraversal(root);

    solution s;
    vector<int> ans = s.leftView(root);
    for(int i=0 ; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}