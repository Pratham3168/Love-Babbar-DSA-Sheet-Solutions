// User function Template for C++

#include <bits/stdc++.h>
using namespace std;


class DLLNode
{
public:
    int data;
    DLLNode *next;
    DLLNode *prev;
    DLLNode(int val)
    {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

struct compare {
    bool operator()(DLLNode* a, DLLNode* b) {
        return a->data > b->data;
    }
};

class Solution {
  public:
  
    
  
    // function to sort a k sorted doubly linked list
    DLLNode *sortAKSortedDLL(DLLNode *head, int k) {
        // code here
        priority_queue<DLLNode*, vector<DLLNode*>, compare> pq;
        
        DLLNode* temp = head;
        DLLNode* curr = NULL;
        DLLNode* newHead = NULL;
        
        for(int i =0 ; temp!=NULL && i<=k;i++){
            pq.push(temp);
            temp = temp->next;
        }
        
        while(!pq.empty()){
            if(newHead == NULL){
                newHead = pq.top();
                pq.pop();
                newHead->prev= NULL;
                curr=newHead;
            }
            else{
                curr->next = pq.top();
                pq.top()->prev=curr;
                curr=pq.top();
                pq.pop();
            }
            
            if(temp!=NULL){
                pq.push(temp);
                temp = temp->next;
            }
        }   
    curr->next=NULL;
        return newHead;
    }
};