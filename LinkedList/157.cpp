// #include <bits/stdc++.h>
// using namespace std;

// class Node {
//     int data;
//     Node *next;

//     Node(int x) {
//         data = x;
//         next = NULL;
//     }
// };

// class Solution {
//   public:
//     Node* deleteNode(Node* head, int key) {
//         // code here
//         if(head == NULL) return head;
        
//         // 🔥 Handle head separately
//         if(head->data == key){
            
//             // single node case
//             if(head->next == head){
//                 delete head;
//                 return NULL;
//             }
            
//             // find last node
//             Node* temp = head;
//             while(temp->next != head){
//                 temp = temp->next;
//             }
            
//             temp->next = head->next;
//             Node* del = head;
//             head = head->next;
//             delete del;
            
//             return head;
//         }
        
//         Node* curr = head;
        
//         while(curr->next!=head){
            
//             if(curr->next->data == key){
//                 Node* temp = curr->next;
//                 curr->next = temp->next;
//                 temp->next = NULL;
//                 delete temp;
//                 return head;
//             }
//             curr = curr->next;
            
            
//         }
//         return head;
// }};