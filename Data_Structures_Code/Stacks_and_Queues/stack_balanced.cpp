#include<iostream>
#include<string>
using namespace std;
int MAX_size = 100;
int top = -1;
int stk[100];
void push(char x) {
    if (top == MAX_size - 1) {
        cout << "Stack overflow" << endl;
        return;
    }
    stk[++top] = x;
}

char pop() {
    if (top == -1) {
        return -1;
    }
    char val = stk[top];
    top--;
    return val;
}
bool isempty(){
    return top == -1;
}
bool isMatching(char open, char close){
    return (open == '(' && close == ')') || (open == '{' && close == '}') ||
    (open == '[' && close == ']');
}
int balance(string exp){
    top = -1;
    for (int i =0;i<exp.length();i++){
        char ch = exp[i];
        if (ch == '(' || ch == '{' || ch == '['){
            push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']'){
            if(isempty()) return false;
            if (!isMatching(pop(),ch)) return false;
        }
    }
    return isempty();

}
int main(){
    string exp= "{(a+b)*[c-d]}";
    if (balance(exp)){
        cout<<"balanced";
    }
    else{
            cout<<"unbalanced";
        }
    return 0;
    }
