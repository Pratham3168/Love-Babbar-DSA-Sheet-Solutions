// /*
// class Node {
//   public:
//     int data;
//     Node* left;
//     Node* right;

//     // Constructor to initialize a new node
//     Node(int val) {
//         data = val;
//         left = NULL;
//         right = NULL;
//     }
// };
// */

// class Solution {
//   public:
  
//     vector<int> ans;
  
//     void leftBoundary(Node* root){
//         if(!root)return;
//         Node* curr = root;
        
//         while(curr->left != NULL || curr->right!=NULL){
//             ans.push_back(curr->data);
//             if(curr->left){
//                 curr = curr->left;
//             }
//             else if(curr->right){
//                 curr = curr->right;
//             }
//         }
        
//     }
    
//     //full dfs traversal for leaf nodes
//     void leafNodes(Node* root){
//         if(!root) return;

//         // if leaf node → add
//         if(!root->left && !root->right) {
//             ans.push_back(root->data);
//             return;
//         }
    
//         // traverse left then right
//         leafNodes(root->left);
//         leafNodes(root->right);
//     }
    
//     void rightBoundary(Node* root){
        
//         if(!root)return;
        
//         Node* curr = root;
//         vector<int> temp;
//         while(curr->left != NULL || curr->right!=NULL){
//             temp.push_back(curr->data);
//             if(curr->right){
//                 curr = curr->right;
//             }
//             else if(curr->left){
//                 curr = curr->left;
//             }
//         }
        
//         //reverse the temp
//         reverse(temp.begin(),temp.end());
//         for(int ele:temp){
//             ans.push_back(ele);
//         }
//     }
  
//     vector<int> boundaryTraversal(Node *root) {
//         // code here
//         if(!root) return ans;
        
//         //do this explicitly
//         ans.push_back(root->data);
        
//         if(!root->left && !root->right) return ans;
        
//         leftBoundary(root->left);
//         leafNodes(root);
//         rightBoundary(root->right);
        
//         return ans;
//     }
// };