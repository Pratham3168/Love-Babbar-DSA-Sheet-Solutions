#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
  
    Node* findMid(Node* head){
        
        Node* slow = head;
        Node* fast = head->next;
        
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
        
    }
    
    
    Node* merge(Node* left,Node* right){
        
        if(left == NULL) return right;
        if(right== NULL) return left;
        
        Node* ans = new Node(-1);
        Node* temp = ans;
        
        while(left!=NULL && right!=NULL){
            
            if(left->data < right->data){
                temp->next = left;
                temp = left;
                left = left->next;
            }
            else{
                temp->next = right;
                temp = right;
                right = right->next;
            }
            
        }
        
        while(left!=NULL){
            temp ->next = left;
            temp = left;
            left = left->next;
        }
        while(right!=NULL){
            temp-> next = right;
            temp = right;
            right = right->next;
        }
        
        ans = ans->next;
        return ans;
        
        
    }
  
  
  
    Node* mergeSort(Node* head) {
        // code here
        if(head == NULL || head->next == NULL) return head;
        
        Node* mid = findMid(head);
        
        Node* left = head;
        Node* right = mid->next;
        mid->next = NULL;
        
        //recursive calls to further break into two halves
        left = mergeSort(left);
        right = mergeSort(right);
        
        //merge the sorted halves
        Node* result = merge(left,right);
        
        return result;
        
    }
};