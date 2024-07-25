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

//building binary tree using level order traversal
void buldFromLevelOrder(Node* &root){

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
    q.push(NULL); // null is used as seperator

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
    void solve(Node* root,int k,vector<int> path,int &count){
        //base case
        if(root == NULL){
            return;
        }

        path.push_back(root->data);
        //left recursion call
        solve(root->left,k,path,count);
        //right recursion call
        solve(root->right,k,path,count);

        //check for k sum
        int sum = 0;
        int size = path.size();
        for(int i = size-1 ; i>=0 ; i--){

            sum +=path[i];
            if(sum == k){
                count++;
            }
        }

        path.pop_back();
    }

    public:
    int sumK(Node* root,int k){
        vector<int> path;
        int count = 0;
        solve(root,k,path,count);
        return count;
    }
};

int main(){
    
    //write your test case here
    Node* root = NULL;
    buldFromLevelOrder(root);

    cout<<"printing binary tree : "<<endl;
    levelOrderTraversal(root);

    int k;
    cout<<"enter the value of k : "<<endl;
    cin>>k;

    solution s;
    cout<<"the no of path present : "<<s.sumK(root,k)<<endl;


}