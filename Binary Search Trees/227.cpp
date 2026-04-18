// /*
// class Node {
// public:
//     int data;
//     Node* left;
//     Node* right;

//     Node(int val) {
//         data = val;
//         left = right = NULL;
//     }
// };
// */

// class Solution {
//   public:
  
//     stack<Node*> f;
//     stack<Node*> b;
//     int cnt =0 ;
    
//     void forwardHelper(Node* root){

//         Node* curr = root;
//         while(curr!=NULL){
//             f.push(curr);
//             curr = curr->left;
//         }
//     }
    
//     void backwardHelper(Node* root){
        
//         Node* curr = root;
//         while(curr!=NULL){
//             b.push(curr);
//             curr = curr->right;
//         }
//     }
    
//     void getCount(Node* root1,Node* root2, int x){
        
//         forwardHelper(root1);
//         backwardHelper(root2);
        
        
//         while(!f.empty() && !b.empty()){
//             Node* forward = f.top();
//             Node* backward = b.top();
//             int sum = forward->data + backward->data;
            
//             if(sum == x){
//                 cnt++;
//                 f.pop();
//                 b.pop();
//                 forwardHelper(forward->right);
//                 backwardHelper(backward->left);
//             }
//             else if(sum > x){
//                 b.pop();
//                 backwardHelper(backward->left);
//             }
//             else if(sum < x){
//                 f.pop();
//                 forwardHelper(forward->right);
//             }
//         }
        
        
        
        
//     }
  
//     int countPairs(Node* root1, Node* root2, int x) {
//         // code here
//         cnt = 0;
//         getCount(root1,root2,x);
//         return cnt;
//     }
// };