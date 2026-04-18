// /* A binary tree node
// struct Node
// {
//     int data;
//     Node* left, * right;
// }; */

// class Solution {
//   public:
  
//     //using recursion
//     int solve(Node* root){
//         //base case
//         if(root == NULL)return 0;
        
//         int temp = root->data;
//         root->data = solve(root->left) + solve(root->right);
        
//         return root->data + temp;
//     }
  

//     // Convert a given tree to a tree where every node contains sum of values of
//     // nodes in left and right subtrees in the original tree
//     void toSumTree(Node *root) {
//         // Your code here
//         if(!root->left && !root->right)return ;
        
//         solve(root);
//     }
// };