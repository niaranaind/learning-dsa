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
    pair<int,int> solve(Node* root){
        //base case
        if(root == NULL){
            pair<int,int> p = make_pair(0,0);
            return p;
        }

        //left and right recursive call
        pair<int,int> left = solve(root->left);
        pair<int,int> right = solve(root->right);

        pair<int,int> result;
        result.first = root->data + left.second + right.second;
        result.second = max(left.first,left.second) + max(right.first,right.second);

        return result;
    }
    
    public:
    int getMaxSum(Node* root){
        
        pair<int,int> ans = solve(root);
        return max(ans.first,ans.second);
    }
};

int main(){
    
    //write your test case here
    Node* root = NULL;
    buldFromLevelOrder(root);

    cout<<"printing binary tree : "<<endl;
    levelOrderTraversal(root);

    solution s;
    cout<<"maximum sum of non-adjacent nodes : "<<s.getMaxSum(root)<<endl;

    return 0;
}
