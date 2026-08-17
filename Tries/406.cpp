
class TrieNode{

    public: 
        char data;
        bool isTerminal;
        TrieNode* children[26];

        TrieNode(char ch){
            data = ch;
            for(int i=0; i< 26; i++){
                children[i] =NULL;
            }
            isTerminal = false;
        }

};

class Solution {
  public:
  
    void insert(string &word, TrieNode* root){

        TrieNode* curr = root;

        for(char ch: word){
            int index = ch - 'a';

            if(curr->children[index] == NULL){
                curr->children[index] = new TrieNode(ch);
            }

            curr = curr->children[index];
        }

        curr->isTerminal = true;
    }
    
    
    void dfs(TrieNode* curr, string prefix, vector<string>& temp){
        
        if(curr->isTerminal){
            temp.push_back(prefix);
        }
        for(int i = 0; i < 26; i++){

            if(curr->children[i]){

                char ch = 'a' + i;

                dfs(curr->children[i], prefix + ch, temp);
            }
        }
        
        
        
    }
    
  
    vector<vector<string>> displayContacts(vector<string> contact, string s) {

        // code here
        
        TrieNode* root = new TrieNode('\0');
        
        for(string ele: contact){
            insert(ele,root);
        }
        
        
        vector<vector<string>> ans;
        TrieNode* curr = root;
        string prefix = "";
        bool found = true;
        for(char ch : s){

            prefix += ch;
            if(!found){
                ans.push_back({"0"});
                continue;
            }

            int index = ch - 'a';

            if(curr->children[index] == NULL){
                ans.push_back({"0"});
                found = false;
                continue;
            }

            curr = curr->children[index];

            // curr = Trie node corresponding to prefix
            vector<string> temp;
            dfs(curr,prefix,temp);
            ans.push_back(temp);
        }
        return ans;
        
        
        
    }
};