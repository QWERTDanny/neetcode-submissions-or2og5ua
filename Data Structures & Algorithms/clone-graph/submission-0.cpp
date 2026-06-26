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
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;

        unordered_map<Node*, Node*> clonedMap;
        return dfs(node, clonedMap);
    }

    Node* dfs(Node* node, unordered_map<Node*, Node*> &clonedMap) {
        if(clonedMap.find(node) != clonedMap.end()) {
            return clonedMap[node];
        }

        Node* cloned_node = new Node(node->val);
        clonedMap[node] = cloned_node;

        for(Node* neighbor : node->neighbors) {
            Node* cloned_neighbor = dfs(neighbor, clonedMap);
            cloned_node->neighbors.push_back(cloned_neighbor);
        }
        return cloned_node;
    }
};
