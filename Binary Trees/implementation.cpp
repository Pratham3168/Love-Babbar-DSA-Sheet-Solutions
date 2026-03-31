//IMPLEMENTING BINARY TREES AND ITS DFS , BFS TRAVERSALS

#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }

};


//code for building tree
node* buildTree(node* root){
    cout<<"Enter the root : "<<endl;
    int data;
    cin>>data;
    if(data == -1)return NULL;
    root = new node(data);
    
    cout<<"Enter the data for left of : "<<root->data<<endl;
    root->left=buildTree(root->left);

    cout<<"Enter the data for the right of : "<<root->data<<endl;
    root->right=buildTree(root->right);

    return root;

}

//level order traversal
void levelOrderTraversal(node* root){
    if(root == NULL) return;

    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty())q.push(NULL);
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
    }
}


void buildFromLevelOrderTraversal(node* &root){
    queue<node*> q;
    cout<<"Enter the value of root node : "<<endl;
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        int leftData;
        cout<<"Enter data for left of : "<<temp->data<<endl;
        cin>>leftData;
        if(leftData != -1){
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        int rightData;
        cout<<"Enter data for right of : "<<temp->data<<endl;
        cin>>rightData;
        if(rightData != -1){
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }

}


void inOrderTraversal(node* root){
    if(root == NULL)return;

    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}

int main(){
    node* root=NULL;
    // root=buildTree(root);
    buildFromLevelOrderTraversal(root);
    // levelOrderTraversal(root);

    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // root=buildTree(root);

    // levelOrderTraversal(root);
    cout<<"\nPrintting Inorder Traversal "<<endl;
    inOrderTraversal(root);
    // cout<<"\nPrinting Preorder Traversal "<<endl;
    // PreorderTraversal(root);
    // cout<<"\nPrinting Postorder Traversal "<<endl;
    // PostorderTraversal(root);
    return 0;
}