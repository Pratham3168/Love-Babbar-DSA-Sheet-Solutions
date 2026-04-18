// /* The structure of the binary tree is as follows
// struct Node
// {
//     int data;
//     Node* left;
//     Node* right;
// };
// */

// class Solution {
//   public:
  
//     int leafLevel = -1;
    
//     bool solve(Node* root,int level){
        
//         //base case
//         if(root == NULL)return true;
        
//         if(!root->left && !root->right){
//             if(leafLevel == -1){
//                 leafLevel = level;
//                 return true;
//             }
//             return leafLevel == level;
//         }
        
//         return solve(root->left,level+1)&&solve(root->right,level+1);
        
//     }
  
//     /*You are required to complete this method*/
//     bool check(Node *root) {
//         // Your code here
//         return solve(root,0);
//     }
// };