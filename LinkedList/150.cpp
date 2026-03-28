#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        //  Code Here
        int len1 = 0;
        int len2 = 0;
        
        //calculating len1
        Node* temp = head1;
        while(temp != NULL){
            len1++;
            temp = temp->next;
        }
        //calculating len2
        temp = head2;
        while(temp != NULL){
            len2++;
            temp = temp->next;
        }
        
        

        int diff = abs(len1-len2);
        

        Node* curr1 = head1;
        Node* curr2 = head2;
        
        // align
        if(len1 > len2){
            while(diff--) curr1 = curr1->next;
        } else {
            while(diff--) curr2 = curr2->next;
        }
        
        // traverse together
        while(curr1 != curr2){
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        
        return curr1;
        
        

    }
};