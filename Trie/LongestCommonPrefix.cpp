#include<iostream>
#include<vector>
using namespace std;

/*approah 1 iterative method*/
class solution{
    public:
    string longestCommonPrefix(vector<string> &arr,int n){

        string ans = "";
        //for traversing all the char of first string
        for(int i=0 ; i<arr[0].length() ; i++){

            char ch = arr[0][i];
            bool match = true;
            //for comapring with all string
            for(int j=1; j<n ; j++){
                //not match
                if(arr[j].size() < i || arr[j][i] != ch){
                    match = false;
                    break;
                }
            }

            if(match == false){
                break;
            }
            else{
                ans.push_back(ch);
            }
        }
        return ans;
    }
};


class trieNode{
    public:
    char ch;
    int childCount;
    trieNode* children[26];
    bool isTerminal;

    //constructor
    trieNode(char data){
        this->ch = data;
        this->childCount = 0;
        for(int i= 0 ; i<26 ; i++){
            children[i] = NULL;
        }
        this->isTerminal = false;
    }
};

class trie{
    public:
    trieNode* root;
    //constructor
    trie(){
        root = new trieNode('\0');
    }

    //inserction 
    void insertUtil(trieNode* root,string word){
        //base case
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        trieNode* child;
        if(root->children[index] != NULL){
            //present
            child = root->children[index];
        }
        else{
            //absent
            child = new trieNode(word[0]);
            root->childCount++;
            root->children[index] = child;
        }

        //recusive call
        insertUtil(child,word.substr(1));
    }

    void insertWord(string word){
        insertUtil(root,word);
    }

    void longestCommonPrefix(string str,string &ans){

        for(int i = 0 ; i<str.length() ; i++){
            char ch = str[i];

            if(root->childCount == 1){
                ans.push_back(ch);
                //move to next 
                int index = ch-'a';
                root = root->children[index];
            }
            else{
                break;
            }

            if(root->isTerminal)
            break;
        }
    }

};



int main(){
    //wrtie your test code here
    vector<string> arr = {"coding" , "codezen", "codingninja","coders"};
    solution sr;
    cout<<"longest common prefix is : "<<sr.longestCommonPrefix(arr,4)<<endl;

    trie* t = new trie();

    for(int i = 0 ; i<arr.size() ; i++){
        t->insertWord(arr[i]);
    }

    string first = arr[0];
    string ans = "";

    t->longestCommonPrefix(first,ans);
    
    cout<<"longest common prefix is : "<<ans<<endl;

    return 0;
}

