// /*
// class Node {
//   public:
//     int data;
//     Node* left;
//     Node* right;

//     Node(int val) {
//         data = val;
//         left = nullptr;
//         right = nullptr;
//     }
// };
// */

// class Solution {
//   public:
  
//     void getView(Node* root, vector<int> &ans){
//         queue<Node*> q;
//         q.push(root);
    
//         while (!q.empty()) {
//             int size = q.size();
    
//             for (int i = 0; i < size; i++) {
//                 Node* temp = q.front();
//                 q.pop();
    
//                 // 🔑 take first node of each level
//                 if (i == size-1) {
//                     ans.push_back(temp->data);
//                 }
    
//                 if (temp->left) q.push(temp->left);
//                 if (temp->right) q.push(temp->right);
//             }
//         }
//     }
  
//     vector<int> rightView(Node *root) {
//         //  code here
//         vector<int> ans;
//         if(root == NULL)return ans;
        
//         getView(root,ans);
//         return ans;
//     }
// };