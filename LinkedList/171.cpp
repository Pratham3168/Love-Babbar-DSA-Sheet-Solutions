#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
   Node* reverse(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    
    while(curr){
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    return prev;
}

Node* compute(Node* head) {
    if(head == NULL || head->next == NULL) return head;
    
    head = reverse(head);
    
    Node* curr = head;
    int maxi = curr->data;
    
    while(curr && curr->next){
        if(curr->next->data < maxi){
            Node* temp = curr->next;
            curr->next = temp->next;
            delete temp;
        } else {
            curr = curr->next;
            maxi = curr->data;
        }
    }
    
    return reverse(head);
}
};