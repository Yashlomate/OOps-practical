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
        else if (!root->right) return root->left;
        
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
    else return search(root->right, data);
}

// Function to display BST (In-order traversal)
void display(Node* root) {
    if (root) {
        display(root->left);
        cout << root->data << " ";
        display(root->right);
    }
}

// Function to get the depth of the tree
int getDepth(Node* root) {
    if (!root) return 0;
    return max(getDepth(root->left), getDepth(root->right)) + 1;
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
    cout << "Tree Depth: " << getDepth(root) << endl;

    root = deleteNode(root, 50);
    cout << "After deleting 50 (In-order): ";
    display(root);
    cout << endl;

    return 0;
}
