#include<iostream>
using namespace std;

class trieNode{
    public:
    char data;
    trieNode* children[26];
    bool isTerminal;

    //constructor
    trieNode(char data){
        this->data = data;
        for(int i = 0; i<26 ; i++){
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

    //insertion
    void insertUtil(trieNode* root, string word){
        //base case
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }
        //assumping word will be capital
        int index = word[0] - 'A';
        trieNode* child;

        if(root->children[index] != NULL){
            //char is present
            child = root->children[index];
        }
        else{ //absent
            child = new trieNode(word[0]);
            root->children[index] = child;
        }

        //recusive call
        insertUtil(child,word.substr(1));
    }

    void insertWord(string word){
        insertUtil(root,word);
    }

    //search 
    bool searchUtil(trieNode* root,string word){
        //base case
        if(word.length() == 0){
            return root->isTerminal;
        }

        int index = word[0] - 'A';
        trieNode* child;

        if(root->children[index] != NULL){
            //present
            child = root->children[index];
        }
        else{
            //absent;
            return false;
        }

        return searchUtil(child,word.substr(1));
    }

    bool serchWord(string word){
        return searchUtil(root,word);
    }
};

int main(){
    //write your test code here
    trie* t = new trie();

    t->insertWord("ARM");
    t->insertWord("DO");
    t->insertWord("TIME");

    cout<<"word is  present or NOT : "<<t->serchWord("TIME")<<endl;

    return 0 ; 
}