#include <bits/stdc++.h>
using namespace std;


class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};


class Solution {
  public:
  
  
    Node* merge(Node* down, Node* right){
        
        if(down == NULL)return right;
        if(right == NULL) return down;
        
        Node* ans = new Node(-1);
        Node* temp = ans;
        
        while(down!=NULL && right!=NULL){
            
            if(down->data < right->data){
                temp->bottom = down;
                temp = down;
                down = down->bottom;
            }else{
                temp->bottom = right;
                temp = right;
                right = right->bottom;
            }
            
        }
        
        while(down!=NULL){
            temp->bottom = down;
            temp = down;
            down = down->bottom;
        }
        while(right!=NULL){
            temp->bottom = right;
            temp = right;
            right = right->bottom;
        }
        
        ans = ans->bottom;
        return ans;
        
        
    }
  
  
    Node *flatten(Node *root) {
        // code here
        if(root == NULL || root ->next == NULL) return root;
        
        Node* right = flatten(root->next);
        
        root->next = NULL;
        
        Node* ans = merge(root,right);
        
        return ans;
    }
};