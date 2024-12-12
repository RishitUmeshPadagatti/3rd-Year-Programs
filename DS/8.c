// Develop a menu driven Program in C for the following operations on Doubly Linked
// List (DLL) of Employee Data with the fields: SSN, Name, Dept, Designation, Sal, PhNo
// a. Create a DLL of N Employees Data by using end insertion.
// b. Display the status of DLL and count the number of nodes in it
// c. Perform Insertion and Deletion at End of DLL
// d. Perform Insertion and Deletion at Front of DLL
// e. Demonstrate how this DLL can be used as Double Ended Queue.
// f. Exit

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char ssn[10], name[20], dept[10], desig[10], phno[10];
    int sal;
    struct node *llink;
    struct node *rlink;
} NODE;

NODE *start = NULL;

void create();
void display();
void insert_front();
void del_front();
void insert_end();
void del_end();
void enqueue();
void dqueue();
void main_menu();

int main(){
    main_menu();
    return 0;
}

void main_menu(){
    int ch;
    while(1){
        printf("\nDOUBLY LINKED LIST IMPLEMENTATION\n");
        printf("\n1. CREATE LIST\n");
        printf("\n2. DISPLAY LIST\n");
        printf("\n3. INPUT RESTRICTED QUEUE\n");
        printf("\n4. OUTPUT RESTRICTED QUEUE\n");
        printf("\n5. EXIT\n");
        printf("\nENTER YOUR CHOICE\n");
        scanf("%d", &ch);
        switch(ch){
            case 1: create(); break;
            case 2: display(); break;
            case 3: enqueue(); break;
            case 4: dqueue(); break;
            case 5: exit(0);
            default: printf("\nINVALID CHOICE\n");
        }
    }
}

void create(){
    int n;
    printf("\nEnter the number of nodes\n");
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
        insert_end();
}

void insert_end(){

}

void display(){
    NODE *curptr = NULL;
    int count = 0;
    if (start==NULL)
        printf("\nLIST EMPTY\n");
    else{
        curptr = start;
        printf("\nThe contents are\n");
        printf("\nSSN\tNAME\tDEPT\tDESIGNATION\tPHONE\tSALARY\n");
        while(curptr!=NULL){
            printf("%s\t%s\t%s\t%s\t%s\t%d\n", curptr->ssn, curptr->name, curptr->dept, curptr->desig, curptr->phno, curptr->sal);
            count++;
            curptr = curptr->rlink;
        }
        printf("TOTAL NUMBER OF NODES IS: %d\n", count);
    }
}