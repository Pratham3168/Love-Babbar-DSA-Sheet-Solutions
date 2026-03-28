// User function Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};


class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        // code here
        vector<pair<int,int>> ans;
        Node* tail = head;
        while(tail->next!=NULL){
            tail = tail ->next;
        }
        
        Node* f = head;
        Node* b = tail;
        
        while(f->data < b->data){
            int ele = f->data + b->data;
            
            if(ele == target){
                pair<int,int> temp;
                temp.first = f->data;
                temp.second = b->data;
                ans.push_back(temp);
                f = f->next;
                b = b->prev;
            }else if(ele > target){
                b = b->prev;
            }else if(ele < target){
                f = f->next;
            }
        }
        return ans;
    }
};