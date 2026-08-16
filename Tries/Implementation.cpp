#include<iostream>
using namespace std;

class TrieNode{
    public:
    int data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        data=ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;
    }
};


class Trie{
    public:
    TrieNode* root;

    Trie(){
        root=new TrieNode('\0');
    }


    //INSERTING A WORD IN A TRIE
    void insertUtil(TrieNode* root, string word){
        //base case
        if(word.length()==0){
            root->isTerminal=true;
            return;
        }
        
        //Assumption : word will be in caps
        int index = word[0] - 'A';
        TrieNode* child;

        //already present
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        //absent
        else{
            child = new TrieNode(word[0]);
            root->children[index]=child;
        }

        //RECURSION SAMBHAL LEGA
        insertUtil(child,word.substr(1));

    }

    void insertWord(string word){
        insertUtil(root,word);
    }


    //SEARCHING THE WORD IN TRIE
    bool searchUtil(TrieNode* root, string word){
        //base case
        if(word.length()==0){
            return root->isTerminal;
        }

        int index= word[0]-'A';
        TrieNode* child;

        //present
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            //absent
            return false;
        }
        return searchUtil(child,word.substr(1));

    }

    bool searchWord(string word){
        return searchUtil(root,word);
    }


    //REMOVING A WORD FROM TRIE
    //BY JUST CALLING THIS FUNCTION WE CAN REMOVE THE WORD FROM TRIE BY FALSE THE ISTERMINAL OF THE LAST CHARACTER OF THE WORD.
    bool removeUtil(TrieNode* &root, string word){
        //base case
        if(word.length()==0){
            root->isTerminal=false;
            return true;
        }

        int index= word[0]-'A';
        TrieNode* child;

        //present
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            //absent
            return false;
        }
        return removeUtil(child,word.substr(1));

    }
    void removeWord(string word){
        removeUtil(root,word);
    }
};


int main(){

    Trie *t = new Trie();
    t->insertWord("DO");
    t->insertWord("ARM");
    t->insertWord("TIME");


    if(t->searchWord("TIME")) {
        cout << "The word is present." << endl;
    } else {
        cout << "The word is not present." << endl;
    }    

    t->removeWord("TIME");
    if(t->searchWord("TIME")) {
        cout << "The word is present." << endl;
    } else {
        cout << "The word is not present." << endl;
    }

    return 0;
}