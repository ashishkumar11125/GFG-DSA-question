/*
class Node {
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
  public:
    vector<int> zigZagTraversal(Node* root) {
        // code here
        vector<int> ans;
        queue<Node*> q;
        q.push(root);
        bool order = true;
        while(!q.empty()){
            vector<int> temp;
            int sz = q.size();
            for(int i = 0 ; i < sz ; i++){
                Node* node = q.front();
                temp.push_back(node->data);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
                q.pop();
            }
            
            if(order){
                //insert temp to ans in clockwise
                for(int i = 0 ; i < temp.size(); i++){
                    ans.push_back(temp[i]);
                }
            }else{
                //insert temp to ans in anti-clockwise
                for(int i = temp.size() - 1 ; i >= 0 ; i--){
                    ans.push_back(temp[i]);
                }
            }
            temp.clear();
            order = !order;
        }
        return ans;
    }
};