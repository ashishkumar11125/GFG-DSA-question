/* Structure of a Linked List node
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
     Node *reverse(Node *head){
           
           Node *prev= NULL;
           Node *curr= head;
           
           while (curr){
                   
                   Node *next = curr->next;
                   curr->next = prev;
                   prev = curr;
                   curr = next;
                   
           }
           
           return prev;
            
    }
    Node *compute(Node *head) {
        // code here
        
            head = reverse(head);
            
            int maxi = INT_MIN;
            
            Node *temp = head;
            
            // while (temp){
            //      cout<<temp->data<<" ";
            //      temp =temp->next;
            // }
            while(temp){
                   
                   while(temp && temp->next && temp->data>temp->next->data){
                           
                           temp->next = temp->next->next;
                        //   temp = temp->next;
                          maxi = max(maxi,temp->data);
                   }
                   
                      temp=temp->next;
        
                   
            }
            return reverse(head);
    }
};