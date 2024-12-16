#include <iostream>
#include <stack>
using namespace std;

// Node structure for Expression Tree
struct Node {
    char data;
    Node* left;
    Node* right;
};

// Create a new node
Node* createNode(char data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Construct Expression Tree from prefix expression
Node* constructTree(string prefix) {
    stack<Node*> s;
    for (int i = prefix.size() - 1; i >= 0; i--) {
        if (isalpha(prefix[i])) {
            s.push(createNode(prefix[i]));
        } else {
            Node* node = createNode(prefix[i]);
            node->left = s.top(); s.pop();
            node->right = s.top(); s.pop();
            s.push(node);
        }
    }
    return s.top();
}

// In-order traversal (Recursive)
void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Pre-order traversal (Recursive)
void preorder(Node* root) {
    if (root) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Post-order traversal (Recursive)
void postorder(Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    string prefix;  // Example prefix expression
    cout << "Enter prefix expression: ";
    cin >> prefix;
    Node* root = constructTree(prefix);

    cout << "In-order: ";
    inorder(root);
    cout << endl;

    cout << "Pre-order: ";
    preorder(root);
    cout << endl;

    cout << "Post-order: ";
    postorder(root);
    cout << endl;

    return 0;
}
