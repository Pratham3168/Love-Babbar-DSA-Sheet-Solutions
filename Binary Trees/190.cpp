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
  
//     pair<int,bool> solve(Node* root){
//         if(root == NULL){
//             return make_pair(0,true);
//         }
        
//         auto left = solve(root->left);
//         auto right = solve(root->right);
        
//         bool leftAns = left.second;
//         bool rightAns = right.second;
//         bool diff = abs(left.first-right.first) <= 1;
        
//         pair<int,bool> ans;
        
//         ans.first = max(left.first,right.first)+1;
        
//         ans.second = (leftAns && rightAns && diff);
        
//         return ans;
//     }
  
  
//     bool isBalanced(Node* root) {
//         // code here
//         return solve(root).second;
//     }
// };