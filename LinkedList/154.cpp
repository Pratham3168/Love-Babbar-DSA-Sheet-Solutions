
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


/* Should return true if linked list is circular, else false */
class Solution {
  public:
  
    // GFG says even an empty list is circular… yeah, apparently logic took a vacation here.
    // If this confuses you, welcome to my pain. Don’t blame the code, blame GFG.
  
    bool isCircular(Node *head) {
    if (head == NULL) return true;  // IMPORTANT (GFG expects this)

    Node* temp = head->next;

    while (temp != NULL && temp != head) {
        temp = temp->next;
    }

    return (temp == head);
}
};