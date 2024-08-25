//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
      
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
          
        // Get the current node's value from the string
        string currVal = ip[i];
          
        // If the left child is not null
        if(currVal != "N") {
            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }
          
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
          
        // If the right child is not null
        if(currVal != "N") {
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function template for C++
/*
Structure of the node of the tree is as follows 
struct Node {
    struct Node* left, *right;
    int data;
};
*/

class Solution{
  public:
    // function should return the number of turns required to go from first node to second node 
    // function should return the number of turns required to go from first node to second node
    int ans = 0;
    struct Node* lowestCommonAncestor(struct Node *root,int p,int q){
        if(!root)return NULL;
        if(root->data==p || root->data==q){
            return root;
        }
        struct Node* left = lowestCommonAncestor(root->left,p,q);
        struct Node* right = lowestCommonAncestor(root->right,p,q);
        if(left != NULL && right != NULL)
        {
            return root;
        }
        else{
            if(left == NULL) return right;
            else{
                return left;
            }
        }
    }
    
    bool findDir(struct Node* node , bool dir , int key){
        if(!node) return NULL;
        
        if(node->data == key) return true; //node found
        
        
        //following are the cases where we check if we find our node in any of the subtree if not found false is returned
        if(dir){//dir is left here that is true
            if(findDir(node->left, dir , key)){
                return true;// dir is left and we are moving in left so no direction change
            }
            if(findDir(node->right, !dir , key)){
                ans++; // dir is left and we are moving in right so direction change and res is incremented
                return true;
            }
        }
        else{//dir is false here that is right
            if(findDir(node->right, dir , key)){
                return true; // dir is right and we are moving in right so no direction change
            }
            if(findDir(node->left , !dir , key)){
                ans++; // dir is right and we are moving in left so direction change and res is incremented
                return true;
            }
        }
        
        return false; // no node found
        
    }
    
    int NumberOFTurns(struct Node* root, int first, int second)
    {
      // Your code goes here
      // direction = true means left and false means right; // initially it is set to true that is left
      struct Node* lca = lowestCommonAncestor(root , first , second);
      bool dir = true;
      if(lca->data == first){
          findDir(lca->left , dir , second);
          findDir(lca->right , !dir , second);
      }
      else if (lca->data == second){
          findDir(lca->left , dir , first);
          findDir(lca->right , !dir , first);
      }
      else{
          findDir(lca->left , dir , first);
          findDir(lca->right , !dir , first);
          findDir(lca->left , dir , second);
          findDir(lca->right , !dir , second);
          return ans+1;
      }
      return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    struct Node *child;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        int turn, first, second;
        cin>>first>>second;
        Solution ob;
        if ((turn = ob.NumberOFTurns(root, first, second) ))
            cout<<turn<<endl;
        else 
            cout<<"-1\n";
        cin.ignore();
    }
    return 0;
}

// } Driver Code Ends