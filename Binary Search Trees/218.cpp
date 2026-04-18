// /*
// class Node {
// public:
//     int data;
//     Node* left;
//     Node* right;

//     Node(int val) {
//         data = val;
//         left = right = nullptr;
//     }
// };
// */

// class Solution {
//   public:
  
//     bool solve(Node* root, int minAllowed , int maxAllowed){
//         //base case
//         if(root == NULL)return true;
        
//         if(root->data <= minAllowed || root->data >= maxAllowed){
//             return false;
//         }
        
//         return solve(root->left,minAllowed,root->data) &&
//                 solve(root->right,root->data,maxAllowed);
//     }
  
//     bool isBST(Node* root) {
//         // code here
//         return solve(root,INT_MIN,INT_MAX);
//     }
// };