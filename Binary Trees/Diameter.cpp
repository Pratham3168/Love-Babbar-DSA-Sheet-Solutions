#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

class Solution {
    public:
      // Function to return the diameter of a Binary Tree.
      
      pair<int,int> diameterFast(Node* root) {

        //base case of recursion
        if(root==NULL){
            pair<int,int> p = make_pair(0,0);
            return p;
        }


        pair<int,int> left = diameterFast(root->left);
        pair<int,int> right = diameterFast(root->right);


        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second + 1;

        pair<int,int> ans;
        ans.first = max(op1,max(op2,op3));
        ans.second = max(left.second , right.second) + 1;

        return ans;

      }
};

int main(){
 // Manually creating tree

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->left->left->left = new Node(7);

    root->right->right = new Node(6);

    Solution obj;
    pair<int,int> result = obj.diameterFast(root);

    cout << "Diameter (nodes): " << result.first << endl;
    cout << "Diameter (edges): " << result.first - 1 << endl;

    return 0;
}