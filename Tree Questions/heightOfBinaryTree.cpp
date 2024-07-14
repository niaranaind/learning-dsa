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

//building tree
node* buildTree(node* root){

    cout<<"enter the data :"<<endl;
    int data;
    cin>>data;
    root = new node(data);

    //base case
    if(data == -1){
        return NULL;
    }

    cout<<"enter data for left part of "<<root->data<<endl;
    root->left = buildTree(root->left);

    cout<<"enter data for right part of "<<root->data<<endl;
    root->right = buildTree(root->right);

    return root;
}

//building tree using level order traversal
void buildFromLevelOrder(node* &root){

    queue<node*> q;
    cout<<"enter data for root node "<<endl;
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){

        node* temp = q.front();
        q.pop();

        cout<<"enter the data for left part of "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;
        if(leftdata != -1){
            temp->left = new node(leftdata);
            q.push(temp->left);
        }

        cout<<"enter the data for right part of "<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;
        if(rightdata != -1){
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
}

//level order traversal
void levelOrderTraversal(node* root){

    queue<node*> q;
    q.push(root);
    q.push(NULL); //NULL is used as seperator

    while(!q.empty()){

        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            //previous level traversal is complete
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
/*------------------------height of the tree code----------------------------------*/
class solution{

    public:
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
};

int main(){
    node* root = NULL;
    root = buildTree(root);
    //printing tree using level order trversal
    levelOrderTraversal(root);

    solution s;
    cout<<"height of tree is : "<<s.height(root)<<endl;

    return 0;
}