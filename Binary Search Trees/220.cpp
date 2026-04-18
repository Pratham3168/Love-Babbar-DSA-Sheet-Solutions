// /*
// class Node {
//   public:
//     int data;
//     Node* left;
//     Node* right;

//     Node(int val) {
//         data = val;
//         left = NULL;
//         right = NULL;
//     }
// };
// */

// class Solution {
//   public:
  
//     Node* n11 = NULL;
//     Node* n22 = NULL;
  
//     Node* solve(Node* root){
//         //base case
//         if(root == NULL)return NULL;
        
//         //if both nodes are smaller than root
//         //go left
//         if(n11->data < root->data && n22->data < root->data){
//             return solve(root->left);
//         }
//         //if both nodes are greater than root
//         //go right
//         else if(n11->data > root->data && n22->data > root->data){
//             return solve(root->right);
//         }
//         //else 
//         //current is lca
//         return root;
//     }
  
//     Node* LCA(Node* root, Node* n1, Node* n2) {
//         // code here
//         n11 = n1;
//         n22 = n2;
        
//         return solve(root);
        
//     }
// };