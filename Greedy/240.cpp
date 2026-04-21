#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
  
    struct Node{
        int freq;
        char ch;
        Node* left;
        int idx;
        Node* right;
        
        Node( char c , int f, int i){
        ch = c;
        idx = i;
        freq = f;
        left = right = NULL;
    }
    };
    
    struct cmp{
    bool operator()(Node* a, Node* b){
        if(a->freq == b->freq)
            return a->idx > b->idx;

        return a->freq > b->freq;
    }
};
    
    vector<string> ans;
    
    void huffManEncode(Node* root, string s){
        if(!root->left && !root->right){
            ans.push_back(s);
            return;
        }
        
        //left
        huffManEncode(root->left,s + "0");
        //right
        huffManEncode(root->right,s + "1");
        
    }
    

    Node* buildTree(priority_queue<Node*, vector<Node*>, cmp>& pq){
        while(pq.size() > 1){
            Node* left = pq.top();pq.pop();
            Node* right = pq.top();pq.pop();
            
            Node* parent = new Node('$' , left->freq + right->freq ,min(left->idx, right->idx));
            
            parent->left = left;
            parent->right = right;
            
            pq.push(parent);
        }
        return pq.top();
    }
  
    vector<string> huffmanCodes(string &s, vector<int> f) {
        // Code here
        ans.clear();
        priority_queue<Node*, vector<Node*>, cmp> pq;
        
        //populate the min heap based on frequency
        for(int i = 0 ; i <f.size() ; i++){
            Node* temp = new Node(s[i],f[i],i);
            pq.push(temp);
        }
        
        Node* root = buildTree(pq); // helper function to build tree
        
        if(!root->left && !root->right){
            ans.push_back("0");
            return ans;
        }
        
        huffManEncode(root, "");
        
        
        return ans;
        
        
        
    }
};