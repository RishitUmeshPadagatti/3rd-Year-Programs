// Evaluation of Suffix expression with single digit operands and operators: +, -, *, /, %, ^

#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAX 20

int s[MAX], top=-1;

void push(int e){
    s[++top] = e;
}

int pop(){
    int temp = s[top--];
    return temp;
}

int main(){
    char postfix[MAX], ch;
    int op1, op2, result;

    printf("Enter the postfix expression: ");
    scanf("%s", postfix);

    for (int i; postfix[i] != '\0'; i++){
        ch = postfix[i];
        if (isdigit(ch))
            push(ch - '0');
        else{
            op2 = pop();
            op1 = pop();
            switch(ch){
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                case '%': result = op1 % op2; break;
                case '^': result = (int) pow(op1, op2); break;
            }
            push(result);
        }
    }

    printf("Result: %d\n", pop());

    return 0;
}