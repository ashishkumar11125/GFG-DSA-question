/* Structure of Binary Tree Node
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
    int longestConsecutive(Node* root) {
        // code here
         int ans=-1,cnt=1;
         help(root,ans,cnt,-1);
         return ans==1?-1:ans;
    }
    void help(Node* root,int &ans,int cnt,int prev){
        if(!root)return;
        
        if(root->data-prev==1)cnt+=1;
        else cnt=1;
        ans=max(ans,cnt);
        
        help(root->left,ans,cnt,root->data);
        help(root->right,ans,cnt,root->data);
    }
};