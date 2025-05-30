/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  private:
    unordered_map<Node*, Node*> parent;
    Node* targetNode = nullptr;
    
    void findTarget(Node* node, int target, Node* par = nullptr) {
        if (!node) return;
        parent[node] = par;
        if (node->data == target) targetNode = node;
        findTarget(node->left, target, node);
        findTarget(node->right, target, node);
    }
    
public:
    int minTime(Node* root, int target) {
        findTarget(root, target);
        if (!targetNode) return 0;
        
        queue<Node*> q;
        unordered_set<Node*> visited;
        q.push(targetNode);
        visited.insert(targetNode);
        
        int time = 0;
        while (!q.empty()) {
            int size = q.size();
            bool burned = false;
            
            for (int i = 0; i < size; i++) {
                Node* node = q.front(); q.pop();
                
                vector<Node*> neighbors = {node->left, node->right, parent[node]};
                for (Node* nei : neighbors) {
                    if (nei && visited.find(nei) == visited.end()) {
                        q.push(nei);
                        visited.insert(nei);
                        burned = true;
                    }
                }
            }
            
            if (burned) time++;
        }
        
        return time;
    }
};