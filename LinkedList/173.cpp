#include<bits/stdc++.h>
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
    int getKthFromLast(Node* head, int k) {
        // code here
        if(head == NULL)return -1;
        
        Node* curr = head;
        
        int n=0;
        
        while(curr!=NULL){
            n++;
            curr=curr->next;
        }
        
        if(k>n)return -1;
        
        int p = n-k;
        
        Node* temp = head;
        
        while(p){
            temp=temp->next;
            p--;
        }
        
        return temp->data;
        
    }
};