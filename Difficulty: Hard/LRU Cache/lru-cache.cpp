//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class Node {

public:

int key;

int value;

Node* prev;

Node* next;

Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}

};

//Then the LRUCache class:

class LRUCache {

private:

int capacity;

unordered_map<int, Node*> cache;

Node* head;

Node* tail;

void addToFront(Node* node) {

// Add the node right after the head dummy node

node->prev = head;

node->next = head->next;

head->next->prev = node;

head->next = node;

}

void removeNode(Node* node) {

// Remove the node from the list

Node* prevNode = node->prev;

Node* nextNode = node->next;

prevNode->next = nextNode;

nextNode->prev = prevNode;

}

void moveToHead(Node* node) {

removeNode(node);

addToFront(node);

}

Node* popTail() {

Node* node = tail->prev;

removeNode(node);

return node;

}

public:

LRUCache(int cap) {

capacity = cap;

head = new Node(-1, -1);

tail = new Node(-1, -1);

head->next = tail;

tail->prev = head;

}

int get(int key) {

if (cache.find(key) == cache.end()) {

return -1;

}

Node* node = cache[key];

moveToHead(node);

return node->value;

}

void put(int key, int value) {

if (cache.find(key) != cache.end()) {

Node* node = cache[key];

node->value = value;

moveToHead(node);

} else {

Node* newNode = new Node(key, value);

cache[key] = newNode;

addToFront(newNode);

if (cache.size() > capacity) {

Node* lruNode = popTail();

cache.erase(lruNode->key);

delete lruNode;

}

}

}

};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--) {
            string q;
            cin >> q;
            if (q == "PUT") {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->put(key, value);
            } else {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends