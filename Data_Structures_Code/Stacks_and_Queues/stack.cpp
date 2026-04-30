#include<iostream>
using namespace std;
class Stack{
    private:
        int top;
        int size=100;
        int stack[100];
    public:
        Stack(){
            top=-1;
        }
        void push(int x){
            if(top==size-1){
                cout<<"Stack overflow"<<endl;
                return;
            }
            stack[++top]=x;
        }
        int pop(){
            if(top==-1){
                cout<<"Stack underflow"<<endl;
                return -1;
            }
            int val=stack[top];
            top--;
            return val;
        }
        int peek(){
            if(top==-1){
                cout<<"Stack is empty"<<endl;
                return -1;
            }
            return stack[top];
        }
        void display(){
            if(top==-1){
                cout<<"Stack is empty"<<endl;
                return;
            }
            for(int i=top;i>=0;i--){
                cout<<stack[i]<<" ";
            }
            cout<<endl;
        }
        int decimalToBinary(int decimal){
            top=-1;
            if (decimal==0){
                push(0);
                return 0;
            }
            while (decimal > 0){
                push(decimal % 2);
                decimal /=2;
            
            }
            return 0;
        }

        int precedence (char c){
            if(c == '^')
                return 3;
                if (c=='*'|| c=='/')
                    return 2;
                    if (c=='+'|| c=='-')
                        return 1;
            return 0;
        }
        void infixToPostfix(string s){
            string postfix="";
            int oldTop=top;
            top=-1;
            for (int i = 0; i < s.length(); i++) {
                char c = s[i];
                if(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9') {
                    postfix += c;
                } else if(c == '(') {
                    push(c);
                } else if(c == ')') {
                    while(top != -1 && stack[top] != '(') {
                        postfix += (char) pop();
                    }
                    pop();
                } else {
                    while(top != -1 && precedence((char)stack[top]) >= precedence(c)) {
                        postfix +=(char)pop();
                    }
                    push(c);
                }
            }
            while(top != -1) {
                postfix += (char)pop();
            }
            cout << "Postfix expression: " << postfix << endl;
            
        }
        void POstfixEvaluation(string postfix){
            int Oldtop = top;
             top = -1;
            for(int i = 0; i < postfix.length();i++){
                   char c = postfix[i];
                
                if (c >= '0' && c <= '9'){
                    push(c -'0');
                }
                else if(c == '*' ||c == '/' || c == '+' || c == '-'){
                    int first = pop();
                    int second = pop();
                    int result;
                    if(c == '*'){
                        result = second * first;
                    }
                    else if(c == '/'){
                        result = second / first;
                    }
                    else if(c == '+'){
                        result = second + first;
                    }
                    else if(c == '-'){
                        result = second - first;
                    }
                    push(result);
                }
            }
            int EvaluatedAnswer = pop();
            cout << "Evaluated answer: " << EvaluatedAnswer<< endl;
                top = Oldtop;
}
};
    int main(){
     int c, val;
     Stack s;
     string expr;
        cout<<"==== Stack Menu ====\n1) Push\n2) Pop\n3) Display\n4) Decimal to Binary\n5) Infix to Postfix\n6) Postfix Evaluation \n7) Exit"<<endl;
        do
        {
            cout<<"\nEnter choice: ";
            cin>>c;
            switch(c){
                case 1: 
                    cout<<"Value: "; cin>>val; 
                    s.push(val); break;
                case 2: 
                    s.pop(); break;
                case 3:
                    s.display(); break;
                case 4:
                    cout<<"Decimal: "; cin>>val;
                     s.decimalToBinary(val); break;
                case 5:
                    cout<<"Infix expression: "; cin>>expr; 
                    s.infixToPostfix(expr); break;
                case 6:
                    cout<<"postfix Expression: "; cin>>expr;
                     s.POstfixEvaluation(expr); break;
                case 7:
                    cout<<"Exiting..."<<endl; break;
                default:
                    cout<<"Invalid choice"<<endl;
            }
        } while (c != 7);
        

        return 0;   }