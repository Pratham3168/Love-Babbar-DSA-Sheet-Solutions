// /*
// class Node {
// public:
//     int data;
//     Node *left;
//     Node *right;

//     Node(int x) {
//         data = x;
//         left = NULL;
//         right = NULL;
//     }
// };
// */

// class Solution {
//   public:
  
//     unordered_map<int,int> mp;
    
//     void make_map(vector<int>& inorder){
//         for(int i=0;i<inorder.size();i++){
//             mp[inorder[i]] = i;
//         }
//     }
  
    
//     Node* solve(vector<int> &inorder,vector<int> &preorder ,
//                 int inStart, int inEnd, int preStart, int preEnd){
        
//         //base case(since both the windows from inorder and preorder will be equal)
//         if(inStart > inEnd || preStart > preEnd) return NULL;
        
//         int val = preorder[preStart];
//         int idx = mp[val];
        
//         Node* root = new Node(val);
        
//         //left window
//         int leftSize = idx - inStart;
        
//         root->left = solve(inorder,preorder,
//                             inStart,idx-1,
//                             preStart+1,preStart+leftSize);
                            
//         root->right = solve(inorder,preorder,
//                             idx+1,inEnd,
//                             preStart+leftSize+1 ,preEnd);
        
//         return root;
        
        
        
        
//     }
    
  
//     Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
//         // code here
//         make_map(inorder); 
//         Node* root = solve(inorder,preorder,0,inorder.size()-1,0,preorder.size()-1);
//         return root;
//     }
// };