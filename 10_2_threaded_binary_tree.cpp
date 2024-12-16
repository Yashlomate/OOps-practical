#include <iostream>
using namespace std;

// Node structure for Threaded Binary Tree
struct Node {
    int data;
    Node* left;
    Node* right;
    bool isThread;  // Flag to indicate if it's a thread
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->isThread = false;
    return newNode;
}

// Function to create In-order Threads
void threadInOrder(Node* root, Node*& prev) {
    if (root == nullptr) return;

    threadInOrder(root->left, prev);

    if (prev) {
        prev->right = root;
        prev->isThread = true;
    }
    prev = root;

    threadInOrder(root->right, prev);
}

// Function for In-order Traversal using threads
void inOrderTraversal(Node* root) {
    Node* current = root;
    while (current) {
        while (!current->isThread && current->left) {
            current = current->left;
        }
        cout << current->data << " ";
        while (current->isThread) {
            current = current->right;
            cout << current->data << " ";
        }
        current = current->right;
    }
    cout << endl;
}

// Function for Pre-order Traversal
void preOrderTraversal(Node* root) {
    if (root) {
        cout << root->data << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

int main() {
    Node* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    root->left->left = createNode(2);
    root->left->right = createNode(7);
    root->right->right = createNode(20);

    Node* prev = nullptr;
    threadInOrder(root, prev);

    cout << "In-order Traversal: ";
    inOrderTraversal(root);

    cout << "Pre-order Traversal: ";
    preOrderTraversal(root);
    cout << endl;

    return 0;
}
