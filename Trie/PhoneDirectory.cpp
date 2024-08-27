#include<iostream>
#include<vector>
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
        isTerminal = false;
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
        else{//absent
            child = new trieNode(word[0]);
            root->children[index] = child;
        }

        //recursive call
        insertUtil(child,word.substr(1));
    }

    void insertWord(string word){
        insertUtil(root,word);
    }

    void printSuggestion(trieNode* curr,vector<string> &temp,string prefix){
        //base case
        if(curr->isTerminal){
            temp.push_back(prefix);
        }

        for(char ch = 'a' ; ch<='z' ; ch++){

            trieNode* next = curr->children[ch-'a'];
            if(next != NULL){
                prefix.push_back(ch);
                printSuggestion(next,temp,prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getSuggestions(string str){

        trieNode* prev = root;
        vector<vector<string >> output;
        string prefix = "";

        for(int i = 0 ; i<str.length() ; i++){
            char lastChar = str[i];
            prefix.push_back(lastChar);

            //check last char is present
            trieNode* curr = prev->children[lastChar - 'a'];
            //if not found
            if(curr == NULL){
                break;
            }

            //if found
            vector<string> temp;
            printSuggestion(curr,temp,prefix);
            output.push_back(temp);
            temp.clear();
            prev = curr;
        }

        return output;
    }

};

vector<vector<string>> phoneDirectory(vector<string> &contactList, string &queryStr){

    trie* t = new trie();
    for(int i = 0 ; i<contactList.size() ; i++){
        t->insertWord(contactList[i]);
    }

    return t->getSuggestions(queryStr);
}