//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};



// } Driver Code Ends
/* Following is the Linked list node structure */

/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution{ 
public:
    int length(Node *head){
        int cnt = 0;
        Node *temp = head;
        while(temp!=NULL){
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
    
    Node *reverseList(Node *head){
        Node *temp = head;
        Node *prev = NULL;
        while(temp != NULL){
            Node *next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        return prev;
    }
    
    void reorderList(Node* head) {
        // Your code here
        
        // Basically the question is after the middle element 
        // reverse the elements after middle element
        //.and put them consecutively in the first half of the linked list
        
        
        if(head == NULL || head->next == NULL)
        return ;
        
        Node *temp1 = head;
        Node *mid = head;
        int len = length(head);
        int pos = (len/2) + 1;
        
        for(int i=0;i<pos-1;i++)
        mid = mid->next;
        
        Node *temp2 = reverseList(mid->next);
        
        while(temp2!=NULL && temp1 !=mid){
            Node *next_temp1 = temp1->next;
            Node *next_temp2 = temp2->next;
            
            temp1->next = temp2;
            temp2->next = next_temp1;
            
            temp1 = next_temp1;
            temp2 = next_temp2;
        }
        mid->next = NULL;
    }
};

//{ Driver Code Starts.



/* Function to create a new Node with given data */
struct Node* newNode(int data) {
    struct Node* new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {

        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    int t, n, m, i, x;

    cin >> t;
    while (t--) {
        struct Node* temp, *head;
        cin >> n;
        cin >> x;
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++) {
            cin >> x;
            temp->next = new Node(x);
            temp = temp->next;
        }
        
        Solution ob;
        
        ob.reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}

// } Driver Code Ends