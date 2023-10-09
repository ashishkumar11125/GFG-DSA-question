//{ Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert()
{
    int n,value;
    cin>>n;
    struct Node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}


// } Driver Code Ends
/*
  reverse alternate nodes and append at the end
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
      int data;
      struct Node *next;
    
      Node(int x){
        data = x;
        next = NULL;
      }
    
   };

*/
class Solution
{
    public:
    void rearrange(struct Node *odd)
    {
        //add code here
        // Initialize pointers
        Node *rev = NULL;   // Pointer for reversing odd-indexed nodes
        Node *temp = odd;   // Pointer for traversal
        Node *next = odd;   // Pointer to keep track of next odd node
        Node *rt = NULL;    // Temporary pointer for reversing nodes

        // Traverse the linked list
        while (temp && temp->next)
        {
            // Store the next odd node in 'rt'
            rt = temp->next;

            // Adjust pointers to reverse 'rt' and connect it to 'rev'
            temp->next = rt->next;
            rt->next = rev;
            rev = rt;

            // Update 'next' to the next odd node
            next = temp->next;

            // If we are at the end of the list, set 'next' to the current node
            if (!temp->next)
            {
                next = temp;
            }

            // Move to the next node in the list
            temp = temp->next;
        }

        // Connect the last even-indexed node to the reversed odd-indexed nodes
        next->next = rev;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while (t--) {
        insert();
        Solution ob;
        ob.rearrange(start);
        printList(start);
    }
    return 0;
}

// } Driver Code Ends