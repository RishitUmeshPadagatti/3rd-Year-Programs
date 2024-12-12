// Develop a menu driven Program in C for the following operations on Singly Linked List (SLL) of Student Data with the fields: USN, Name, Programm, Sem, PhNo
// a. Create a SLL of N Students Data by using front insertion.
// b. Display the status of SLL and count the number of nodes in it
// c. Perform Insertion / Deletion at End of SLL
// d. Perform Insertion / Deletion at Front of SLL(Demonstration of stack)
// e. Exit

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char usn[20], name[20], branch[20], phno[11];
    int sem;
    struct node *link;
} NODE;

NODE *start = NULL;

void main_menu();
void create_list();
void display();
void stack();
void insert_front();
void del_front();
void insert_end();
void del_end();

int main(){
    main_menu();

    return 0;
}

void main_menu(){
    int ch;
    while (1){
        printf("\n\nSINGLY LINKED LIST IMPLEMENTATION\n");
        printf("\n1. CREATE LIST\n");
        printf("\n2. INSERTION AND DELETION FROM FRONT (STACK)\n");
        printf("\n3. INSERT END\n");
        printf("\n4. DELETE END\n");
        printf("\n5. DISPLAY\n");
        printf("\n6. EXIT\n");
        printf("\nENTER YOUR CHOICE\n");
        scanf("%d", &ch);
        switch(ch){
            case 1: create_list(); break;
            case 2: stack(); break;
            case 3: insert_end(); break;
            case 4: del_end(); break;
            case 5: display(); break;
            case 6: exit(0);
            default: printf("\nINVALID CHOICE\n");
        } 
    }
}

void create_list(){
    int n;
    printf("enter number of nodes: ");
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
        insert_front();
    
}
void display(){
    NODE *curptr = NULL;
    if (start==NULL)
        printf("\nLIST EMPTY\n");
    else {
        int count = 0;
        curptr = start;
        printf("\nUSN\tNAME\tBRANCH\tPHONE\tSEM\n");
        while(curptr!=NULL){
            printf("%s\t%s\t%s\t%s\t%d\n", curptr->usn, curptr->name, curptr->branch, curptr->phno, curptr->sem);
            curptr = curptr->link;
            count++;
        }
        printf("NUMBER OF NODES: %d", count);
        
    }
        
}
void stack(){
    int ch;
    while(1){
        printf("\nStack Implementation\n");
        printf("\n1. Insert Front\n");
        printf("\n2. Delete Front\n");
        printf("\n3. Display\n");
        printf("\n4. Exit from Stack Menu\n");
        printf("\nEnter your choice\n");
        scanf("%d", &ch);
        switch(ch){
            case 1: insert_front(); break;
            case 2: del_front(); break;
            case 3: display(); break;
            case 4: main_menu(); break;
            default: printf("\nINVALID CHOICE\n");
        }
    }
}
void insert_front(){
    NODE *newnode = NULL;
    newnode = (NODE *)malloc(sizeof(NODE));
    printf("\nEnter USN, name, branch, phone number and semester\n");
    scanf("%s%s%s%s%d", newnode->usn, newnode->name, newnode->branch, newnode->phno, &newnode->sem);
    newnode->link = start;
    start = newnode;
}
void del_front(){
    NODE *curptr = NULL;
    if (start==NULL)
        printf("\nLIST EMPTY\n");
    else {
        curptr = start;
        start = start->link;
        printf("The deleted information is\n");
        printf("\nUSN\tNAME\tBRANCH\tPHONE\tSEM\n");
        printf("%s\t%s\t%s\t%s\t%d\n", start->usn, start->name, start->branch, start->phno, start->sem);
        free(curptr);
    }
}
void insert_end(){
    NODE *curptr, *newnode=NULL;
    newnode = (NODE *)malloc(sizeof(NODE));
    printf("\nEnter USN, name, branch, phone number and semester\n");
    scanf("%s%s%s%s%d", newnode->usn, newnode->name, newnode->branch, newnode->phno, &newnode->sem);
    
    if (start==NULL){
        newnode->link = start; // newnode->link = NULL;
        start = newnode;
    }
    else{
        curptr = start;
        while(curptr->link != NULL)
            curptr = curptr->link;
        newnode->link = NULL;
        curptr->link = newnode;
    }
    
}
void del_end(){
    NODE *curptr=NULL, *prevptr=NULL;
    if (start==NULL)
        printf("\nLIST EMPTY\n");
    else if (start->link == NULL){
        printf("The deleted information is\n");
        printf("\nUSN\tNAME\tBRANCH\tPHONE\tSEM\n");
        printf("%s\t%s\t%s\t%s\t%d\n", start->usn, start->name, start->branch, start->phno, start->sem);
        free(start);
        start = NULL;
    }
    else{
        curptr = start;
        prevptr = curptr;
        while(curptr->link != NULL){
            prevptr = curptr;
            curptr = curptr->link;
        }
        prevptr->link = NULL;
        printf("The deleted information is\n");
        printf("\nUSN\tNAME\tBRANCH\tPHONE\tSEM\n");
        printf("%s\t%s\t%s\t%s\t%d\n", curptr->usn, curptr->name, curptr->branch, curptr->phno, curptr->sem);
        free(curptr);
    }
}