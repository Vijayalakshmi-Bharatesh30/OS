#include <stdio.h>

int main() {
    int pages[50], frames[10], time[10];
    int n, f, i, j, k;
    int page_faults = 0, found;
    int counter = 0, least, pos;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter the page reference string:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &f);

    // Initialize frames
    for(i = 0; i < f; i++) {
        frames[i] = -1;
    }

    printf("\nPage\tFrames\n");

    for(i = 0; i < n; i++) {
        found = 0;

        // Check if page is already in frames (HIT)
        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                counter++;
                time[j] = counter; // update recent use
                found = 1;
                break;
            }
        }

        // If page not found (FAULT)
        if(!found) {
            // Find empty frame first
            int empty = -1;
            for(j = 0; j < f; j++) {
                if(frames[j] == -1) {
                    empty = j;
                    break;
                }
            }

            if(empty != -1) {
                frames[empty] = pages[i];
                counter++;
                time[empty] = counter;
            } else {
                // Find least recently used page
                least = time[0];
                pos = 0;

                for(j = 1; j < f; j++) {
                    if(time[j] < least) {
                        least = time[j];
                        pos = j;
                    }
                }

                frames[pos] = pages[i];
                counter++;
                time[pos] = counter;
            }

            page_faults++;
        }

        // Print frame status
        printf("%d\t", pages[i]);
        for(k = 0; k < f; k++) {
            if(frames[k] != -1)
                printf("%d ", frames[k]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", page_faults);

    return 0;
}
