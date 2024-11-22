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
    Node* cloneUtil(Node* node, unordered_map<Node*, Node*>& mp) {
        Node* newNode = new Node(node->val);
        mp[node] = newNode;
        for (auto neighbor : node->neighbors) {
            if (mp.find(neighbor) == mp.end()) {
                // Create the neighbor's clone
                (newNode->neighbors).push_back(cloneUtil(neighbor, mp));
            } else {
                (newNode->neighbors).push_back(mp[neighbor]);
            }
        }
        return newNode;
    }

    Node* cloneGraph(Node* node) {
        if (!node) return NULL;
        unordered_map<Node*, Node*> mp; // old -> new
        return cloneUtil(node, mp);
    }
};