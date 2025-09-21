//WAP for prefix expression evaluation.
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 50

int stack[MAX], top=-1;

void push(int x) { stack[++top]=x; }
int pop() { return stack[top--]; }

int main() {
    char prefix[MAX];
    int i, op1, op2;
    printf("Enter prefix expression: ");
    gets(prefix);

    for(i=strlen(prefix)-1;i>=0;i--) {
        if(isdigit(prefix[i])) push(prefix[i]-'0');
        else {
            op1=pop();
            op2=pop();
            switch(prefix[i]) {
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
