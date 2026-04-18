// /*
// struct Node
// {
//     int data;
//     struct Node *left;
//     struct Node *right;
//     struct Node *next;

//     Node(int x)
//     {
//         data = x;
//         left = NULL;
//         right = NULL;
//         next = NULL;
//     }
// };
// */
// class Solution {
//   public:
  
//     Node* prev = NULL;
    
//     void solve(Node* root){
//         //base case
//         if(root == NULL){
//             return;
//         }
        
//         solve(root->left);
//         //process
//         if(prev != NULL){
//             prev->next = root;
//         }
//         prev = root;
        
//         solve(root->right);
//     }
  
//     void populateNext(Node *root) {
//         // code here
//         solve(root);
//     }
// };