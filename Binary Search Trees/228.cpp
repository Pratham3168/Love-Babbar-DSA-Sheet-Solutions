// /* The Node structure is
// struct Node
// {
//     int data;
//     struct Node *left;
//     struct Node *right;

//     Node(int val) {
//         data = val;
//         left = right = NULL;
//     }
// };
// */

// class Solution {
//   public:
  
//     vector<int> inOrder;
//     int i = 0;
    
    
//     void solve(Node* root){
//         if(root == NULL)return;
        
//         solve(root->left);
//         root->data = inOrder[i++];
//         solve(root->right);
//     }
    
    
//     //build the inorder array
//     void getInorder(Node* root){
//         if(root == NULL)return;
        
//         getInorder(root->left);
//         //add to vector
//         inOrder.push_back(root->data);
//         getInorder(root->right);
//     }
  
//     // The given root is the root of the Binary Tree
//     // Return the root of the generated BST
//     Node *binaryTreeToBST(Node *root) {
//         // Your code goes here
//         getInorder(root);
        
//         sort(inOrder.begin(),inOrder.end());
        
//         solve(root);
//         return root;
//     }
// };