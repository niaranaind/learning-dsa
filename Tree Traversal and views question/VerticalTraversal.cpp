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

Node* buildTree(Node* root){

    cout<<"enter the data: "<<endl;
    int data;
    cin>>data;
    root = new Node(data);

    //base case
    if(data == -1){
        return NULL;
    }

    cout<<"enter the data for left of : "<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"enter the data for right of : "<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}

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
    //function to find the vertical order trversal of binary tree
    vector<int> verticalOrder(Node* root){
        //create map for mapping horizontal distance to level wise node
        map<int,map<int,vector<int>>> nodes;

        queue<pair<Node*,pair<int,int>>> q;
        //ans vector
        vector<int> ans;
        if(root == NULL){
            return ans;
        }

        q.push(make_pair(root,make_pair(0,0)));
        
        while(!q.empty()){
            pair<Node*,pair<int,int>> temp = q.front();
            q.pop();

            Node* frontNode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;

            //entry in the map (hd -> level wise node)
            nodes[hd][lvl].push_back(frontNode->data);

            if(frontNode->left){
                q.push(make_pair(frontNode->left,make_pair(hd-1,lvl+1)));
            }

            if(frontNode->right){
                q.push(make_pair(frontNode->right,make_pair(hd+1,lvl+1)));
            }
        }

        //map se answer nekal lo
        for(auto i:nodes){

            for(auto j:i.second){

                for(auto k:j.second){

                    ans.push_back(k);
                }
            }
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
    vector<int> ans = s.verticalOrder(root);

    for(int i=0 ;i < ans.size();i++ ){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}