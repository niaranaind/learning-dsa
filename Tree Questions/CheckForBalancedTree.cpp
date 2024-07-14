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

//building tree using recursion
Node* buildTree(Node* root){

    cout<<"enter the data: "<<endl;
    int data;
    cin>>data;
    root = new Node(data);

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

void buildFromLevelOrder(Node* &root){

    queue<Node*> q;
    cout<<"enter the data: "<<endl;
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

//level order traversal
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
                //queue has some child eement
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
/*------------------------------------solution for isBlanced function-----------------------------------*/
class solution{
    private:
    int height(Node* node){
        //base case
        if(node == NULL){
            return 0;
        }

        int left = height(node->left);
        int right = height(node->right);
        int ans = max(left,right) + 1;

        return ans;
    }

    public:
    bool isBalanced(Node* root){
        //base case
        if(root == NULL){
            return true;
        }

        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        bool diff = abs(height(root->left) - height(root->right)) <= 1;

        if(left && right && diff){
            return true;
        }
        else{
            return false;
        }
    }
};

class solution2{

    public:
    pair<bool,int> isBalancedFast(Node* node){
        //base case
        if(node == NULL){
            pair<bool,int> p = make_pair(true,0);
            return p;
        }

        pair<bool,int> left = isBalancedFast(node->left);
        pair<bool,int> right = isBalancedFast(node->right);

        bool leftans = left.first;
        bool rightans = right.first;
        bool diff = abs(left.second - right.second) <= 1;

        pair<bool,int> ans;
        ans.second = max(left.second,right.second) + 1;
        if(leftans && rightans && diff){
            ans.first = true;
        }
        else{
            ans.first = false;
        }

        return ans;
    }

    bool isBalanced(Node* root){
        return isBalancedFast(root).first;
    }
};

int main(){
    //write your test case here
    return 0;
}