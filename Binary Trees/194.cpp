// /* Structure for tree and linked list
// class Node {
//   public:
//     int data;
//     Node* left;
//     Node* right;

//     Node()
//         : data(0)
//         , left(NULL)
//         , right(NULL) {}

//     Node(int x)
//         : data(x)
//         , left(NULL)
//         , right(NULL) {}
// };
//  */

// // This function should return head to the DLL
// class Solution {
//   public:
  
//     Node* prev = NULL;
//     Node* head = NULL;
    
//     void solve(Node* root){
//         if(root == NULL)return;
        
//         solve(root->left);
        
//         //linking is done here
//         if(prev == NULL){
//             head = root;
//         }
//         else{
//             prev->right = root;
//             root->left = prev;
//         }
//         prev = root;
        
//         solve(root->right);
//     }
  
//     Node* bToDLL(Node* root) {
//         // code here
//         solve(root);
//         return head;
        
//     }
// };