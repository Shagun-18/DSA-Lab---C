//WAP for postfix expression evaluation.
#include <stdio.h>
#include <ctype.h>
#define MAX 50

int stack[MAX], top=-1;

void push(int x) { stack[++top]=x; }
int pop() { return stack[top--]; }

int main() {
    char postfix[MAX];
    int i, op1, op2;
    printf("Enter postfix expression: ");
    gets(postfix);

    for(i=0;postfix[i];i++) {
        if(isdigit(postfix[i])) push(postfix[i]-'0');
        else {
            op2=pop();
            op1=pop();
            switch(postfix[i]) {
                case '+': push(op1+op2); break;
                case '-': push(op1-op2); break;
                case '*': push(op1*op2); break;
                case '/': push(op1/op2); break;
            }
        }
    }
    printf("Result = %d\n", pop());
    return 0;
}
