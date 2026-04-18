// /*The Node structure is
// class Node
// {
//     int data;
//     struct Node *left;
//     struct Node *right;

//     Node(int x){
//         data = x;
//         left = NULL;
//         right = NULL;
//     }
// };*/

// class Solution {
//   public:
  
//     //using ranges recursively
//     bool solve(Node* root, int minAllowed, int maxAllowed){
//         //base case
//         if(root == NULL)return false;
        
//         bool ans = false;
//         bool left = false;
//         bool right = false;
//         if(!root->left && !root->right){
//             ans =  root->data+1 > maxAllowed &&
//                     root->data-1 < minAllowed;
//         }
//         else{
//             left = solve(root->left,minAllowed,root->data-1);
//             right = solve(root->right,root->data+1,maxAllowed);
//         }
        
//         return (ans || left || right);
//     }
  
  
//     bool isDeadEnd(Node *root) {
//         // Code here
//         return solve(root,1,INT_MAX);
        
//     }
// };