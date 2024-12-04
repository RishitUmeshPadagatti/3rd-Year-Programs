// Develop a menu driven Program in C for the following operations on Singly Linked List (SLL) of Student Data with the fields: USN, Name, Programm, Sem, PhNo
// a. Create a SLL of N Students Data by using front insertion.
// b. Display the status of SLL and count the number of nodes in it
// c. Perform Insertion / Deletion at End of SLL
// d. Perform Insertion / Deletion at Front of SLL(Demonstration of stack)
// e. Exit

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char usn[20], name[20], branch[20], phone[11];
    int sem;
    struct node *link;
} NODE;

NODE *start = NULL;

void insert_front(){
    NODE *newnode = NULL;
    newnode = (NODE *) malloc(sizeof(NODE));

    printf("Enter USN, name, branch, semester and phone number\n");
    scanf("%s%s%s%d%s", newnode->usn, newnode->name, newnode->branch, &newnode->sem, newnode->phone);

    newnode->link = start;
    start = newnode;
}

void create_list(){
    NODE *newnode = NULL;
    int n;
    printf("Enter the number of nodes\n");
    scanf("%d", &n);
    for (int i=1; i<=n; i++){
        insert_front();
    }
    
}
void stack(){
    printf("stack");
}
void insert_end(){
    printf("insert_end");
}
void del_end(){
    printf("del_end");
}
void display(){
    printf("display");
}

void main_menu(){
    int ch;
    while(1){
        printf("\nSINGLY LINKED LIST IMPLEMENTATION\n");
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

int main(){

    main_menu();
    return 0;
}