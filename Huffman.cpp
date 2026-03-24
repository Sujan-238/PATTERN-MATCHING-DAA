#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Node structure
struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

// Comparator (Min Heap)
struct compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

// Function to print codes
void printCodes(Node* root, string code) {
    if (!root)
        return;

    // Leaf node
    if (root->left == nullptr && root->right == nullptr) {
        cout << root->ch << " : " << code << endl;
    }

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

int main() {
    char arr[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int n = 6;

    priority_queue<Node*, vector<Node*>, compare> pq;

    // Insert nodes
    for (int i = 0; i < n; i++) {
        pq.push(new Node(arr[i], freq[i]));
    }

    // Build tree
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* newNode = new Node('#', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    // Print result
    cout << "Huffman Codes:\n";
    printCodes(pq.top(), "");

    return 0;
}