// //Back-end complete function Template for C++

// class Solution {
//   public:
  
  
//     struct Node {
//         int data;
//         Node *left, *right;
//     };
    
//     // A utility function to create a new BST node
//     Node* newNode(int item)
//     {
//         Node* temp = new Node;
//         temp->data = item;
//         temp->left = temp->right = NULL;
//         return temp;
//     }
  

//     Node* insert(Node* root, int val, int &succ) {
//         if (root == NULL) {
//             return newNode(val);
//         }

//         if (val < root->data) {
//             succ = root->data;   // current node is a better successor candidate
//             root->left = insert(root->left, val, succ);
//         } else {
//             root->right = insert(root->right, val, succ);
//         }

//         return root;
//     }

    
//     void replace(vector<int>& arr, int n)
//     {
//         Node* root = NULL;
//         for (int i = n - 1; i >= 0; i--) {
//             int succ = -1;
//             root = insert(root, arr[i], succ);
//             arr[i] = succ;
//         }
//     }
  
  
//     vector<int> findLeastGreater(vector<int>& arr, int n) {
//         replace(arr,n);
//         return arr;
//     }
// };