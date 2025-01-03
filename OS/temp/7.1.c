// FIFO

#include <stdio.h>
#define MAX_FRAMES 3
#define MAX_PAGES 10

void fifo(int referenceString[MAX_PAGES]) {
    int frames[MAX_FRAMES] = {-1, -1, -1};
    int frameIndex = 0;
    int pageFaults = 0;

    printf("Page Replacement Using FIFO Algorithm\n");
    printf("Page Reference String: ");
    for (int i = 0; i < MAX_PAGES; i++) {
        printf("%d ", referenceString[i]);
    }
    printf("\n");

    for (int i = 0; i < MAX_PAGES; i++) {
        int currentPage = referenceString[i];
        int pageFound = 0;

        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == currentPage) {
                pageFound = 1;
                break;
            }
        }

        if (!pageFound) {
            printf("Page %d is not in the frames. Page Fault!\n", currentPage);
            pageFaults++;

            frames[frameIndex] = currentPage;
            frameIndex = (frameIndex + 1) % MAX_FRAMES;
        }

        printf("Frames: ");
        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] != -1) {
                printf("%d ", frames[j]);
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
    fifo(referenceString);
    return 0;
}

// Page Replacement Using FIFO Algorithm
// Page Reference String: 1 2 3 4 1 2 5 1 2 3 
// Page 1 is not in the frames. Page Fault!
// Frames: 1 - - 
// Page 2 is not in the frames. Page Fault!
// Frames: 1 2 - 
// Page 3 is not in the frames. Page Fault!
// Frames: 1 2 3 
// Page 4 is not in the frames. Page Fault!
// Frames: 4 2 3 
// Page 1 is not in the frames. Page Fault!
// Frames: 4 1 3 
// Page 2 is not in the frames. Page Fault!
// Frames: 4 1 2 
// Page 5 is not in the frames. Page Fault!
// Frames: 5 1 2 
// Frames: 5 1 2 
// Frames: 5 1 2 
// Page 3 is not in the frames. Page Fault!
// Frames: 5 3 2 
// Total Page Faults: 8