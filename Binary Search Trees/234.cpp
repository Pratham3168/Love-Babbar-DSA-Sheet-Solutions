// /* Tree node structure  used in the program

// struct Node {
//     int data;
//     Node *left;
//     Node *right;

//     Node(int val) {
//         data = val;
//         left = right = NULL;
//     }
// };*/

// class Solution {
//   public:
  
//     struct info{
//         bool isBst;
//         int maxi;
//         int mini;
//         int size;
//     };
    
    
//     info solve(Node* root){
//         //base case
//         if(root == NULL){
//             info ans;
//             ans.isBst = true;
//             ans.maxi = INT_MIN;
//             ans.mini = INT_MAX;
//             ans.size = 0;
//             return ans;
//         }
        
        
//         info left = solve(root->left);
//         info right = solve(root->right);
        
//         info curr;
//         curr.isBst = left.isBst && 
//                         right.isBst && 
//                         left.maxi<root->data && 
//                         right.mini>root->data;
                        
//         if(curr.isBst){
//             curr.size = left.size + right.size + 1;
//         }
//         else{
//             curr.size = max(left.size,right.size);
//         }
        
//         curr.mini = min(root->data,min(left.mini,right.mini));
//         curr.maxi = max(root->data,max(left.maxi,right.maxi));
        
//         return curr;
        
//     }
    
  
//     /*You are required to complete this method */
//     // Return the size of the largest sub-tree which is also a BST
//     int largestBst(Node *root) {
//         // Your code here
        
//         return solve(root).size;
//     }
// };