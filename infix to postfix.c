//WAP to convert infix to postfix.
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 50

char stack[MAX];
int top=-1;

void push(char x) { stack[++top]=x; }
char pop() { return stack[top--]; }
int priority(char x) {
    if(x=='+'||x=='-') return 1;
    if(x=='*'||x=='/') return 2;
    if(x=='^') return 3;
    return 0;
}

int main() {
    char infix[MAX], postfix[MAX];
    int i,j=0;
    printf("Enter infix expression: ");
    gets(infix);

    for(i=0;infix[i];i++) {
        if(isalnum(infix[i])) postfix[j++]=infix[i];
        else if(infix[i]=='(') push('(');
        else if(infix[i]==')') {
            while(top!=-1 && stack[top]!='(') postfix[j++]=pop();
            if(top!=-1) pop();
        } else {
            while(top!=-1 && priority(stack[top])>=priority(infix[i])) postfix[j++]=pop();
            push(infix[i]);
        }
    }
    while(top!=-1) postfix[j++]=pop();
    postfix[j]='\0';

    printf("Postfix: %s\n", postfix);
    return 0;
}
