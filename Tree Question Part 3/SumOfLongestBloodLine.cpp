#include<iostream>
#include<vector>
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

//buildine tree using level order traversal
void buildFromLevelOrder(Node* &root){

    queue<Node*> q;
    cout<<"enter the data : "<<endl;
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
            //previous level is traversed
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
    private:
    void solve(Node* root,int sum,int &maxSum ,int len, int &maxLen){
        //base case
        if(root == NULL){

            if(len > maxLen){
                maxLen = len;
                maxSum = sum;
            }
            else if(len == maxLen){
                maxSum = max(sum,maxSum);
            }

            return ;
        }

        sum = sum + root->data;

        //left and right recursive call
        solve(root->left , sum,maxSum,len+1,maxLen);
        solve(root->right ,sum,maxSum,len+1,maxLen);
    }
    
    public:
    int sumOfLongRootToLeafPath(Node* root){

        int sum = 0;
        int maxSum = 0;
        int len = 0;
        int maxLen = 0;
        solve(root,sum,maxSum,len,maxLen);

        return maxSum;
    }
};

class solution2{

    private:
    void solve(Node* root,int sum,int len,pair<int,int> &ans){

        //base case 
        if(root == NULL){
            return;
        }

        if(root->left == NULL && root->right == NULL){
            sum = sum+root->data;

            if(len > ans.second){
                ans.first = sum;
                ans.second = len;
            }
            else if(len == ans.second){
                ans.first = max(ans.first,sum);
            }
            return;
        }

        sum = sum+root->data;
        //left and right recursive call
        solve(root->left,sum,len+1,ans);
        solve(root->right,sum,len+1,ans);
    }

    public:
    int sumOfLongRootToLeafPath(Node* root){

        pair<int,int> ans = make_pair(0,0);
        int len = 1;
        int sum = 0;
        solve(root ,sum,len,ans);
        return ans.first;
    }

};

int main(){

    //write your test case here
    Node* root = NULL;
    buildFromLevelOrder(root);

    cout<<"printing binary tree "<<endl;
    levelOrderTraversal(root);

    solution s;
    cout<<"sum all node on the longest part is: "<<s.sumOfLongRootToLeafPath(root)<<endl;

    solution s2;
    cout<<"sum of all node on the longest part is: "<<s2.sumOfLongRootToLeafPath(root)<<endl;

    return 0;
}