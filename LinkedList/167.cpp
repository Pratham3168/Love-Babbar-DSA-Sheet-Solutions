#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class Solution {
  public:
   Node* segregate(Node* head) {
    if(head == NULL || head->next == NULL) return head;
    
    Node* zeroH = new Node(-1);
    Node* zeroT = zeroH;
    
    Node* oneH = new Node(-1);
    Node* oneT = oneH;
    
    Node* twoH = new Node(-1);
    Node* twoT = twoH;
    
    Node* curr = head;
    
    while(curr != NULL){
        if(curr->data == 0){
            zeroT->next = curr;
            zeroT = curr;
        }
        else if(curr->data == 1){
            oneT->next = curr;
            oneT = curr;
        }
        else{
            twoT->next = curr;
            twoT = curr;
        }
        curr = curr->next;
    }
    
    // heads
    Node* zH = zeroH->next;
    Node* oH = oneH->next;
    Node* tH = twoH->next;
    
    // connect safely
    if(oH != NULL){
        zeroT->next = oH;
        oneT->next = tH;
    } else {
        zeroT->next = tH;
    }
    
    twoT->next = NULL;
    
    // return correct head
    if(zH != NULL) return zH;
    if(oH != NULL) return oH;
    return tH;
}
};