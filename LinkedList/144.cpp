#include <bits/stdc++.h>
using namespace std;
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

class Solution {
  public:
    // Function to remove duplicates from sorted linked list.
    Node* removeDuplicates(Node* head) {

        // code here
        if(head == NULL || head->next == NULL)return head;
        Node* prev = NULL;
        Node* curr = head;
        Node* temp = curr;
        
        prev = curr;
        curr = curr->next;
        
        while(curr!=NULL){
            if(curr->data == prev->data){
                while(curr!=NULL && curr->data == prev->data){
                    temp = curr;
                    curr = curr->next;
                }
                temp->next = NULL;
                prev->next = curr;
                prev = curr;
                temp = curr;
                if(curr!=NULL){
                    curr = curr->next;
                }
                
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};