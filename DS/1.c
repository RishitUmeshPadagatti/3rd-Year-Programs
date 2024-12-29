// Develop a Program in C for the following:
// a) Declare a calendar as an array of 7 elements (A dynamically Created array) to
// represent 7 days of a week. Each Element of the array is a structure having three fields.
// The first field is the name of the Day (A dynamically allocated String), The second field
// is the date of the Day (A integer), the third field is the description of the activity for a
// particular day (A dynamically allocated String).
// b) Write functions create(), read() and display(); to create the calendar, to read the data
// from the keyboard and to print weeks activity details report on screen.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NO_OF_DAYS 3

typedef struct cal{
    char* name;
    int date;
    char* desc;
} CALENDAR;

void create(CALENDAR a[], int i, char name[], int date, char desc[]){
    a[i].name = (char *)malloc(strlen(name) + 1);
    strcpy(a[i].name, name);

    a[i].date = date;

    a[i].desc = (char *)malloc(strlen(desc) + 1);
    strcpy(a[i].desc, desc);
}

void read(CALENDAR a[]){
    int date;
    char name[20], desc[20];
    for (int i=0; i<NO_OF_DAYS; i++){
        printf("\nEnter Name, Date and Description\n");
        scanf("%s%d%s", name, &date, desc);
        create(a, i, name, date, desc);
    }
}

void print(CALENDAR a[]){
    printf("\nName\tDate\tDescription\n");
    for (int i=0; i<NO_OF_DAYS; i++){
        printf("%s\t%d\t%s\n", a[i].name, a[i].date, a[i].desc);
    }
}

int main(){
    CALENDAR a[NO_OF_DAYS];
    read(a);
    print(a);

    return 0;
}