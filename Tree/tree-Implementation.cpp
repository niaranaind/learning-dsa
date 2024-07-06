#include<iostream>
#include<queue>
using namespace std;

class node{

    public:
    int data;
    node* left;
    node* rigth;

    //constructor
    node(int data){
        this->data = data;
        this->left = NULL;
        this->rigth = NULL;
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

    cout<<"enter data for inserting in left "<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"enter data for inserting in right "<<data<<endl;
    root->rigth = buildTree(root->rigth);

    return root;
}

void levelOrderTraversal(node* root){

    queue<node*> q;
    q.push(root);
    q.push(NULL);  //null is used as seperator

    while(!q.empty()){

        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            //Previous level is traversed      
            cout<<endl;
            if(!q.empty()){
                //queue still has child node
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }

            if(temp->rigth){
                q.push(temp->rigth);
            }
        }
    }
}

int main(){

    node* root = NULL;
    root = buildTree(root);
    cout<<"printing the level order output: "<<endl;
    levelOrderTraversal(root);
    return 0;
}