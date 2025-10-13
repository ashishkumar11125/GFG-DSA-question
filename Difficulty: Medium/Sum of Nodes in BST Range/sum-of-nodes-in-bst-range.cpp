/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    int ans =0;
    int nodeSum(Node* root, int l, int r) {
        // code here
            
            if (!root) return 0;
            if (root->data<=r && root->data>=l){
                ans+=root->data ;  
            }
            
            nodeSum(root->left,l,r);
            nodeSum(root->right,l,r);
             return ans;
    }
};
