// Develop a Program in C for converting an Infix Expression to Postfix Expression.
// Program should support for both parenthesized and free parenthesized expressions with
// the operators: +, -, *, /, % (Remainder), ^ (Power) and alphanumeric operands.


#include <stdio.h>
#include <stdlib.h> // for exit(0)
#include <ctype.h>  // for type of character

char postfix[50], infix[50], s[50];
int top = -1;

int precedence(char e) {
    switch (e) {
        case '#': return -1;
        case '(': return 0;
        case '+': return 1;
        case '-': return 1;
        case '*': return 2;
        case '/': return 2;
        case '%': return 2;
        case '^': return 3;
        default: printf("Invalid"); exit(0);
    }
}

void push(char e){
    s[++top] = e;
}

char pop(){
    char e = s[top--];
    return e;
}

int main(){
    int j = 0; // for 'postfix' variable

    printf("Enter the infix expression: ");
    scanf("%s", infix);

    char ch;
    push('#');
    for (int i=0; infix[i]!='\0'; i++){
        ch = infix[i];

        if (isalnum(ch))
            postfix[j++] = ch;
        else if (ch == '(')
            push(ch);
        else if (ch == ')'){
            while(s[top] != '(')
                postfix[j++] = pop();
            pop();
        }
        else{
            while(precedence(ch) <= precedence(s[top])){
                if (s[top] == '^' || ch == '^')
                    break;
                postfix[j++] = pop();
            }
            push(ch);
        }
        
    }

    while (s[top] != '#'){
        postfix[j++] = pop();
    }
    postfix[j] = '\0';

    printf("Postfix: %s\n", postfix);

    return 0;
}