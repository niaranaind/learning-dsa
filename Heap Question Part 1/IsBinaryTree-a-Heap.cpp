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

//building binary tree using level order traversal 
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
            if(temp->left){
                q.push(temp->left);
            }

            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

class solution {
    private:
    int countNode(Node* root){
        //base case
        if(root == NULL){
            return 0;
        }

        int ans = 1+ countNode(root->left) + countNode(root->right);
        return ans;
    }

    bool isCBT(Node* root,int index,int cnt){

        if(root == NULL){
            return true;
        }

        if(index >= cnt){
            return false;
        }
        else{
            bool left  = isCBT(root->left,2*index+1,cnt);
            bool right = isCBT(root->right,2*index+2,cnt);
            return left&&right;
        }
    }

    bool isMaxOrder(Node* root){

        //leaf Node
        if(root->left == NULL && root->right == NULL){
            return true;
        }

        if(root->right == NULL){
            return (root->data > root->left->data);
        }
        else{
            bool left  = isMaxOrder(root->left);
            bool right = isMaxOrder(root->right);
            return (left && right && (root->data > root->left->data && root->data > root->right->data));
        }
    }
    public:
    bool isHeap(Node* root){

        int totalCount = countNode(root);
        int index = 0;
        if(isCBT(root,index,totalCount) && isMaxOrder(root)){
            return true;
        }
        else{
            return false;
        }

    }
};

int main(){
    //write your test case here
    Node* root = NULL;
    buildFromLevelOrder(root);

    cout<<"printing the binary tree :"<<endl;
    levelOrderTraversal(root);

    solution sr;
    cout<<" is the binary tree a Heap : "<<sr.isHeap(root)<<endl;

    return 0;
}