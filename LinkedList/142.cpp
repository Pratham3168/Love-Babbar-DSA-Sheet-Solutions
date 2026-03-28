#include <bits/stdc++.h>
using namespace std;
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Solution {
  public:
  
    Node* detectLoop(Node* head) {
        // code here
        if(head==NULL)return NULL;
        Node* slow = head;
        Node* fast = head;
        
        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
        
        fast=fast->next->next;
        if(slow == fast){
            return slow;
        }
            
        }
        
        return NULL;
    }
    
    Node* getStartingPoint(Node* head){
        
        Node* meet = detectLoop(head);
        if(meet == NULL){
            return NULL;
        }
        
        Node* slow = head;
        
        while(slow!=meet){
            slow = slow->next;
            meet = meet->next;
        }
        
        return slow;
        
    }
    
    
  
    void removeLoop(Node* head) {
        // code here
        
        Node* startPoint = getStartingPoint(head);
        if(startPoint == NULL)return;
        
        Node* temp = startPoint;
        
        while(temp->next!=startPoint){
            temp = temp->next;
        }
        
        temp->next = NULL;
        
    }
};