// /*
// class Node {
//     int data;
//     Node *left;
//     Node *right;

//     Node(int val) {
//         data = val;
//         left = right = NULL;
//     }
// };
// */
// class Solution {
//   public:
  
//     void solve(Node* root, vector<int>&ans){
        
//         queue<Node*> q;
//         q.push(root);
        
//         bool left2right = true;
        
//         while(!q.empty()){
            
//             int size = q.size();
//             vector<int> temp(size);
            
//             for(int i =0;i<size;i++){
                
//                 Node* curr = q.front();
//                 q.pop();
                
//                 int index = left2right? i : size-i-1;
                
//                 temp[index] = curr->data;
                
//                 if(curr->left){
//                     q.push(curr->left);
//                 }
//                 if(curr->right){
//                     q.push(curr->right);
//                 }
//             }
//             left2right =  !left2right;
            
//             for(int ele:temp){
//                 ans.push_back(ele);
//             }
            
//         }
        
//     }
  
  
//     vector<int> zigZagTraversal(Node* root) {
//         // code here
//         vector<int> res;
//         solve(root,res);
//         return res;
//     }
// }; 