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

Node* insertIntoBST(Node* root,int data){

    //base case
    if(root == NULL){
        root = new Node(data);
        return root;
    }

    if(data > root->data){
        //right wale part mai insert karo
        root->right = insertIntoBST(root->right,data);
    }
    else{
        //left wale part mai insert karo
        root->left = insertIntoBST(root->left,data);
    }

    return root;
}

void takeInput(Node* &root){

    int data;
    cin>>data;

    while(data != -1){
        root = insertIntoBST(root,data);
        cin>>data;
    }
}

void levelOrderTraversal(Node* root){

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){

        Node* temp = q.front();
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

void inorderTraversal(Node* root){

    //base case
    if(root == NULL){
        return ;
    }

    //LNR
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}
/*-----------------------------------------------------------------------------------------------------------------------*/
class solution{
    //find the predessor and successor of BST
    public:
    pair<int,int> predessorSuccessor(Node* root,int key){

        //step 1 : find the key and track the possible pre and suc
        Node* temp = root;
        int pre = -1;
        int suc = -1;

        while(temp->data != key){

            if(temp->data > key){
                //left part mai jao
                suc = temp->data;
                temp = temp->left;
            }
            else{
                //right part mai jao
                pre = temp->data;
                temp = temp->right;
            }
        }

        //temp is pointing to key node
        //step 2: find predessor and successor
        //pre
        Node* leftTree = temp->left;
        while(leftTree != NULL){
            pre = leftTree->data;
            leftTree = leftTree->right;
        }

        //suc
        Node* rightTree = temp->right;
        while(rightTree != NULL){
            suc = rightTree->data;
            rightTree = rightTree->left;
        }

        pair<int,int> ans = make_pair(pre,suc);
        return ans;
    }
};

int main(){

    //write your test case here
    Node* root = NULL;

    cout<<"Enter data to create BST : "<<endl;
    takeInput(root);

    cout<<"printing the BST : "<<endl;
    levelOrderTraversal(root);

    cout<<endl;
    cout<<"inorder traversal of BST "<<endl;
    inorderTraversal(root);

    cout<<endl;
    int k;
    cout<<"enter the key value : ";
    cin>>k;

    solution sr;
    cout<<"predessor of given key in BST is : "<<sr.predessorSuccessor(root,k).first<<endl;
    cout<<"successor of given key in BST is : "<<sr.predessorSuccessor(root,k).second<<endl;

    return 0;
}