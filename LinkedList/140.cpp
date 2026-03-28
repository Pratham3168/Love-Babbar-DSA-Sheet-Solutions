#include <bits/stdc++.h>
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

class Solution {
  public:
  
    Node* reverse(Node* head, Node* tail) {
        Node* prev = tail->next;  // IMPORTANT
        Node* curr = head;
        Node* next = NULL;
    
        while (prev != tail) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
    
        return tail; // new head after reversal
    }
  
    Node *reverseKGroup(Node *head, int k) {
        // code here
        if(head == NULL || head->next == NULL)return head;
        
        int temp = k;
        
        Node* groupStart = head;
        Node* groupEnd = head;
        Node* nextGroup = NULL;
        Node* prevTail = NULL;
        Node* newHead = NULL;
        
        while(groupStart!=NULL){
            
            temp = k-1;
            
            while(temp--){
                if(groupEnd == NULL)break;
                groupEnd = groupEnd->next;
            }
            
            if(groupEnd == NULL){  //node remaining are less than k
                groupEnd = groupStart;
                while(groupEnd->next!=NULL){
                    groupEnd = groupEnd->next;
                }
                nextGroup = NULL;
            }else{
                nextGroup = groupEnd->next;
            }
            
            groupEnd = reverse(groupStart,groupEnd);
            if(newHead == NULL){
                newHead = groupEnd;
            }
            
            groupStart->next = nextGroup;
            if(prevTail != NULL){
                prevTail->next = groupEnd;
            }
            
            prevTail = groupStart;
            
            groupStart = nextGroup;
            groupEnd = groupStart;
            
        }
        return newHead;
    }
};