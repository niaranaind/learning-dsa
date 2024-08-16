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

/*-------------------------------------------------------Two Sum in BST -------------------------------------------*/

class solution{
    private:
    void inorder(Node* root,vector<int> &in){

        if(root == NULL)
        return;

        //LNR
        inorder(root->left,in);
        in.push_back(root->data);
        inorder(root->right,in);
    }

    public:
    bool twoSumInBST(Node* root,int target){

        //step 1: creating inorder sorted list from  BST
        vector<int> inorderVal;
        inorder(root,inorderVal);

        //step 2: find the pair using two pointer approach
        int i = 0;
        int j = inorderVal.size() - 1;

        while(i < j){
            int sum = inorderVal[i] + inorderVal[j];
            if(sum == target){
                return true;
            }
            else if(sum > target){
                j--;
            }
            else{
                i++;
            }
        }
        return false;
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

    int target;
    cout<<"enter the target value : ";
    cin>>target;

    solution sr;
    if(sr.twoSumInBST(root,target)){
        cout<<"pair sum present in BST that is Equal to target "<<endl;
    }
    else{
        cout<<"pair sum NOT pesent in BST that is Equal to target "<<endl;
    }

    return 0;
}