// /*  Tree node
// struct Node
// {
//     int data;
//     Node* left, * right;
// }; */

// // Should return true if tree is Sum Tree, else false
// class Solution {
//   public:
  
  
//     pair<bool,int> solve(Node* root){
//         if(root == NULL){
//             return (make_pair(true,0));
//         }
        
//         if(!root->left && !root->right){
//             return (make_pair(true,root->data));
//         }
        
//         pair<bool,int> left = solve(root->left);
//         pair<bool,int> right = solve(root->right);
        
//         pair<bool,int> ans;
//         if(left.first && right.first && (root->data == left.second + right.second)){
//             ans.first = true;
//         }
//         else{
//             ans.first = false;
//         }
//         ans.second = root->data + left.second + right.second;
        
//         return ans;
//     }
  
  
//     bool isSumTree(Node* root) {
//         // Your code here
//         return solve(root).first;
//     }
// };