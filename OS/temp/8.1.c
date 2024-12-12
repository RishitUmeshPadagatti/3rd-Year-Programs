// Single Level Directory

#include <stdio.h>
int main()
{
    int master, s[20];
    char f[20][20][20];
    char d[20][20];
    int i, j;
    printf("enter number of directorios:");
    scanf("%d", &master);
    printf("enter names of directories:");
    for (i = 0; i < master; i++)
        scanf("%s", &d[i]);
    printf("enter size of directories:");
    for (i = 0; i < master; i++)
        scanf("%d", &s[i]);
    printf("enter the file names :");
    for (i = 0; i < master; i++)
        for (j = 0; j < s[i]; j++)
            scanf("%s", &f[i][j]);
    printf("\n");
    printf(" directory\tsize\tfilenames\n");
    printf("*************************************************\n");
    for (i = 0; i < master; i++)
    {
        printf("%s\t\t%2d\t", d[i], s[i]);
        for (j = 0; j < s[i]; j++)
            printf("%s\n\t\t\t", f[i][j]);
        printf("\n");
    }
    printf("\t\n");
}


// enter number of directorios:3
// enter names of directories:a
// b
// c
// enter size of directories:2
// 4
// 3
// enter the file names :d
// e
// f
// g
// h
// i
// j
// k
// l

//  directory      size    filenames
// *************************************************
// a                2      d
//                         e

// b                4      f
//                         g
//                         h
//                         i

// c                3      j
//                         k
//                         l