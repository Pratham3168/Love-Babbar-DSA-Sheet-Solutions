// // User function Template for C++

// class Solution {
//   public:
//     Node *moveToFront(Node *head) {
//         // code here
//         if(head->next == NULL || head == NULL){
//             return head;
//         }
//         Node* curr = head;
//         Node* prev = NULL;
        
//         while(curr!=NULL){
//             if(curr->next == NULL){
//                 prev->next = NULL;
//                 curr->next = head;
//                 head = curr;
//                 break;
//             }
            
//             prev = curr;
//             if(curr!=NULL){
//                 curr =  curr->next;
//             }
//         }
        
//         return head;
//     }
// };