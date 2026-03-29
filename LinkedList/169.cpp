#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

struct compare {
    bool operator()(Node* a, Node* b) {
        return a->data > b->data; // min heap
    }
};

class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        // code here
        priority_queue<Node* , vector<Node*>,compare> pq;
        
        //push all heads
        for(auto node:arr){
            if(node!=NULL)pq.push(node);
        }
        
        Node* newHead = new Node(-1);
        Node* tail = newHead;
        
        while(!pq.empty()){
            
            Node* temp = pq.top();
            pq.pop();
            
            tail->next =temp;
            tail=temp;
            if(temp->next){
                pq.push(temp->next);
            }
            
        }
        
        newHead = newHead->next;
        return newHead;
        
    }
};