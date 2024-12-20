// Given a File of N employee records with a set K of Keys (4-digit) which uniquely
// determine the records in file F. Assume that file F is maintained in memory by a Hash
// Table (HT) of m memory locations with L as the set of memory addresses (2-digit) of
// locations in HT. Let the keys in K and addresses in L are Integers. Develop a Program
// in C that uses Hash function H: K →L as H(K)=K mod m (remainder method), and
// implement hashing technique to map a given key K to the address space L. Resolve the
// collision (if any) using linear probing

#include <stdio.h>
#include <stdlib.h>

int n;                                  // Number of records
int m;                                  // Hash Table size
int *ht, count = 0, key[20];
int hashIndex;

void insert(int key){
    if (count == m){
        printf("Hash Table is full and Record cannot be inserted");
    }
    else{
        hashIndex = key % m;
        if (ht[hashIndex] != -1){
            printf("Collision Detected\n");
            while (ht[hashIndex] != -1)
                hashIndex = (hashIndex+1) % m;
        }
        ht[hashIndex] = key;
        count++;
    }
}

void display(){
    int i;
    if (count == 0){
        printf("\nHash table is empty");
        return;
    }
    printf("\nHash Table contents are: \n");
    for (i=0; i<n; i++)
        printf("\nT[%d]-->%d", i, ht[i]);
}

int main(){
    printf("\nEnter the number of employee records: ");
    scanf("%d", &n);
    printf("\nEnter the size of the hash table: ");
    scanf("%d", &m);

    ht = (int *)malloc(m*sizeof(int));
    for (int i=0; i<m; i++)
        ht[i] = -1;

    printf("Enter the four digit key values for N Employee Records\n");
    for (int i=0; i<n; i++){
        scanf("%d", &key[i]);
        insert(key[i]);
    }

    display();

    return 0;
}