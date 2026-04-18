// /*
// class Node {
// public:
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
  
//     void getView(Node* root, vector<int>& ans){
        
//         // ========  APPROACH - 1 =======
//         // queue<Node*> q;
//         // q.push(root);
//         // q.push(NULL);
//         // vector<int> tempArray;
//         // while(!q.empty()){
//         //     Node* temp = q.front();
//         //     q.pop();
            
//         //     if(temp==NULL){
//         //         ans.push_back(tempArray[0]);
//         //         tempArray.clear();
//         //         // 🔑 KEY FIX
//         //         if(!q.empty()){
//         //             q.push(NULL);
//         //         }
//         //     }
//         //     else{
//         //         tempArray.push_back(temp->data);
//         //         if(temp->left){
//         //             q.push(temp->left);
//         //         }
//         //         if(temp->right){
//         //             q.push(temp->right);
//         //         }
//         //     }
        
        
        
//         // ====== APPROACH -2 (MORE CLEANER)====
//         queue<Node*> q;
//         q.push(root);
    
//         while (!q.empty()) {
//             int size = q.size();
    
//             for (int i = 0; i < size; i++) {
//                 Node* temp = q.front();
//                 q.pop();
    
//                 // 🔑 take first node of each level
//                 if (i == 0) {
//                     ans.push_back(temp->data);
//                 }
    
//                 if (temp->left) q.push(temp->left);
//                 if (temp->right) q.push(temp->right);
//             }
//         }

        
//     }
  
  
//     vector<int> leftView(Node *root) {
//         // code here
        
//         vector<int> ans;
//         if(root == NULL){
//             return ans;
//         }
        
//         getView(root,ans);
//         return ans;
        
//     }
// };