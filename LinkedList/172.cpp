// User function template for C++
#include<bits/stdc++.h>
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
    Node* divide(Node* head) {
        // code here
        if(head == NULL || head->next == NULL) return head;
    
    Node* evenH = new Node(-1);
    Node* evenT = evenH;
    
    Node* oddH = new Node(-1);
    Node* oddT = oddH;
    
    Node* curr = head;
    
    while(curr != NULL){
        if(curr->data % 2 == 0){
            evenT->next = curr;
            evenT = curr;
        } else {
            oddT->next = curr;
            oddT = curr;
        }
        curr = curr->next;
    }
    
    // actual heads
    Node* eH = evenH->next;
    Node* oH = oddH->next;
    
    // connect
    if(eH != NULL){
        evenT->next = oH;
    }
    
    oddT->next = NULL;
    
    // return correct head
    if(eH != NULL) return eH;
    return oH;
    }
};