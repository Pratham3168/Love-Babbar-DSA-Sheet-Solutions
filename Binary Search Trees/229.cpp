// /*
// // Tree Node
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
  
//   int cnt =0;
  
  
//     //==========USING MORRIS INORDER==========
//     // void countNodes(Node* root,int l,int h){
//     //     Node* curr = root;
//     //     while(curr != NULL){
//     //         if(curr->left ==NULL){
//     //             if(l <= curr->data && h >= curr->data ){
//     //                 cnt ++;
//     //             }
                
//     //             curr = curr->right;
//     //         }
//     //         else{
//     //             Node* prev = curr->left;
//     //             while(prev->right && prev->right != curr){
//     //                 prev = prev->right;
//     //             }
//     //             if(prev->right == NULL){
//     //                 prev->right = curr;
//     //                 curr = curr->left;
//     //             }
//     //             else{
//     //                 prev->right = NULL;
//     //                 if(l <= curr->data && h >= curr->data ){
//     //                     cnt ++;
//     //                 }
                    
//     //                 curr = curr->right;
//     //             }
//     //         }
//     //     }
//     // }
  
  
//     //========USING RECURSION (BST PRUNING)=======
//     void getCountRecursion(Node* root,int l,int h){
//         //base case
//         if(root == NULL){
//             return;
//         }
        
//         if(root->data >= l ){
//             getCountRecursion(root->left,l,h);
//         }
        
//         if(l <= root->data && h >= root->data){
//             cnt++;
//         }
        
//         if(root->data <= h){
//             getCountRecursion(root->right,l,h);
//         }
//     }
  
  
//     int getCount(Node *root, int l, int h) {
//         // your code here
//         cnt = 0;
//         // countNodes(root,l,h);
//         getCountRecursion(root,l,h);
//         return cnt;
//     }
// };