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
    char ssn[10], name[20], dept[20], desig[20], phno[11];
    int sal;
    struct node *llink;
    struct node *rlink;
} NODE;
NODE *start = NULL;

void main_menu();
void create();
void display();
void enqueue();
void dequeue();
void insert_front();
void insert_end();
void delete_front();
void delete_end();

int main(){
    main_menu();
    
    return 0;
}

void main_menu(){
    int ch;
    while(1){
        printf("\n\nDOUBLY LINKED LIST IMPLEMENTATION");
        printf("\n1. CREATE LIST");
        printf("\n2. DISPLAY");
        printf("\n3. ENQUEUE");
        printf("\n4. DEQUEUE");
        printf("\n5. EXIT");
        printf("\nENTER YOUR CHOICE: ");
        scanf("%d", &ch);
        switch(ch){
            case 1: create(); break;
            case 2: display(); break;
            case 3: enqueue(); break;
            case 4: dequeue(); break;
            case 5: exit(0);
        }
    }
}

void create(){
    int n;
    printf("Enter the number of nodes to create: ");
    scanf("%d", &n);
    for (int i=0; i<n; i++)
        insert_end();
}

void display(){
    if (start == NULL)
        printf("No nodes to display\n");
    else{
        NODE *curptr = start;
        printf("SSN\tNAME\tDEPARTMENT\tDESIGNATION\tPHONE\tSALARY\n");
        while(curptr != NULL){
            printf("%s\t%s\t%s\t%s\t%s\t%d\n", curptr->ssn, curptr->name, curptr->dept, curptr->desig, curptr->phno, curptr->sal);
            curptr = curptr->rlink;
        }
    }
}

void enqueue(){
    int ch;
    while(1){
        printf("\nENQUEUE");
        printf("\n1. INSERT FRONT");
        printf("\n2. DELETE FRONT");
        printf("\n3. DELETE END");
        printf("\n4. DISPLAY");
        printf("\n5. EXIT");
        printf("\nENTER YOUR CHOICE: ");
        scanf("%d", &ch);
        switch(ch){
            case 1: insert_front(); break;
            case 2: delete_front(); break;
            case 3: delete_end(); break;
            case 4: display(); break;
            case 5: main_menu(); break;
        }
    }
}

void dequeue(){
    int ch;
    while(1){
        printf("\nDEQUEUE");
        printf("\n1. INSERT FRONT");
        printf("\n3. INSERT END");
        printf("\n2. DELETE END");
        printf("\n4. DISPLAY");
        printf("\n5. EXIT");
        printf("\nENTER YOUR CHOICE: ");
        scanf("%d", &ch);
        switch(ch){
            case 1: insert_front(); break;
            case 2: insert_end(); break;
            case 3: delete_end(); break;
            case 4: display(); break;
            case 5: main_menu(); break;
        }
    }
}

void insert_front(){
    NODE *newnode = (NODE*)malloc(sizeof(NODE));
    printf("Enter SSN, name, department, designation, phone and salary\n");
    scanf("%s%s%s%s%s%d", newnode->ssn, newnode->name, newnode->dept, newnode->desig, newnode->phno, &newnode->sal);
    if (start == NULL){
        newnode->rlink = NULL;
        newnode->llink = NULL;
        start = newnode;
    }
    else{
        newnode->rlink = start;
        newnode->llink = NULL;
        start->llink = newnode;
        start = newnode;
    }
}

void insert_end(){
    NODE *curptr = NULL;
    NODE *newnode = (NODE*)malloc(sizeof(NODE));
    printf("Enter SSN, name, department, designation, phone and salary\n");
    scanf("%s%s%s%s%s%d", newnode->ssn, newnode->name, newnode->dept, newnode->desig, newnode->phno, &newnode->sal);
    if (start == NULL){
        newnode->llink = NULL;
        newnode->rlink = NULL;
        start = newnode;
    }
    else{
        curptr = start;
        while(curptr->rlink != NULL)
            curptr = curptr->rlink;
        newnode->llink = curptr;
        newnode->rlink = NULL;
        curptr->rlink = newnode;
    }
}

void delete_front(){
    if (start == NULL)
        printf("Nothing to delete!");
    else if (start->rlink == NULL){
        NODE *curptr = start;
        printf("\nThe deleted information is");
        printf("\nSSN\tNAME\tDEPARTMENT\tDESIGNATION\tPHONE\tSALARY");
        printf("\n%s\t%s\t%s\t%s\t%s\t%d\n", curptr->ssn, curptr->name, curptr->dept, curptr->desig, curptr->phno, curptr->sal);
        start = NULL;
        free(curptr);
    }
    else {
        NODE *curptr = start;
        printf("\nThe deleted information is");
        printf("\nSSN\tNAME\tDEPARTMENT\tDESIGNATION\tPHONE\tSALARY");
        printf("\n%s\t%s\t%s\t%s\t%s\t%d\n", curptr->ssn, curptr->name, curptr->dept, curptr->desig, curptr->phno, curptr->sal);
        start = start->rlink;
        start->llink = NULL;
        free(curptr);
    }
}

void delete_end(){
    if (start == NULL)
        printf("Nothing to delete!");
    else if (start->rlink == NULL){
        NODE *curptr = start;
        printf("\nThe deleted information is");
        printf("\nSSN\tNAME\tDEPARTMENT\tDESIGNATION\tPHONE\tSALARY");
        printf("\n%s\t%s\t%s\t%s\t%s\t%d\n", curptr->ssn, curptr->name, curptr->dept, curptr->desig, curptr->phno, curptr->sal);
        start = NULL;
        free(curptr);
    }
    else{
        NODE *curptr = start;
        while(curptr->rlink != NULL)
            curptr = curptr->rlink;
        curptr->llink->rlink = NULL;
        printf("\nThe deleted information is");
        printf("\nSSN\tNAME\tDEPARTMENT\tDESIGNATION\tPHONE\tSALARY");
        printf("\n%s\t%s\t%s\t%s\t%s\t%d\n", curptr->ssn, curptr->name, curptr->dept, curptr->desig, curptr->phno, curptr->sal);
        free(curptr);
    }
}