#include<iostream>
#include<queue>
using namespace std;

class node{

    public:
    int data;
    node* left;
    node* right;

    //constructor
    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(node* root){

    cout<<"enter the data: "<<endl;
    int data;
    cin>>data;
    root = new node(data);

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

void buldFromLevelOrder(node* &root){

    queue<node*> q;
    cout<<"enter data for root node "<<endl;
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout<<"enter the data for left of "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;
        if(leftdata != -1){
            temp->left = new node(leftdata);
            q.push(temp->left);
        }

        cout<<"enter the data for right of "<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;
        if(rightdata != -1){
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
}

void levelOrderTraversal(node* root){

    queue<node*> q;
    q.push(root);
    q.push(NULL); //null is used as seperator

    while(!q.empty()){

        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            //previous level traversing is complete
            cout<<endl;
            if(!q.empty()){
                //queue contain some leaf node
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

/*------------------------------solution----------------------*/
class solution1{
    private:
    int height(node* root){
        //base case
        if(root == NULL){
            return 0;
        }

        int left = height(root->left);
        int right = height(root->right);
        int ans = max(left,right) + 1;

        return ans;
    }

    public:
    int diameter(node* root){
        //base case
        if(root == NULL){
            return 0;
        }

        int op1 = diameter(root->left);
        int op2 = diameter(root->right);
        int op3 = height(root->left) + height(root->right)+1;

        int ans = max(op1,max(op2,op3));
        return ans;

    }
};

class solution2{
    private:
    pair<int,int> diameterFast(node* root){
        //base case
        if(root == NULL){
            pair<int,int> p = make_pair(0,0);
            return p;
        }

        pair<int,int> left = diameterFast(root->left);
        pair<int,int> right = diameterFast(root->right);

        int op1 = left.first;
        int op2 = right.first;;
        int op3 = left.second + right.second + 1;

        pair<int,int> ans;
        ans.first = max(op1,max(op2,op3));
        ans.second = max(left.second,right.second) + 1;
        return ans;
    }

    public:
    int diameter(node* root){
        return diameterFast(root).first;
    }
};

int main(){

    //write your test case here
    return 0;
}