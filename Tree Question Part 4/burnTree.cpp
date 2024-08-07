#include<iostream>
#include<queue>
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

//building tree using level order traversal
void builFromLevelOrder(Node* &root){

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

//printing binary tree using level order traversal
void levelOrderTraversal(Node* root){

    queue<Node*> q;
    q.push(root);
    q.push(NULL); //null is used as seperator

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            //previous level traversal is complete
            cout<<endl;
            if(!q.empty()){
                //queue has some child element
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
    private:
    Node* createParentMapping(Node* root,int target,map<Node*,Node*> &nodeToParent){

        queue<Node*> q;
        q.push(root);
        Node* result = NULL;
        nodeToParent[root] = NULL;

        while(!q.empty()){
            Node* frontNode = q.front();
            q.pop();

            if(frontNode->data == target){
                result = frontNode;
            }

            if(frontNode->left){
                nodeToParent[frontNode->left] = frontNode;
                q.push(frontNode->left);
            }

            if(frontNode->right){
                nodeToParent[frontNode->right] = frontNode;
                q.push(frontNode->right);
            }
        }
        return result;
    }

    int burnTree(Node* root,map<Node*,Node*> &nodeToParent){

        //creating map to track visit of node
        map<Node*,bool> visited;

        queue<Node*> q;
        q.push(root);
        visited[root] = true;
        int ans = 0;

        while(!q.empty()){

            int size = q.size();
            int flag = false;

            for(int i=0 ; i<size ; i++){
                //prosessing neighbouring nodes
                Node* front = q.front();
                q.pop();

                if(front->left && !visited[front->left]){
                    flag = true;
                    q.push(front->left);
                    visited[front->left] = true;
                }

                if(front->right && !visited[front->right]){
                    flag = true;
                    q.push(front->right);
                    visited[front->right] = true;
                }

                if(nodeToParent[front] && !visited[nodeToParent[front]]){
                    flag = true;
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]] = true;
                }
            }
            if(flag == true){
                ans++;
            }
        }
        return ans;
    }

    public:
    int minTime(Node* root,int target){

        //algo:-
        //create a mapping nodeToParent
        //find the target node
        //burn the tree and fin min time
        map<Node*,Node*> nodeToParent;
        Node* targetNode = createParentMapping(root,target,nodeToParent);
        int ans = burnTree(targetNode,nodeToParent);
        return ans;
    }
};

int main(){
    //write your test case here

    Node* root = NULL;
    builFromLevelOrder(root);

    cout<<"print binary tree : "<<endl;
    levelOrderTraversal(root);

    solution s;
    cout<<"minimum time to burn a tree : "<<s.minTime(root,8);
    return 0;
}