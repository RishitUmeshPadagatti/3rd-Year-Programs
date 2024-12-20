// Develop a menu driven Program in C for the following operations on Binary Search Tree (BST) of Integers .
// a. Create a BST of N Integers: 6, 9, 5, 2, 8, 15, 24, 14, 7, 8, 5, 2
// b. Traverse the BST in Inorder, Preorder and Post Order
// c. Search the BST for a given element (KEY) and report the appropriate message
// d. Exit

#include <stdio.h>
#include <stdlib.h>

struct BST {
    int data;
    struct BST *lchild;
    struct BST *rchild;
};
typedef struct BST *NODE;

NODE create(){
    NODE temp = (NODE)malloc(sizeof(struct BST));
    printf("Enter the value: ");
    scanf("%d", &temp->data);
    temp->lchild = NULL;
    temp->rchild = NULL;
    return temp;
}

void insert(NODE root, NODE newnode){
    if (newnode->data < root->data){
        if (root->lchild == NULL)
            root->lchild = newnode;
        else 
            insert(root->lchild, newnode);
    }
    else if (newnode->data > root->data){
        if (root->rchild == NULL)
            root->rchild = newnode;
        else
            insert(root->rchild, newnode);
    }
}

void search(NODE root){
    NODE cur;
    int key;
    if (root==NULL){
        printf("BST is empty");
        return;
    }
    printf("\nEnter element to be searched: ");
    scanf("%d", &key);
    
    cur = root;
    while(cur != NULL){
        if (key == cur->data){
            printf("Element Found!");
            return;
        }
        if (key < cur->data){
            cur = cur->lchild;
        }
        else{
            cur = cur->rchild;
        }
    }
    printf("Element not found");
}

void preorder(NODE root){
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->lchild);
    preorder(root->rchild);
};

void inorder(NODE root){
    if (root == NULL) return;
    inorder(root->lchild);
    printf("%d ", root->data);
    inorder(root->rchild);
}

void postorder(NODE root){
    if (root == NULL) return;
    postorder(root->lchild);
    postorder(root->rchild);
    printf("%d ", root->data);
}

int main(){
    int ch, i, n;
    NODE root = NULL, newnode;

    while(1){
        printf("\n\n-----BST MENU-----");
        printf("\n1. Create a BST");
        printf("\n2. Search");
        printf("\n3. BST Traversal");
        printf("\n4. Exit\n");
        scanf("%d", &ch);
        switch(ch){
            case 1: printf("\nEnter the number of elements: ");
                    scanf("%d", &n);
                    for(i=0; i<n; i++){
                        newnode = create();
                        if (root == NULL){
                            root = newnode;
                        }
                        else{
                            insert(root, newnode);
                        }
                    }
                    break;
            case 2: search(root); 
                    break;
            case 3: if (root == NULL)
                        printf("\nTree is not created");
                    else{
                        printf("\nThe Preorder display: ");
                        preorder(root);
                        printf("\nThe Inorder display: ");
                        inorder(root);
                        printf("\nThe Postorder display: ");
                        postorder(root);
                    }
                    break;
            case 4: exit(0);
        }
    }

    return 0;
}