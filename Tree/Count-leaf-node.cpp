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

//bulding tree using level order traversal
void buildFromLevelOrder(node* &root){

    queue<node*> q;
    cout<<"enter data for root "<<endl;
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){

        node* temp = q.front();
        q.pop();

        cout<<"enter left node for: "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;
        if(leftdata != -1){
            temp->left = new node(leftdata);
            q.push(temp->left);
        }

        cout<<"enter right node for: "<<temp->data<<endl;
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
            //previous level traversal is complete
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

/*-----------------------------solution------------------------------------------------*/

void inorder(node* root,int &count){
    //base case
    if(root == NULL){
        return;
    }

    inorder(root->left,count);

    if(root->left == NULL && root->right == NULL){
        count++;
    }

    inorder(root->right,count);
}

int noOfleafNode(node* root){
    int cnt = 0;
    inorder(root,cnt);
    return cnt;
}

int main(){

    node* root = NULL;
    buildFromLevelOrder(root);
    levelOrderTraversal(root);

    cout<<"number of leaf node is: "<<noOfleafNode(root)<<endl;

    return 0;
}