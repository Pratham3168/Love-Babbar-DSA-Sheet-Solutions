#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};


class Solution {
  public:
  
    void reverse(Node* &head) {
        
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        
        while(curr != NULL) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
       
    }
    
    
    void insertAtTail(Node* &head, Node* &tail,int val){
        Node* temp = new Node(val);
        
        if(head == NULL){
            head = temp;
            tail = temp;
            return;
        }
        else{
            tail->next = temp;
            tail = temp;
            return;
        }
        
        
    }
    
    
    void add(Node* &head){
        
        int carry = 1;
        int sum = 0;
        
        
        Node* temp = head;
        
        while(temp!=NULL && carry!=0){
            
            
            sum = temp->data + carry;
            
            temp->data = sum%10;
            carry = sum/10;
            
            
            
            
            if(temp->next == NULL && carry!=0){
                insertAtTail(head,temp,carry);
                return ;
            }
            
            temp = temp->next;
            
            
        }
    }
    
  
    Node* addOne(Node* head) {
        // Your Code here
        
        reverse(head);
        
        add(head);
        
        reverse(head);
        
        return head;
        
        
        // return head of list after adding one
    }
};