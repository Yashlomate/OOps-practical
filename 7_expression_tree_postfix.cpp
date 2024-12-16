#include <iostream>
#include <stack>
using namespace std;

struct Node {
    char data;
    Node *left, *right;
    Node(char val) : data(val), left(nullptr), right(nullptr) {}
};

Node* buildTree(string postfix) {
    stack<Node*> s;
    for (char c : postfix) {
        Node* node = new Node(c);
        if (!isalnum(c)) {
            node->right = s.top(); s.pop();
            node->left = s.top(); s.pop();
        }
        s.push(node);
    }
    return s.top();
}

void inorder(Node* root) {
    if (root) { inorder(root->left); cout << root->data << " "; inorder(root->right); }
}

void preorder(Node* root) {
    if (root) { cout << root->data << " "; preorder(root->left); preorder(root->right); }
}

void postorder(Node* root) {
    if (root) { postorder(root->left); postorder(root->right); cout << root->data << " "; }
}

int main() {
    string postfix;
    cout << "Enter postfix expression: ";
    cin >> postfix;

    Node* root = buildTree(postfix);

    cout << "Inorder: "; inorder(root); cout << endl;
    cout << "Preorder: "; preorder(root); cout << endl;
    cout << "Postorder: "; postorder(root); cout << endl;

    return 0;
}
