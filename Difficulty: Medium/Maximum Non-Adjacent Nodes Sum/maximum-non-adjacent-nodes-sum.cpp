/*
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
   pair<int,int> traverse(Node* node){
      pair<int,int> lft ={0,0}, rt = {0,0};
      if(node->left !=NULL)lft = traverse(node->left);
      if(node->right!=NULL)rt =traverse(node->right);
      int sum1 = 0, sum2 =0;
      sum2 = max(lft.first , lft.second) +  max(rt.first , rt.second);
      sum1 = lft.second + max(node->data + rt.second , rt.first);
      sum1 = max(sum1 , rt.second + max(node->data + lft.second , lft.first));
      return {sum1 , sum2};
  }
    int getMaxSum(Node *root) {
        // code here
         auto ans = traverse(root);
        return max(ans.first , ans.second);
    }
};