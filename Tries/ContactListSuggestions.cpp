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
        int index = word[0] - 'a';
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


    void printSuggestions(TrieNode* curr,vector<string> &temp,string prefix){
    if(curr->isTerminal){
        temp.push_back(prefix);
        //no return use
    }
    for(char ch='a';ch<='z';ch++){
        TrieNode* next=curr->children[ch-'a'];

        if(next!=NULL){
            prefix.push_back(ch);  //pushing the character beacuse we want a complete word in the suggestion
            printSuggestions(next,temp,prefix);
            prefix.pop_back(); //backtrack
        }
    }
}

    vector<vector<string>> getSuggestions(string str){
        TrieNode* prev=root;
        vector<vector<string>> output;
        string prefix="";

        for(int i=0;i<str.length();i++){
            char lastch=str[i];
            prefix.push_back(lastch);

            //check for last character
            TrieNode* curr=prev->children[lastch-'a'];

            if(curr==NULL){
                break;
            }

            vector<string> temp;
            printSuggestions(curr,temp,prefix);

            output.push_back(temp);
            temp.clear();
            prev=curr;
        }
        return output;
    }
};



vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    //    Write your code here.

    Trie* t=new Trie();

    //insert all conatct in trie
    for(int i=0;i<contactList.size();i++){
        string str=contactList[i];
        t->insertWord(str);
    }


    return t->getSuggestions(queryStr);


}