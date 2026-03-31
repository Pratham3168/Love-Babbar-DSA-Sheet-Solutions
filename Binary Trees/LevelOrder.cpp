#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


class Solution {
  public:
    vector<vector<int>> levelOrder(Node *root) {
        // code here
        
        //======APPROACH : 1=============
        // queue<Node*> q;
        // q.push(root);
        // q.push(NULL);
        // vector<int> tempArray;
        // vector<vector<int>> ans;
        // while(!q.empty()){
        //     Node* temp = q.front();
        //     q.pop();
            
        //     if(temp==NULL){
        //         ans.push_back(tempArray);
        //         tempArray.clear();
        //         // 🔑 KEY FIX
        //         if(!q.empty()){
        //             q.push(NULL);
        //         }
        //     }
        //     else{
        //         tempArray.push_back(temp->data);
        //         if(temp->left){
        //             q.push(temp->left);
        //         }
        //         if(temp->right){
        //             q.push(temp->right);
        //         }
        //     }
        // }
        // return ans;
        
        
        
        
        
        
        //=======APPROACH: 2==========
        // vector<vector<int>> ans;
        // if(root == NULL) return ans;
    
        // queue<Node*> q;
        // q.push(root);
    
        // while(!q.empty()){
        //     int size = q.size();
        //     vector<int> level;
    
        //     for(int i = 0; i < size; i++){
        //         Node* temp = q.front();
        //         q.pop();
    
        //         level.push_back(temp->data);
    
        //         if(temp->left) q.push(temp->left);
        //         if(temp->right) q.push(temp->right);
        //     }
    
        //     ans.push_back(level);
        // }
    
        // return ans;
    }
};