// /*The structure of the Binary Tree Node  is
// struct Node
// {
//   char data;
//   struct Node* left;
//   struct Node* right;
// };*/

// class Solution {
//   public:
  
//     unordered_map<string,int> mp;
//     bool hasDuplicate = false;
  
//     string solve(Node* root){
//         //base case
//         if(root == NULL)return "#";
        
//         string left = solve(root->left);
//         string right = solve(root->right);
        
//         string node(1, root->data);
        
//         string ans = node+','+left+','+right;
        
//         if(!(root->left == NULL && root->right == NULL)){
//             mp[ans] += 1;
//         }
//         if(mp[ans] == 2){
//             hasDuplicate = true;
//         }
//         return ans;
//     }
  
//     /*This function returns true if the tree contains
//     a duplicate subtree of size 2 or more else returns false*/
//     int dupSub(Node *root) {
//         // code here
//         solve(root);
        
//         return hasDuplicate?1:0;
        
        
//     }
// };