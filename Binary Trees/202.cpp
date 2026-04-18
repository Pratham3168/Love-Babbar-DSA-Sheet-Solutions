// /*
// class Node {
//   public:
//     int data;
//     Node *left;
//     Node *right;

//     Node(int x) {
//         data = x;
//         left = NULL;
//         right = NULL;
//     }
// }; */

// class Solution {
//   public:
  
//     //using recursion and pair<height,sum>
//     pair<int,int> solve(Node* root){
//         if(root == NULL){
//             return (make_pair(0,0));
//         }
        
//         pair<int,int> left = solve(root->left);
//         pair<int,int> right = solve(root->right);
        
//         pair<int,int> ans;
//         ans.first = max(left.first,right.first) + 1;
//         if(left.first == right.first){
//             ans.second = root->data + max(left.second,right.second);
//         }
//         else if(left.first>right.first){
//             ans.second = root->data + left.second;
//         }
//         else{
//             ans.second = root->data + right.second;
//         }
        
//         return ans;
//     }
  
//     int sumOfLongRootToLeafPath(Node *root) {
//         // code here
//         return solve(root).second;
        
//     }
// };