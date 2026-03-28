#include <bits/stdc++.h>
using namespace std;
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


class Solution {
  public:
  
    Node* reverse(Node* head) {
        
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        
        while(curr != NULL) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
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
    
    
    Node* add(Node* head1,Node* head2){
        int carry = 0;
        Node* head=NULL;
        Node* tail=NULL;
        
        
        while(head1!=NULL || head2!=NULL || carry!=0){
            int val1 = 0;
            if(head1!=NULL){
                val1 = head1->data;
            }
            
            int val2 = 0;
            if(head2!=NULL){
                val2 = head2->data;
            }
            
            
            int sum = carry + val1 + val2;
            int digit = sum%10;
            
            insertAtTail(head,tail,digit);
            
            carry = sum/10;
            
            if(head1!=NULL){
                head1 = head1->next;
            }
            if(head2!=NULL){
                head2 = head2->next;
            }
        }
        return head;
    }
    
    
    
  
    Node* addTwoLists(Node* head1, Node* head2) {
        // code here
        head1 = reverse(head1);
        head2 = reverse(head2);
        
        Node* ans = add(head1,head2);
        
        ans = reverse(ans);
        
        while(ans != NULL && ans->data == 0 && ans->next != NULL){
    Node* temp = ans;
    ans = ans->next;   // move first
    delete temp;       // delete after
}
        
        return ans;
        
    }
};