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
    Node *removeDuplicates(Node *head) {
        
        if(head == NULL) return head;
        
        unordered_map<int, bool> seen;
        
        Node* curr = head;
        Node* prev = NULL;
        
        while(curr != NULL) {
            
            if(seen[curr->data]) {
                // duplicate → remove node
                prev->next = curr->next;
                Node* temp = curr;
                curr = curr->next;
                delete temp;
            } else {
                // first time seen
                seen[curr->data] = true;
                prev = curr;
                curr = curr->next;
            }
        }
        
        return head;
    }
};