// SCAN disk scheduling algorithm

#include <stdio.h>
int main()
{
    int i, j, sum = 0, n;
    int d[20];
    int disk; // loc of head
    int temp, max;
    int dloc; // loc of disk in array
    // clrscr();
    printf("enter number of location\t");
    scanf("%d", &n);
    printf("enter position of head\t");
    scanf("%d", &disk);
    printf("enter elements of disk queue\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &d[i]);
    }
    d[n] = disk;
    n = n + 1;
    for (i = 0; i < n; i++) // sorting="" disk="" locations<="" span="">
    {
        for (j = i; j < n; j++)
        {
            if (d[i] > d[j])
            {
                temp = d[i];
                d[i] = d[j];
                d[j] = temp;
            }
        }
    }
    max = d[n];
    for (i = 0; i < n; i++) // to="" find="" loc="" of="" disc="" in="" array<="" span="">
    {
        if (disk == d[i])
        {
            dloc = i;
            break;
        }
    }
    for (i = dloc; i >= 0; i--)
    {
        printf("%d -->", d[i]);
    }
    printf("0 -->");
    for (i = dloc + 1; i < n; i++) //< span="">
    {
        printf("%d-->", d[i]);
    }
    sum = disk + max;
    printf("\nmovement of total cylinders %d", sum);
    // getch();
    return 0;
}


// enter number of location        8
// enter position of head  53
// enter elements of disk queue
// 98
// 183
// 37
// 122
// 14
// 124
// 65
// 57
// 53 -->37 -->14 -->0 -->57-->65-->98-->122-->124-->183-->
// movement of total cylinders 53