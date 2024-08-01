#include<iostream>
#include<vector>
#include<map>
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

//building tree
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

//printing binary tree using level order trversal 
void levelOrderTraversal(Node* root){

    queue<Node*> q;
    q.push(root);
    q.push(NULL); //null is used as seperator

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

class solution{

    public:
    //function to return a list containing the bottom view of the given tree
    vector<int> bottomView(Node* root){

        vector<int> ans;
        if(root == NULL){
            return ans;
        }

        //create a map to link horizontal distance to node data
        map<int ,int> bottomNode;
        queue<pair<Node*,int>> q;
        q.push(make_pair(root,0));

        while(!q.empty()){
            pair<Node* ,int> temp = q.front();
            q.pop();

            Node* frontNode = temp.first;
            int hd = temp.second;

            //entry in map
            bottomNode[hd] = frontNode->data;

            if(frontNode->left){
                q.push(make_pair(frontNode->left,hd-1));
            }

            if(frontNode->right){
                q.push(make_pair(frontNode->right,hd+1));
            }
        }

        //map se answer nekal lo
        for(auto i:bottomNode){
            ans.push_back(i.second);
        }

        return ans;
    }
};

int main(){
    //write your test case here 
    Node* root = NULL;
    buildFromLevelOrder(root);

    cout<<"printing the tree : "<<endl;
    levelOrderTraversal(root);

    solution s;
    vector<int> ans = s.bottomView(root);
    for(int i=0 ; i < ans.size() ; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}