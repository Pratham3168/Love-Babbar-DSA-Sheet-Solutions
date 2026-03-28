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
} ;

class Solution {
  public:
    bool detectLoop(Node* head) {
        // code here
        if(head==NULL)return false;
        Node* slow = head;
        Node* fast = head;
        
        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
        
        fast=fast->next->next;
        if(slow == fast){
            return true;
        }
            
        }
        
        return false;
    }
    
};