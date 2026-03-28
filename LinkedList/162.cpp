#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int x)
    {
        data = x;
        prev = nullptr;
        next = nullptr;
    }
};


class Solution {
  public:
    Node *rotateDLL(Node *head, int p) {

        // code here..
        if(head == NULL || head->next == NULL)return head;
        
        Node* curr = head;
        Node* temp = curr;
        int cnt = 1;
        
        Node* tail = head;
        while(tail->next!=NULL){
            tail = tail->next;
            cnt++;
        }
        
        p = p%cnt; //EDGE CASE, IF LENGTH OF LIST IS LESS THAN  P
        if(p == 0)return head; //IMPORTANT
        
        for(int i = 0 ;curr!=NULL && i<p;i++){
            
            temp = curr->next;
            curr->prev = tail;
            tail->next = curr;
            curr->next = NULL;
            temp->prev = NULL;
            tail = curr;
            curr = temp;
            
        }
        
        head = curr;
        
        return head;
    }
};