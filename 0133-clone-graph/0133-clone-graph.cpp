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
    unordered_map<Node*,Node*>map;

    Node* cloneGraph(Node* node) {
        if(!node)return nullptr;

        if(map.find(node)!=map.end()){
            return map[node];
        }

        Node* root=new Node(node->val);
        map[node]=root;
        for(int i=0;i<node->neighbors.size();i++){
            root->neighbors.push_back(cloneGraph(node->neighbors[i]));
        }
        return root;
        
    }
};