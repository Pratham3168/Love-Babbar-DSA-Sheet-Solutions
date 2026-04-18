// /*
// class Node {
// public:
//     int data;
//     Node* left;
//     Node* right;

//     Node(int x) {
//         data = x;
//         left = right = NULL;
//     }
// };
// */

// class Solution {
//   public:
  
//     int n11 = 0;
//     int n22 = 0;
  
//     Node* solve(Node* root){
//         //base case
//         if(root == NULL)return NULL;
        
//         if(root->data == n11 || root->data == n22 ){
//             return root;
//         }
        
//         Node* left = solve(root->left);
//         Node* right = solve(root->right);
        
//         if(left && right){
//             return root;
//         }
        
//         return left ? left: right;
//     }
  
//     Node* lca(Node* root, int n1, int n2) {
//         //  code here
//         n11 = n1;
//         n22 = n2;
        
//         return solve(root);
        
//     }
// };