// Linked File Allocation

#include <stdio.h>
struct file
{
    char fname[10];
    int start, size, block[10];
} f[10];
int main()
{
    int i, j, n;
    // clrscr(); 
    printf("Enter no. of files:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter file name:");
        scanf("%s", &f[i].fname);
        printf("Enter starting block:");
        scanf("%d", &f[i].start);
        f[i].block[0] = f[i].start;
        printf("Enter no.of blocks:");
        scanf("%d", &f[i].size);
        printf("Enter block numbers:");
        for (j = 1; j <= f[i].size; j++)
        {
            scanf("%d", &f[i].block[j]);
        }
    }
    printf("File\tstart\tsize\tblock\n");
    for (i = 0; i < n; i++)
    {
        printf("%s\t%d\t%d\t", f[i].fname, f[i].start, f[i].size);
        for (j = 1; j <= f[i].size - 1; j++)
            printf("%d--->", f[i].block[j]);
        printf("%d", f[i].block[j]);
        printf("\n");
        // getch();  
    }
}


// Enter no. of files:2
// Enter file name:a.c
// Enter starting block:23
// Enter no.of blocks:3
// Enter block numbers:12
// 45
// 2
// Enter file name:b.c
// Enter starting block:34
// Enter no.of blocks:4
// Enter block numbers:6
// 90
// 25
// 5
// File    start   size    block
// a.c     23      3       12--->45--->2
// b.c     34      4       6--->90--->25--->5