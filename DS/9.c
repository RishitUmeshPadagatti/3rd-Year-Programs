// Develop a Program in C for the following operations on Singly Circular Linked List (SCLL) with header nodes a. Represent and Evaluate 
// a Polynomial P(x,y,z) = 6x 2 y 2 z-4yz 5 +3x 3 yz+2xy 5 z-2xyz 3 
// b. Find the sum of two polynomials POLY1(x,y,z) and POLY2(x,y,z) and store the result in POLYSUM(x,y,z) 
// Support the program with appropriate functions for each of the above operations

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdlib.h>

typedef struct node{
    int coef;
    int x, y, z;
    struct node* link;
} NODE;

NODE* getnode(){
    NODE *x = (NODE *)malloc(sizeof(NODE));
    return x;
}

NODE* readpoly(){
    NODE* temp, *head, *cur;
    char ch;
    head = getnode();
    head->coef = -1;
    head->x = -1;
    head->y = -1;
    head->z = -1;
    head->link = head;
    do{
        temp = getnode();
        printf("\nEnter the coefficient: ");
        scanf("%d", &temp->coef);
        printf("Enter the exponents of x, y and x in order: ");
        scanf("%d%d%d", &temp->x, &temp->y, &temp->z);
        printf("Do you want to enter more coefficients(y/n): ");
        scanf("%s", &ch);
        cur = head;
        while (cur->link != head)
            cur = cur->link;
        cur->link = temp;
        temp->link = head;
    } while(ch == 'y' || ch == 'Y');
    return head;
}

void print(NODE *ptr){
    NODE *cur;
    cur = ptr->link;
}

int main(){
    int ch;
    while(1){
        printf("\n1. Evaluate a Polynomial");
        printf("\n2. Adding 2 Polynomials");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1: printf("\nEnter the elements of the polynomial A");
                    NODE* a = readpoly();
                    printf("\nThe Polynomial is: ");
                    print(a);
                    break;

            case 3: exit(0);
        }
    }
    
    return 0;
}