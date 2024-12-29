// Solving Tower of Hanoi problem with n disk

#include <stdio.h>


int count = 0;
// n, source, auxillary, destination
void TOH(int n, char A, char B, char C){
    if (n > 0){
        TOH(n-1, A, C, B);
        printf("Move disc %d from %c to %c\n", n, A, C);
        count++;
        TOH(n-1, B, A, C);
    }
}

int main(){
    int n;
    printf("Number of discs: ");
    scanf("%d", &n);
    TOH(n, 'A', 'B', 'C');
    printf("Total number of moves: %d\n", count);

    return 0;
}