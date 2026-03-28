#include <bits/stdc++.h>
using namespace std;
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};


class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        if(head == NULL || head->next == NULL)return head;
        
        Node* curr = head;
        Node* prev = NULL;
        
        while(curr!=NULL){
            
            Node* temp = curr->next;
            curr->prev = temp ;
            curr->next = prev;
            prev = curr;
            curr = temp;
            
        }
        
        head = prev;
        
        return head;
    }
};