// Circle Queue of characters

#include <stdio.h>
#include <stdlib.h>

#define max 5

int q[max], f = -1, r = -1;

void insert(){
    if (f == (r+1)%max)
        printf("Queue Overflow\n");
    else{
        if (f == -1)
            f = 0;
        r = (r + 1) % max;
        int num;
        printf("Enter the number to insert: ");
        scanf("%d", &num);
        q[r] = num;
    }
}

void delete(){
    if (r == -1)
        printf("Queue Underflow");
    else{
        printf("Deleted Element: %d", q[f]);
        if (f==r)
            f = r = -1;
        else{
            f = (f + 1) % max;
        }
    }
}

void display(){
    if (f == -1)
        printf("Queue Empty");
    else {
        int i;
        printf("\tQUEUE CONTENTS\n");
        for (i=f; i!=r; i=(i+1)%max){
            printf("%d\t", q[i]);
        }
        printf("%d", q[i]);
    }
}

int main(){
    int ch;
    printf("\nCircular Queue Operations");
    printf("\n1. Insert");
    printf("\n2. Delete");
    printf("\n3. Display");
    printf("\n4. Exit");
    while(1){
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: exit(0);
            default:printf("Invalid choice");
        }
    }

    return 0;
}