#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
    int data ;
    Node *next ;

    Node(int x) {
        data = x ;
        next = NULL ;
    }
};


class Solution {
  public:
  
    void reverseUsingRecursion(Node* &head, Node* curr, Node* prev){
        if(curr == NULL){
            head = prev;
            return ;
        }
        
        Node* forward = curr->next;
        reverseUsingRecursion(head, forward,curr);
        curr->next = prev;
    }
  
  
    Node* reverseList(Node* head) {
        // code here
        
        //USING POINTERS
        // if(head == NULL || head->next == NULL)return head;
        // Node* prev = head;
        // Node* curr = prev->next;
        // prev->next=NULL;
        // Node* temp = curr->next;
        // while(curr!=NULL){
        //     curr->next = prev;
        //     prev = curr;
        //     curr = temp;
        //     if(curr!=NULL){
        //         temp = curr->next;
        //     }
        // }
        
        // return prev;
        
        
        
        //USING RECURSION
        if(head == NULL || head->next == NULL)return head;
        reverseUsingRecursion(head,head,NULL);
        return head;

    }
};