//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    struct node *reverseIt (struct node *head, int k)
    { 
        // Complete this method
        int count=0;
        int occ;
        node *headcopy=head;
        int i=0;
        stack<int>stack;

        while(headcopy!=NULL)
        {
            count++;
            headcopy=headcopy->next;
        }

        occ=count/k;
        if(count%k)
        occ+=1;
        headcopy=head;
        node*it_head=headcopy;
        while(occ)
        {
            //it_head=headcopy;
            i=0;
            while(it_head!=NULL)
            {
                stack.push(it_head->data);
                it_head=it_head->next;
                i++;
                if(i==k)
                break;
            }
            it_head=headcopy;
            i=0;
            while(it_head!=NULL)
            {
                it_head->data=stack.top();
                stack.pop();
                it_head=it_head->next;
                i++;
                if(i==k)
                break;
            }  
            headcopy=it_head;
            occ--;
            
        }
        return head;
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverseIt(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends