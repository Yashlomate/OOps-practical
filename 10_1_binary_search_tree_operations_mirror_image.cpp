#include <iostream>
using namespace std;

// Node structure for BST
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Function to insert into BST (Handles duplicates)
Node* insert(Node* root, int data) {
    if (!root) return createNode(data);
    if (data < root->data) 
        root->left = insert(root->left, data);
    else if (data > root->data) 
        root->right = insert(root->right, data);
    return root;
}

// Function to delete a node from BST
Node* deleteNode(Node* root, int data) {
    if (!root) return nullptr;
    if (data < root->data) 
        root->left = deleteNode(root->left, data);
    else if (data > root->data) 
        root->right = deleteNode(root->right, data);
    else { 
        if (!root->left) return root->right;
        if (!root->right) return root->left;
        
        Node* successor = root->right;
        while (successor->left) 
            successor = successor->left;
        root->data = successor->data;
        root->right = deleteNode(root->right, successor->data);
    }
    return root;
}

// Function to search in BST
bool search(Node* root, int data) {
    if (!root) return false;
    if (root->data == data) return true;
    if (data < root->data) return search(root->left, data);
    return search(root->right, data);
}

// Function to display BST (In-order traversal)
void display(Node* root) {
    if (root) {
        display(root->left);
        cout << root->data << " ";
        display(root->right);
    }
}

// Function to display the mirror image of the tree
void displayMirror(Node* root) {
    if (root) {
        displayMirror(root->right);  // Mirror image by swapping left/right
        cout << root->data << " ";
        displayMirror(root->left);
    }
}

int main() {
    Node* root = nullptr;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);
    
    cout << "Tree (In-order): ";
    display(root);
    cout << endl;

    cout << "Search 40: " << (search(root, 40) ? "Found" : "Not Found") << endl;

    cout << "Tree Mirror (In-order): ";
    displayMirror(root);
    cout << endl;

    root = deleteNode(root, 50);
    cout << "After deleting 50 (In-order): ";
    display(root);
    cout << endl;

    return 0;
}
