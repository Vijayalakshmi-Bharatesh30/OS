#include <stdio.h>

int main()
{
    int frames, pages;
    printf("Enter number of frames: ");
    scanf("%d", &frames);

    printf("Enter number of pages: ");
    scanf("%d", &pages);

    int ref[100], frame[10], i, j, k, pos, faults = 0, found;

    printf("Enter reference string:\n");
    for(i = 0; i < pages; i++)
        scanf("%d", &ref[i]);

    for(i = 0; i < frames; i++)
        frame[i] = -1;

    for(i = 0; i < pages; i++)
    {
        found = 0;

        for(j = 0; j < frames; j++)
        {
            if(frame[j] == ref[i])
            {
                found = 1;
                break;
            }
        }

        if(found == 0)
        {
            int farthest = -1, index = -1;

            for(j = 0; j < frames; j++)
            {
                int next = -1;
                for(k = i + 1; k < pages; k++)
                {
                    if(frame[j] == ref[k])
                    {
                        next = k;
                        break;
                    }
                }

                if(next == -1)
                {
                    index = j;
                    break;
                }

                if(next > farthest)
                {
                    farthest = next;
                    index = j;
                }
            }

            frame[index] = ref[i];
            faults++;
        }

        printf("Frames: ");
        for(j = 0; j < frames; j++)
        {
            if(frame[j] == -1)
                printf("- ");
            else
                printf("%d ", frame[j]);
        }
        printf("\n");
    }

    printf("Total Page Faults = %d\n", faults);

    return 0;
}
