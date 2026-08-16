class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    int count;

    TrieNode(char ch) {
        data = ch;

        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }

        isTerminal = false;
        count = 0;
    }
};

class Solution {
  public:
    
    int calculateCount(TrieNode* node) {

        int count = 0;

        // If a word ends at this node, it contributes 1
        if (node->isTerminal) {
            count = 1;
        }

        // Add counts returned by all children
        for (int i = 0; i < 26; i++) {

            if (node->children[i] != NULL) {
                count += calculateCount(node->children[i]);
            }
        }

        node->count = count;

        return count;
    }
  
  
    void insert(TrieNode* root, string &word) {

        TrieNode* curr = root;

        for (char ch : word) {

            int index = ch - 'a';

            if (curr->children[index] == NULL) {
                curr->children[index] = new TrieNode(ch);
            }

            curr = curr->children[index];
        }

        curr->isTerminal = true;
    }
    
    string getPrefix(TrieNode* root, string &word) {

        TrieNode* curr = root;

        string prefix = "";

        for (char ch : word) {

            int index = ch - 'a';

            curr = curr->children[index];

            prefix += ch;

            // Only one word passes through this node
            if (curr->count == 1) {
                break;
            }
        }

        return prefix;
    }
  
    vector<string> findPrefixes(vector<string>& arr) {
        // code here
        
        TrieNode* root = new TrieNode('\0');

        // Step 1: Build Trie
        for (string &word : arr) {
            insert(root, word);
        }

        // Step 2: Calculate count of words
        // passing through every node
        calculateCount(root);

        // Step 3: Find shortest unique prefix
        vector<string> ans;

        for (string &word : arr) {
            ans.push_back(getPrefix(root, word));
        }

        return ans;
    }
};