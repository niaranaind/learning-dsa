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

void levelOrderTraveral(Node* root){

    queue<Node*> q;
    q.push(root);
    q.push(NULL); //null is used as seperator

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            //preious level is traversed
            cout<<endl;
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

/*---------------------solution for sum tree problem------------------------*/
class solution{

    public:
    pair<bool,int> isSumTreeFast(Node* root){
        //base case
        if(root == NULL){
            pair<bool,int> p = make_pair(true,0);
            return p;
        }

        if(root->left == NULL && root->right == NULL){
            pair<bool,int> p = make_pair(true,root->data);
            return p;
        }

        pair<bool,int> leftans = isSumTreeFast(root->left);
        pair<bool,int> rightans = isSumTreeFast(root->right);

        bool left = leftans.first;
        bool right= rightans.first;
        bool condn = root->data == leftans.second + rightans.second;
        pair<bool,int> ans;

        if(left && right && condn){
            ans.first = true;
            ans.second = root->data + leftans.second + rightans.second;
        }
        else{
            ans.first = false;
        }

        return ans;
    }

    bool isSumTree(Node* root){
        return isSumTreeFast(root).first;
    }
};

int main(){

    Node* root = NULL;
    buildFromLevelOrder(root);

    cout<<"print the tree: "<<endl;
    levelOrderTraveral(root);

    solution s;
    if(s.isSumTree(root)){
        cout<<"Tree is sum tree "<<endl;
    }
    else{
        cout<<"Tree is NOT sum tree "<<endl;
    }

    return 0;
}