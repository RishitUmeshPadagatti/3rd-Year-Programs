#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct node
{
    int coef;
    int x, y, z;
    struct node *link;
} NODE;

NODE *getnode()
{
    NODE *x;
    x = (NODE *)malloc(sizeof(NODE));
    return x;
}
NODE *readpoly()
{
    NODE *temp, *head, *cur;
    char ch;
    head = getnode();
    head->coef = -1;
    head->x = -1;
    head->y = -1;
    head->z = -1;
    head->link = head;
    do
    {
        temp = getnode();
        printf("\nEnter the coefficient \n");
        scanf("%d", &temp->coef);
        printf("\nEnter the  exponent of x , y and Z in decreasing order\n");
        scanf("%d%d%d", &temp->x, &temp->y, &temp->z);
        cur = head;
        while (cur->link != head)
            cur = cur->link;
        cur->link = temp;
        temp->link = head;
        printf("\nDo you want to enter more coefficients(y/n)");
        ch = getchar();
        scanf("%c", &ch);
    } while (ch == 'y' || ch == 'Y');
    return head;
}
int compare(NODE *a, NODE *b)
{
    if (a->x > b->x)
        return 1;
    else if (a->x < b->x)
        return -1;
    else if (a->y > b->y)
        return 1;
    else if (a->y < b->y)
        return -1;
    else if (a->z > b->z)
        return 1;
    else if (a->z < b->z)
        return -1;
    return 0;
}
void attach(int cf, int x1, int y1, int z1, NODE **ptr)
{
    NODE *temp;
    temp = getnode();
    temp->coef = cf;
    temp->x = x1;
    temp->y = y1;
    temp->z = z1;
    (*ptr)->link = temp;
    *ptr = temp;
}
NODE *addpoly(NODE *a, NODE *b)
{
    NODE *starta, *c, *lastc;
    int sum, done = 0;
    starta = a;
    a = a->link;
    b = b->link;
    c = getnode();
    c->coef = -1;
    c->x = -1;
    c->y = -1;
    c->z = -1;
    lastc = c;
    do
    {
        switch (compare(a, b))
        {
        case -1:
            attach(b->coef, b->x, b->y, b->z, &lastc);
            b = b->link;
            break;
        case 0:
            if (starta == a)
                done = 1;
            else
            {
                sum = a->coef + b->coef;
                if (sum)
                    attach(sum, a->x, a->y, a->z, &lastc);
                a = a->link;
                b = b->link;
            }
            break;
        case 1:
            if (starta == a)
                done = 1;
            attach(a->coef, a->x, a->y, a->z, &lastc);
            a = a->link;
            break;
        }
    } while (!done);
    lastc->link = c;
    return c;
}
void print(NODE *ptr)
{
    NODE *cur;
    cur = ptr->link;
    while (cur != ptr)
    {
        printf("%d*x^%d*y^%d*z^%d", cur->coef, cur->x, cur->y, cur->z);
        cur = cur->link;
        if (cur != ptr)
            printf(" + ");
    }
}
void evaluate(NODE *ptr)
{
    int res = 0;
    int x, y, z, ex, ey, ez, cof;
    NODE *cur;
    printf("\nEnter the values of x, y,z");
    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%d", &z);
    cur = ptr->link;
    while (cur != ptr)
    {
        ex = cur->x;
        ey = cur->y;
        ez = cur->z;
        cof = cur->coef;
        res += cof * pow(x, ex) * pow(y, ey) * pow(z, ez);
        cur = cur->link;
    }
    printf("\nresult: %d", res);
}
int main()
{

    int i, ch;
    NODE *a = NULL, *b, *c;
    while (1)
    {
        printf("\n1: Evaluate a Polynomial");
        printf("\n2: Adding 2 polynomial");
        printf("\n3: Exit");
        printf("\n Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the elements of the polynomial A");

            a = readpoly();
            printf("\nThe Polynomial is");
            print(a);
            evaluate(a);
            break;
        case 2:
            printf("\nEnter  first polynomials");
            a = readpoly();
            printf("\nThe Polynomial is");
            print(a);
            printf("\n Enter second polynomial");
            b = readpoly();
            printf("\nThe Polynomial is");
            print(b);
            c = addpoly(a, b);
            printf("\nThe sum of two polynomials is: ");
            print(c);
            printf("\n");
            break;
        case 3:
            return 0;
        default:
            printf("\nInvalid choice!\n");
        }
    }

    return 0;
}