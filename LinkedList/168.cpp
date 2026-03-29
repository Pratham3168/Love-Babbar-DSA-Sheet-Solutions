/*
class Node {
  public:
    int data;
    Node* next;
    Node* random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};
*/

// class Solution {
//   public:
//     Node* cloneLinkedList(Node* head) {
        // code here
        
        
        
        //===========USING MAP===========
        // unordered_map<Node*, Node*> mp;

        // Node* curr = head;
    
        // // Step 1: create all nodes
        // while (curr) {
        //     mp[curr] = new Node(curr->data);
        //     curr = curr->next;
        // }
    
        // curr = head;
    
        // // Step 2: connect next & random
        // while (curr) {
        //     mp[curr]->next = mp[curr->next];
        //     mp[curr]->random = mp[curr->random];
        //     curr = curr->next;
        // }
    
        // return mp[head];
        
        
        
        //=========OPTIMAL AND BEST=======
        //  if (!head) return NULL;
    
        // Node* curr = head;
    
        // // Step 1: insert cloned nodes
        // while (curr) {
        //     Node* temp = new Node(curr->data);
        //     temp->next = curr->next;
        //     curr->next = temp;
        //     curr = temp->next;
        // }
    
        // // Step 2: set random
        // curr = head;
        // while (curr) {
        //     if (curr->random)
        //         curr->next->random = curr->random->next;
        //     curr = curr->next->next;
        // }
    
        // // Step 3: separate lists
        // curr = head;
        // Node* copyHead = head->next;
    
        // while (curr) {
        //     Node* copy = curr->next;
        //     curr->next = copy->next;
        //     if (copy->next)
        //         copy->next = copy->next->next;
        //     curr = curr->next;
        // }
    
        // return copyHead;
//     }
// };