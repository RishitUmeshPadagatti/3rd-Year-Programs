// Develop a menu driven Program in C for the following operations on STACK
// of Integers (Array Implementation of Stack with maximum size MAX)
// a. Push an Element on to Stack
// b. Pop an Element from Stack
// c. Demonstrate how Stack can be used to check Palindrome
// d. Demonstrate Overflow and Underflow situations on Stack
// e. Display the status of Stack
// f. Exit
// Support the program with appropriate functions for each of the above
// operations

#include <stdio.h>
#include <stdlib.h>

#define smax 5

int stack[smax], top=-1;

void push(){
    if (top == smax-1){
        printf("Stack Overflow!");
    }
    else{
        int num;
        printf("Enter the number to push: ");
        scanf("%d", &num);
        stack[++top] = num;
    }
}
void pop(){
    if (top == -1){
        printf("Stack Underflow!");
    }
    else{
        int temp = stack[top--];
        printf("The deleted element is: %d", temp);
    }
}
void palin(){
    if (top==-1 || top==0){
        printf("\nPalindrome Cannot be Checked");
    }
    else{
        int revstack[smax];
        int j=0;
        int flag=1; // 1 - True
        for (int i=top; i>=0; i--, j++)
            revstack[j]=stack[i];
        for (int i=0; i<=top; i++){
            if (revstack[i] != stack[i]){
                flag=0;
                break;
            }
        }
        
        if (flag){
            printf("Palindrome");
        }
        else{
            printf("Not a Palindrome");
        }
    }
}
void display(){
    if (top == -1){
        printf("Stack Empty");
    }
    else{
        printf("Stack Contents\n");
        for (int i=top; i>=0; i--){
            printf("%d\n", stack[i]);
        }
    }
}

int main(){
    int ch;
    while(1){
        printf("\n\nSTACK MENU");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Check Palindrome");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1: push(); break;
            case 2: pop(); break;
            case 3: palin(); break;
            case 4: display(); break;
            case 5: exit(0);
            default:printf("\nInvalid Input");
        }
    }

    return 1;
}