class TrieNode{
    public:
        int data;
        TrieNode* children[2];
        bool isTerminal;
        
        TrieNode(int num){
            data = num;
            children[0] = NULL;
            children[1] = NULL;
            isTerminal = false;
        }
};

class Solution {
  public:
    vector<vector<int>> uniqueRow(vector<vector<int>>& mat) {
        // code here
        
        TrieNode* root = new TrieNode(-1);
        vector<vector<int>> ans;
        
        for(int i =0; i< mat.size() ;i ++){
            
            bool isUnique = false;
            //start iterating over the trie
            TrieNode* curr = root;
            for(int j =0; j < mat[i].size(); j++){
                int idx = mat[i][j];
                if(curr->children[idx] != NULL){
                    curr = curr->children[idx];
                }
                else{
                    isUnique = true;
                    TrieNode* child = new TrieNode(idx);
                    curr->children[idx] = child;
                    curr = child;
                }
            }
            if(isUnique){
                ans.push_back(mat[i]);
            }
            
        }
        
        return ans;
    }
};