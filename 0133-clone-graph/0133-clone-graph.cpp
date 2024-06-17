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
    unordered_map<Node*, Node*> m;
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        m.clear();
        fillMap(node);
        addEdges();
        return m[node];
    }

    void fillMap(Node* node) {
        if(m.find(node) != m.end()) return;
        m[node] = new Node(node->val);
        for(auto neighbor : node->neighbors) fillMap(neighbor);
    }

    void addEdges() {
        for(auto [oldNode, newNode] : m) {
            for(auto neighbor : oldNode->neighbors) {
                newNode->neighbors.push_back(m[neighbor]);
            }
        }
    }
};