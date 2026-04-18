// /* A binary tree node
// struct Node
// {
//     int data;
//     Node* left, * right;
// }; */

// class Solution {
//   public:
  
  
//     int calculateHeight(Node* root , int target , int height){
//         //base case
//         if(root == NULL)return -1;
        
//         if(root->data == target){
//             return height;
//         }
        
//         int leftHeight = calculateHeight(root->left,target,height+1);
//         int rightHeight = calculateHeight(root->right,target,height+1);
        
        
//         return leftHeight!=-1 ? leftHeight : rightHeight;
        
//     }
  
//     //second finding the sum of depths from LCA
//     int solve(Node* root,int a,int b){
        
//         int firstHeight = calculateHeight(root,a,0);
//         int secondHeight = calculateHeight(root,b,0);
        
//         return firstHeight+secondHeight;
        
//     }
    
    
  
//     //first finding LCA
//     Node* LCA(Node* root,int a,int b){
//         //base case
//         if(root == NULL)return NULL;
        
//         if(root->data == a || root->data == b ){
//             return root;
//         }
        
//         Node* left = LCA(root->left,a,b);
//         Node* right = LCA(root->right,a,b);
        
//         if(left && right){
//             return root;
//         }
        
//         return left ? left: right;
//     }
  
//     /* Should return minimum distance between a and b
//     in a tree with given root*/
//     int findDist(Node* root, int a, int b) {
//         // Your code here
//         Node* lca = LCA(root,a,b);
        
//         int ans = solve(lca,a,b);
        
//         return ans;
        
//     }
// };