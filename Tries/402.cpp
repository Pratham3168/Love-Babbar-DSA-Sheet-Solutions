class TrieNode {
	public:
	int data;
	TrieNode* children[26];
	bool isTerminal;
	
	TrieNode(char ch) {
		data = ch;
		for (int i = 0; i<26; i++) {
			children[i] = NULL;
		}
		isTerminal = false;
	}
};

class Trie {
	public:
	TrieNode* root;
	
	Trie() {
		// implement Trie
		root = new TrieNode('\0');
	}
	
	void insert(string &word) {
		// insert word into Trie
		TrieNode* r = root;
		
		for (int i = 0; i<word.length() ; i++) {
			
			int index = word[i] - 'a';
			TrieNode* child;
			
			if (r->children[index] != NULL) {
				child = r->children[index];
			}
			else {
				child = new TrieNode(word[i]);
				r->children[index] = child;
			}
			
			r = child;
			
		}
		r->isTerminal = true;
	}
	
	bool search(string &word) {
		// search word in the Trie
		
		TrieNode* r = root;
		
		for (int i = 0; i<word.length() ; i++) {
			int index = word[i] - 'a';
			
			if (r->children[index] == NULL) {
				return false;
			}
			
			r = r->children[index];
			
		}
		
		return r->isTerminal;
		
	}
	
	bool isPrefix(string &word) {
		// search prefix word in the Trie
		TrieNode* r = root;
		
		for (int i = 0; i < word.length(); i++) {
			
			int index = word[i] - 'a';
			
			// Character doesn't exist
			if (r->children[index] == NULL) {
				return false;
			}
			
			// Move to next node
			r = r->children[index];
		}
		
		// All characters of prefix were found
		return true;
	}
};
