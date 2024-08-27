#include<iostream>
#include<vector>
using namespace std;

class trieNode{
    public:
    char ch;
    trieNode* children[26];
    bool isTreminal;

    //constructor
    trieNode(char data){
        this->ch = data;
        for(int i = 0 ; i<26 ; i++){
            children[i] = NULL;
        }
        this->isTreminal = false;
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
            root->isTreminal = true;
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
            root->children[index] = child;
        }

        //recursive call
        insertUtil(child,word.substr(1));
    }

    void insertWord(string word){
        insertUtil(root,word);
    }

    void display(trieNode* root,char str[],int level){  //method 1
        //base case
        if(root->isTreminal){
            str[level] = '\0';
            cout<<str<<endl;
        }

        for(int i = 0 ; i<26 ; i++){
            
            if(root->children[i]){
                str[level] = i+'a';
                display(root->children[i],str,level+1);
            }
        }
    }

    void print(trieNode* root,string str){ //method 2
        //base case
        if(root->isTreminal){
            cout<<str<<endl;
        }

        for(char ch = 'a'; ch <= 'z' ; ch++){

            trieNode* next = root->children[ch - 'a'];
            if(next != NULL){
                str.push_back(ch);
                print(next,str);
                str.pop_back();
            }
        }
    }
};

int main(){
    //write your test code here
    trie* t = new trie();

    vector<string> arr = {"coding","codeingninja","codezen","coders","cod"};
    for(int i = 0; i<arr.size(); i++){
        t->insertWord(arr[i]);
    }

    int level = 0;
    char str[20];
    t->display(t->root,str,level);

    cout<<endl;
    string ans = "";
    t->print(t->root,ans);
    return 0;
}