#include<iostream>
using namespace std;

class trieNode{
    public:
    char ch;
    trieNode* children[26];
    bool isTerminal;
    
    //constructor
    trieNode(char data){
        this->ch = data;
        for(int i = 0 ; i<26 ; i++){
            children[i] = NULL;
        }
        this->isTerminal = false;
    }
};

class Trie{
    public:
    trieNode* root;
    //constructor
    Trie(){
        root = new trieNode('\0');
    }

    //inserction
    void insertUtil(trieNode* root,string word){
        //base case
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'A';
        trieNode* child;
        if(root->children[index] != NULL){
            //present
            child = root->children[index];
        }
        else{
            //absent
            child  = new trieNode(word[0]);
            root->children[index] = child;
        }

        //Recursion
        insertUtil(child,word.substr(1));
    }

    void insertWord(string word){
        insertUtil(root,word);
    }

    //serach in trie
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
            //absent
            return false;
        }

        //recursion
        return searchUtil(child,word.substr(1));
    }

    bool serachWord(string word){
        return searchUtil(root,word);
    }

    bool isEmpty(trieNode* root)
    {
        for (int i = 0; i < 26; i++)
            if (root->children[i])
                return false;
        return true;
    }

    trieNode* removeUtil(trieNode* root,string word ,int depth){
        //base case
        if(root == NULL){
            return NULL;
        }
        
        if(depth == word.length()){

            //terminal is present or not
            if(root->isTerminal){
                root->isTerminal = false;
            }

            //root have child or not
            if(isEmpty(root)){
                delete root;
                root = NULL;
            }

            return root;
        }

        int index = word[depth] - 'A';
        root->children[index] = removeUtil(root->children[index],word,depth+1);

        if(isEmpty(root) && root->isTerminal == false){
            delete root;
            root = NULL;
        }

        return root;
    }

    void removeWord(string word){
        root = removeUtil(root,word,0);
    }
};

int main(){
    //write your test code here
    Trie* t = new Trie();
    t->insertWord("ARM");
    t->insertWord("DO");
    t->insertWord("TIME");
    t->insertWord("TIM");

    cout<<"Present or NOT in trie data structure : "<<t->serachWord("TIM")<<endl;
    
    t->removeWord("TIM");

    cout<<"Present or NOT in trie data structure : "<<t->serachWord("TIM")<<endl;
    cout<<"Present or NOT in trie data structure : "<<t->serachWord("TIME")<<endl;

    return 0;
}