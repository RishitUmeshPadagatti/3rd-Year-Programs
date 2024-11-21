// WAP to simulate producer and consumer problem using semaphones

#include <stdio.h>
#include <stdlib.h>

int full=0, empty=3, x=0, mutex=1;

int custom_wait(int s){
    return (--s);
}

int custom_signal(int s){
    return (++s);
}

void producer(){
    mutex = custom_wait(mutex);
    full = custom_signal(full);
    empty = custom_wait(empty);
    x++;
    printf("Produced item: %d\n", x);
    mutex = custom_signal(mutex);
}

void consumer(){
    mutex = custom_wait(mutex);
    full = custom_wait(full);
    empty = custom_signal(empty);
    printf("Consumed item: %d\n", x);
    x--;
    mutex = custom_signal(mutex);
}

int main(){
    int choice;
    while(1){
        printf("\n1. Producer\n2. Consumer\n3. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1: if (mutex==1 && empty!=0){ producer(); }
                    else { printf("Buffer is full"); }
                    break;
            case 2: if (mutex==1 && full!=0){ consumer(); }
                    else { printf("Buffer is empty"); }
                    break;
            case 3: exit(0);
            default: break;
        }
    }

    return 0;
}