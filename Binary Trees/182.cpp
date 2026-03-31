#include<bits/stdc++.h>
using namespace std;


class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};


class Solution {
  public:
  
    void inorderTraversal(Node* root, vector<int>&ans){
        
        stack<Node*> s;
        
        Node* curr = root;
        
        while(!s.empty() || curr !=NULL ){
            if(curr != NULL){
                s.push(curr);
                curr = curr->left;
            }
            else{
                Node* temp = s.top();
                s.pop();
                ans.push_back(temp->data);
                curr = temp->right;
            }
        }
        
    }
  
    vector<int> inOrder(Node* root) {
        // code here
        vector<int> ans;
        inorderTraversal(root,ans);
        return ans;
    }
};