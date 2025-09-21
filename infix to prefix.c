//WAP to convert infix to prefix.
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

// Reverse a string
void reverse(char str[]) {
    int i=0, j=strlen(str)-1;
    char temp;
    while(i<j) {
        temp=str[i]; str[i]=str[j]; str[j]=temp;
        i++; j--;
    }
}

int main() {
    char infix[MAX], prefix[MAX], temp[MAX];
    int i,j=0;
    printf("Enter infix expression: ");
    gets(infix);

    reverse(infix);
    for(i=0;infix[i];i++) {
        if(infix[i]=='(') infix[i]=')';
        else if(infix[i]==')') infix[i]='(';
    }

    for(i=0;infix[i];i++) {
        if(isalnum(infix[i])) temp[j++]=infix[i];
        else if(infix[i]=='(') push('(');
        else if(infix[i]==')') {
            while(top!=-1 && stack[top]!='(') temp[j++]=pop();
            if(top!=-1) pop();
        } else {
            while(top!=-1 && priority(stack[top])>=priority(infix[i])) temp[j++]=pop();
            push(infix[i]);
        }
    }
    while(top!=-1) temp[j++]=pop();
    temp[j]='\0';
    reverse(temp);
    strcpy(prefix,temp);

    printf("Prefix: %s\n", prefix);
    return 0;
}
