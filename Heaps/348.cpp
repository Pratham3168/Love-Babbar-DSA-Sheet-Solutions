
// User Function template for C++

// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    int countNodes(struct Node* root){
        if(root==NULL){
            return 0;
        }
        
        int ans=1+countNodes(root->left)+countNodes(root->right);
        
        return ans;
    }
    
    bool isCBT(struct Node* root,int index,int cnt){
        if(root==NULL){
            return true;
        }
        
        if(index>=cnt){
            return false;
        }
        
        bool left=isCBT(root->left,2*index+1,cnt);
        bool right=isCBT(root->right,2*index+2,cnt);
        
        return left && right;
    }
    
    bool isMaxHeap(struct Node* root){
        if(root->right==NULL && root->left==NULL){
            return true;
        }
        
        if(root->right==NULL){
            return (root->data>root->left->data);
        }
        else{
            bool left=isMaxHeap(root->left);
            bool right=isMaxHeap(root->right);
            
            return ((left&&right)&& root->data>root->left->data && 
            root->right->data<root->data);
        }
    }
    
    bool isHeap(struct Node* tree) {
        // code here
        int index=0;
        int totalcount=countNodes(tree);
        if(isCBT(tree,index,totalcount) && isMaxHeap(tree)){
            return true;
        }
        else{
            return false;
        }
    }
};