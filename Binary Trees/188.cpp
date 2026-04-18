// /*
// class Node {
// public:
//     int data;
//     Node* left;
//     Node* right;

//     Node(int x) {
//         data = x;
//         left = right = NULL;
//     }
// };
// */

// class Solution {
//   public:
  
//     void solve(Node* root, vector<int> &ans){
        
//         queue<pair<Node*,int>> q;
//         map<int,int> mp;
        
//         q.push(make_pair(root,0));
        
//         while(!q.empty()){
            
//             pair<Node*,int> temp = q.front();
//             q.pop();
            
//             Node* node = temp.first;
//             int HD = temp.second;
            
//             if(node!=NULL){
//                 mp[HD] = node->data;
//                 if(node->left){
//                     q.push(make_pair(node->left,HD-1));
//                 }
//                 if(node->right){
//                     q.push(make_pair(node->right,HD+1));
//                 }
//             }
//         }
        
//         for(auto &it:mp){
//             ans.push_back(it.second);
//         }
        
//     }
  
//     vector<int> bottomView(Node *root) {
//         // code here
//         vector<int> ans;
//         solve(root,ans);
//         return ans;
        
//     }
// };