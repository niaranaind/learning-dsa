#include<iostream>
#include<queue>
#include<vector>
#include<map>
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

void buildFromLevelOrder(Node* &root){

    cout<<"enter the data : "<<endl;
    queue<Node*> q;
    int data;
    cin>> data;
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

void levelOrderTraversal(Node* root){

    queue<Node*> q;
    q.push(root);
    q.push(NULL);//null is used as sperator

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

class solution{
    public:
    //function to return list of node visible from top view
    vector<int> topView(Node* root){

        vector<int> ans;
        if(root == NULL){
            return ans;
        }

        //map to link horizontal distance to node data
        map<int ,int> topNode;
        queue<pair<Node*,int>> q;
        q.push(make_pair(root,0));

        while(!q.empty()){
            pair<Node*,int> temp = q.front();
            q.pop();
            
            Node* frontNode = temp.first;
            int hd = temp.second;

            //entry in map and note that there should be one to one mapping
            if(topNode.find(hd) == topNode.end()){
                topNode[hd] = frontNode->data;
            }

            if(frontNode->left){
                q.push(make_pair(frontNode->left,hd-1));
            }

            if(frontNode->right){
                q.push(make_pair(frontNode->right,hd+1));
            }
        }

        //map se answer nekal lo
        for(auto i:topNode){
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
    vector<int> ans = s.topView(root);

    for(int i = 0 ; i < ans.size() ; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}