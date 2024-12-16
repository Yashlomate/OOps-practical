#include <iostream>
#include <stack>
#include <string>
#include <algorithm> // For reverse and swap
using namespace std;

// Function to check precedence
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Function to convert infix to prefix
string infixToPrefix(string infix) {
    stack<char> s;
    string prefix = "";
    reverse(infix.begin(), infix.end());

    // Swap '(' and ')' in the reversed expression
    for (char& c : infix) {
        if (c == '(') c = ')';
        else if (c == ')') c = '(';
    }

    for (char c : infix) {
        if (isalnum(c)) {
            prefix = c + prefix; // Add operand to prefix
        } else if (c == '(') {
            s.push(c); // Push '(' onto stack
        } else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                prefix = s.top() + prefix; // Append operator to prefix
                s.pop();
            }
            s.pop(); // Remove '(' from stack
        } else {
            while (!s.empty() && precedence(s.top()) > precedence(c)) {
                prefix = s.top() + prefix; // Append operator to prefix
                s.pop();
            }
            s.push(c); // Push current operator
        }
    }

    while (!s.empty()) {
        prefix = s.top() + prefix; // Append remaining operators
        s.pop();
    }

    return prefix;
}

// Function to evaluate prefix expression
int evaluatePrefix(string prefix) {
    stack<int> s;
    for (int i = prefix.size() - 1; i >= 0; --i) {
        if (isdigit(prefix[i])) {
            s.push(prefix[i] - '0'); // Push operand
        } else {
            int op1 = s.top(); s.pop();
            int op2 = s.top(); s.pop();

            switch (prefix[i]) {
                case '+': s.push(op1 + op2); break;
                case '-': s.push(op1 - op2); break;
                case '*': s.push(op1 * op2); break;
                case '/': s.push(op1 / op2); break;
            }
        }
    }

    return s.top(); // Final result
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string prefix = infixToPrefix(infix);
    cout << "Prefix expression: " << prefix << endl;

    int result = evaluatePrefix(prefix);
    cout << "Evaluation result: " << result << endl;

    return 0;
}
