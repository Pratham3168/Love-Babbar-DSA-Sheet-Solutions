#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  struct Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
};


//  function which splits the circular linked list.  head is pointer
// to head Node of given lined list.  head1_ref1 and *head_ref2
// are pointers to head pointers of resultant two halves.

class Solution {
  public:
    pair<Node *, Node *> splitList(struct Node *head) {
        // code here
        Node* slow = head;
        Node* fast = head;
        
        while(fast->next!=head && fast->next->next!=head){
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast->next->next == head){
            fast = fast->next;
        }
        Node* temp = slow->next;
        fast->next = temp;
        
        slow->next = head;
        
        pair<Node* , Node*> ans;
        ans.first = head;
        ans.second = temp;
        
        return ans;
    }
};