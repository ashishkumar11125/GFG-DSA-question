//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

// Initial template for C++

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
/* Link list Node
struct Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

}; */
class Solution {
  public:
    /* Agar linked list empty ho, toh -1 return karega. Warna middle node ka data return karega */
    int getMiddle(Node* head) {
        // slow pointer ko head se initialize karte hain
        Node *slow = head;
        // fast pointer ko bhi head se initialize karte hain
        Node *fast = head;
        
        // Jab tak fast pointer aur fast ka next NULL nahi ho jaate, loop chalayenge
        while(fast != NULL && fast->next != NULL) {
            // slow pointer ko ek step aage badhate hain
            slow = slow->next;
            // fast pointer ko do steps aage badhate hain
            fast = fast->next->next;
        }
        
        // Jab fast pointer list ke end tak pahunch jaata hai, slow pointer middle pe hota hai
        // slow pointer ka data return karte hain jo middle node ka data hoga
        return slow->data;
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after reading t

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        cout << ob.getMiddle(head) << endl;
    }

    return 0;
}

// } Driver Code Ends