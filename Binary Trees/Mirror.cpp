
#include<bits/stdc++.h>
using namespace std;


class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};


class Solution {
  public:
    //recursive function to mirror tree
    void mirrorTree(Node* root){
        //base case
        if(root == NULL)return ;
        
        Node* temp = root->left;
        root->left = root->right;
        root->right = temp;
        
        mirrorTree(root->left);
        mirrorTree(root->right);
        
    }
  
  
    void mirror(Node* root) {
        // code here
        mirrorTree(root);
    }
};