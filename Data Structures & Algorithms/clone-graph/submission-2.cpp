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
        map<Node*,Node*> nodeMap;

        return dfs(node, nodeMap);
        
    }

    Node* dfs(Node* node, map<Node*,Node*>& nodeMap) {

        if (!node){
            return nullptr;
        }

        if (nodeMap.count(node)){
            return nodeMap[node];
        }

        Node* newNode = new Node(node->val);
        nodeMap[node] = newNode;

        for(auto neighbor: node->neighbors){
            newNode->neighbors.push_back(dfs(neighbor, nodeMap));
        }

        return newNode;

    }

};
