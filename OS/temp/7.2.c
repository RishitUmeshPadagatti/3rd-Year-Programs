// LRU

#include <stdio.h>
#define MAX_FRAMES 3
#define MAX_PAGES 10

void lru(int referenceString[MAX_PAGES]) {
    int frames[MAX_FRAMES] = {-1, -1, -1};
    int counters[MAX_FRAMES] = {0};

    printf("Page Replacement Using LRU Algorithm\n");
    printf("Page Reference String: ");
    for (int i = 0; i < MAX_PAGES; i++) {
        printf("%d ", referenceString[i]);
    }
    printf("\n");

    int pageFaults = 0;

    for (int i = 0; i < MAX_PAGES; i++) {
        int currentPage = referenceString[i];
        int pageFound = 0;

        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == currentPage) {
                pageFound = 1;
                counters[j] = 0;
                break;
            }
        }

        if (!pageFound) {
            printf("Page %d is not in the frames. Page Fault!\n", currentPage);
            pageFaults++;

            int lruIndex = 0;
            for (int j = 1; j < MAX_FRAMES; j++) {
                if (counters[j] > counters[lruIndex]) {
                    lruIndex = j;
                }
            }

            frames[lruIndex] = currentPage;
            counters[lruIndex] = 0; 
        }

        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] != -1) {
                counters[j]++;
            }
        }

        printf("Frames: ");
        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] != -1) {
                printf("%d(%d) ", frames[j], counters[j]);
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }

    printf("Total Page Faults: %d\n", pageFaults);
}

int main() {
    int referenceString[MAX_PAGES] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3};
    lru(referenceString);
    return 0;
}


// Page Replacement Using LRU Algorithm
// Page Reference String: 1 2 3 4 1 2 5 1 2 3 
// Page 1 is not in the frames. Page Fault!
// Frames: 1(1) - - 
// Page 2 is not in the frames. Page Fault!
// Frames: 2(1) - - 
// Page 3 is not in the frames. Page Fault!
// Frames: 3(1) - - 
// Page 4 is not in the frames. Page Fault!
// Frames: 4(1) - - 
// Page 1 is not in the frames. Page Fault!
// Frames: 1(1) - - 
// Page 2 is not in the frames. Page Fault!
// Frames: 2(1) - - 
// Page 5 is not in the frames. Page Fault!
// Frames: 5(1) - - 
// Page 1 is not in the frames. Page Fault!
// Frames: 1(1) - - 
// Page 2 is not in the frames. Page Fault!
// Frames: 2(1) - - 
// Page 3 is not in the frames. Page Fault!
// Frames: 3(1) - - 
// Total Page Faults: 10