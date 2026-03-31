#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
};
class Solution {
  public:
    vector<int> reverseLevelOrder(Node *root) {
        // code here
        //======APPROACH : 1=============
        queue<Node*> q;
        q.push(root);
        vector<int> ans;
        stack<Node*> st;
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
        
            st.push(temp);
            
            if(temp->right){
                q.push(temp->right);
            }
            if(temp->left){
                q.push(temp->left);
            }
            
        }
        while(!st.empty()){
            ans.push_back(st.top()->data);
            st.pop();
        }
         
         
        return ans;
    }
};