#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


#include<bits/stdc++.h>

class Solution {
  public:
  
    //recursive function to calculate height easity
    int calculateHeight(Node* root){
        //base case
        if(root == NULL)return 0;
        
        int leftHeight = calculateHeight(root->left);
        int rightHeight = calculateHeight(root->right);
        
        int ans = max(leftHeight,rightHeight)+1;
        
        return ans;
    }
  
    int height(Node* root) {
        // code here
        return calculateHeight(root)-1;
    }
};