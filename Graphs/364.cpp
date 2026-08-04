/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node* , Node*> mp;

    Node* dfsClone(Node* headNode){
        if(headNode == NULL)return NULL;

        if(mp.find(headNode) != mp.end()){
            return mp[headNode];
        }

        Node* cloneHead = new Node(headNode->val);
        mp[headNode] = cloneHead;

        for(Node* neighbor : headNode->neighbors){
            cloneHead->neighbors.push_back(dfsClone(neighbor));
        }

        return cloneHead;
    }

    Node* cloneGraph(Node* node) {
        return dfsClone(node);
    }
};