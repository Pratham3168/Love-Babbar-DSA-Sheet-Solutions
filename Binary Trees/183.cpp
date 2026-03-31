#include<bits/stdc++.h>
using namespace std;


class Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution {
  public:
  
    // preorder ->   ROOT->LEFT->RIGHT
  
    //recursive approach
    void preOrderTraversalRecursion(Node* root, vector<int> &ans){
        //base case
        if(root == NULL){
            return ;
        }
        
        ans.push_back(root->data);
        preOrderTraversalRecursion(root->left,ans);
        preOrderTraversalRecursion(root->right,ans);
    }
    
    
    //iterative approach
    void preOrderTraversalIterative(Node* root, vector<int> &ans){
        
        stack<Node*> s;
        
        s.push(root);
        
        while(!s.empty()){
            
            Node* temp = s.top();
            s.pop();
            
            ans.push_back(temp->data);
            
            
            //since we want left to print first , so we push right before left
            // as we know stack is LIFO
            if(temp->right){ 
                s.push(temp->right);
            }
            if(temp->left){
                s.push(temp->left);
            }
            
        }
        
    }
  
    vector<int> preOrder(Node* root) {
        // code here
        vector<int> ans;
        // preOrderTraversalRecursion(root,ans);
        preOrderTraversalIterative(root,ans);
        return ans;
    }
};