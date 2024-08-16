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

/*------------------------------------------------------------Merge two BST-----------------------------------------*/
class solution{
    private:
    void inorder(Node* root,vector<int> &in){
        //base case
        if(root == NULL){
            return;
        }
        //LNR
        inorder(root->left,in);
        in.push_back(root->data);
        inorder(root->right,in);
    }

    vector<int> mergeArray(vector<int> &a,vector<int> &b){

        int i = 0;
        int j = 0;
        int k = 0;
        vector<int> ans(a.size() + b.size());

        while( i < a.size() && j < b.size()){

            if(a[i] < b[j]){
                ans[k++] = a[i];
                i++;
            }
            else{
                ans[k++] = b[j];
                j++;
            }
        }

        while( i < a.size()){
            ans[k++] = a[i];
            i++;
        }

        while( j < b.size()){
            ans[k++] = b[j];
            j++;
        }

        return ans;
    }

    Node* inorderToBST(vector<int> &in,int s,int e){

        //base case
        if(s > e){
            return NULL;
        }

        int mid = (s+e)/2;
        Node* root = new Node(in[mid]);

        //recursive call
        root->left = inorderToBST(in,s,mid-1);
        root->right  = inorderToBST(in,mid+1,e);

        return root;
    }

    public:
    Node* mergeBST(Node* root1,Node* root2){

        vector<int> bst1,bst2;

        inorder(root1,bst1);
        inorder(root2,bst2);

        //step 2: merge two sorted array
        vector<int> mergeArr = mergeArray(bst1,bst2);

        //step 3: use merge inorder array to build BST
        int s = 0;
        int e = mergeArr.size() - 1;
        return inorderToBST(mergeArr,s,e);

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
    Node* root1 = NULL;
    Node* root2 = NULL;

    cout<<"Enter data to create BST 1 : "<<endl;
    takeInput(root1);
    cout<<"printing the BST : "<<endl;
    levelOrderTraversal(root1);

    cout<<endl;

    cout<<"Enter data to create BST 2 : "<<endl;
    takeInput(root2);
    cout<<"printing the BST : "<<endl;
    levelOrderTraversal(root2);

    cout<<endl;

    solution sr;
    Node* root3 = sr.mergeBST(root1,root2);
    cout<<"Merge BST is as follow : "<<endl;
    levelOrderTraversal(root3);

    return 0;
}