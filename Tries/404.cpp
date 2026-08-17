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
    
    
    bool canBreak(int i, string &word, TrieNode* root,vector<int> &dp){
        
        if(i == word.length()){
            return true;
        }
        
        if(dp[i] != -1){
            return dp[i];
        }
        
        TrieNode* curr = root;
        
        for(int k = i; k < word.length() ; k++){
            
            int index = word[k] - 'a';
            
            TrieNode* child = curr->children[index];
            
            if(!child){
                break;
            }
            
            curr = curr->children[index];
            if(curr->isTerminal == true){
                if(canBreak(k+1,word,root,dp)){
                    return dp[i] = 1;
                }
            }
            
        }
        
        return dp[i] = 0;
    }
    
    
  
    bool wordBreak(string &s, vector<string> &dictionary) {
        // code here
        
        TrieNode* root = new TrieNode('\0');
        vector<int> dp(s.length(),-1);
        
        for(string ele: dictionary){
            insert(ele,root);
        }
        
        bool ans = canBreak(0,s,root,dp);
        
        return ans;
        
        
        
    }
};