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
    while(cur != ptr){
        printf("%d * x^%d * y^%d * z^%d", cur->coef, cur->x, cur->y, cur->z);
        cur = cur->link;
        if (cur != ptr){
            printf(" + ");
        }
    }
}

void evaluate(NODE* ptr){
    int res = 0;
    int x, y, z, ex, ey, ez, cof;
    NODE *cur;
    printf("\nEnter the values of x, y and z: ");
    scanf("%d%d%d", &x, &y, &z);
    cur = ptr->link;
    while (cur != ptr){
        ex = cur->x;
        ey = cur->y;
        ez = cur->z;
        cof = cur->coef;
        res += cof * pow(x, ex) * pow(y, ey) * pow(z, ez);
        cur = cur->link;
    }
    printf("Result: %d\n", res);
}

int compare(NODE *a, NODE *b){
    if (a->x > b->x) return 1;
    else if (a->x < b->x) return -1;
    else if (a->y > b->y) return 1;
    else if (a->y < b->y) return -1;
    else if (a->z > b->z) return 1;
    else if (a->z < b->z) return -1;
    return 0;
}

NODE* addpoly(NODE *a, NODE *b){
    NODE *starta, *c, *lastc, *temp;
    int sum, done = 0;
    starta = a;
    a = a->link;
    b = b->link;

    c = getnode();
    c->coef = -1;
    c->x = -1;
    c->y = -1;
    c->z = -1;
    c->link = c;  // Circular Linked List
    lastc = c;

    do{
        temp = getnode();
        switch(compare(a, b)){
            case -1:temp->coef = b->coef;
                    temp->x = b->x;
                    temp->y = b->y;
                    temp->z = b->z;
                    b = b->link;
                    break;
            case 0: if (starta == a){
                        done = 1;
                        free(temp);
                        continue;
                    }
                    else{
                        sum = a->coef + b->coef;
                        if (sum){
                            temp->coef = sum;
                            temp->x = a->x;
                            temp->y = a->y;
                            temp->z = a->z;
                        }
                        else{
                            // skips terms with 0 coef
                            free(temp);
                            a = a->link;
                            b = b->link;
                            continue;
                        }

                        a = a->link;
                        b = b->link;
                    }
                    break;
            case 1: if (a == starta){
                        done = 1;
                        free(temp);
                        continue;
                    }
                    temp->coef = a->coef;
                    temp->x = a->x;
                    temp->y = a->y;
                    temp->z = a->z;
                    a = a->link;
                    break;
        }
        lastc->link = temp;
        temp->link = c;  // circular
        lastc = temp;
    } while(!done);

    return c;
}

int main(){
    int ch;
    NODE *a = NULL, *b, *c;
    while(1){
        printf("\n1. Evaluate a Polynomial");
        printf("\n2. Adding 2 Polynomials");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1: printf("\nEnter the elements of the polynomial A");
                    a = readpoly();
                    printf("The Polynomial is: ");
                    print(a);
                    printf("\n");
                    evaluate(a);
                    break;
            case 2: printf("\nENTER FIRST POLYNOMIAL");
                    a = readpoly();
                    printf("The Polynomial is: ");
                    print(a);
                    printf("\n\nENTER SECOND POLYNOMIAL");
                    b = readpoly();
                    printf("The Polynomial is: ");
                    print(b);
                    c = addpoly(a, b);
                    printf("\nThe sum of two polynomial is: ");
                    print(c);
                    break;
            case 3: exit(0);
        }
    }
    
    return 0;
}