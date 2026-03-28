#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
       data = x;
       next = NULL;
    }
};


class Solution {
  public:
  
     Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        
        while(curr != NULL) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
  
  
    bool isPalindrome(Node *head) {
        //  code here
        if(head == NULL || head->next == NULL) return true;
        
        Node* slow = head;
        Node* fast = head;
        
        while(fast->next!=NULL && fast->next->next != NULL){
            
            slow = slow->next;
            fast = fast->next->next;
    
            
        }
        
        Node* secondHalf = reverse(slow->next);
        
        Node* firstHalf = head;
        
        while(secondHalf!=NULL){
            
            if(secondHalf->data != firstHalf->data) return false;
            
            secondHalf = secondHalf->next;
            firstHalf = firstHalf->next;
            
        }
        
        return true;
        
    }
};