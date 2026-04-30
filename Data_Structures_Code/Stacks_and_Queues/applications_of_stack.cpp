#include <iostream>
#include <string>
using namespace std;

// Global Stack Variables (Easiest for beginners to access)
int stack_size = 100;
char arr[100]; // Our stack
int top = -1;

void push(char x) {
    if (top == stack_size - 1) {
        cout << "Stack overflow" << endl;
        return;
    }
    arr[++top] = x;
}

char pop() {
    if (top == -1) {
        return -1;
    }
    char val = arr[top];
    top--;
    return val;
}

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

void infixtopostfix(string expr) {
    string postfix_exp = "";
    top = -1; // Reset stack for this operation

    for (int i = 0; i < expr.length(); i++) {
        char c = expr[i];

        // 1. If it's a letter or number, add to output
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            postfix_exp += c;
        }
        // 2. If '(', push it
        else if (c == '(') {
            push(c);
        }
        // 3. If ')', pop everything until '('
        else if (c == ')') {
            while (top != -1 && arr[top] != '(') {
                postfix_exp += pop();
            }
            pop(); // Remove the '(' from stack
        }
        // 4. If it's an operator
        else {
            while (top != -1 && precedence(arr[top]) >= precedence(c)) {
                postfix_exp += pop();
            }
            push(c);
        }
    }

    // Pop anything left in the stack
    while (top != -1) {
        postfix_exp += pop();
    }

    cout << "Postfix expression: " << postfix_exp << endl;
}

int main() {
    string expr;
    cout << "Enter Infix expression: ";
    cin >> expr; 
    infixtopostfix(expr);
    return 0;
}