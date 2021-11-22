#include <stdio.h>
#include <stdlib.h>

int main()
{
    int heap[10], i, j, n, temp, root, c;

    printf("Enter number of elements:");
    scanf("%d", &n);

    printf("Enter Values:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &heap[i]);
    }

    printf("\nHeap Array:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d  ", heap[i]);
    }

    for(i = 1; i < n; i++)
    {
        c = i;

        do {
            root = (c - 1)/2;

            if(heap[root] < heap[c]) // create max heapify array/tree
            {
                temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }

            c = root;
        }while(c != 0);
    }

    printf("\nMax Heap Array:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d  ", heap[i]);
    }

    //sort heap array
    for(j = n - 1; j >= 0; j--) // 4, 3
    {
        //swap maximum value with rightmost leaf element

        temp = heap[0];
        heap[0] = heap[j];
        heap[j] = temp;

//        max heap array
//    80  79  67  60  13
//    13  79  67  60  80
//    79  13  67  60  80
//    79  60  67  13  80
//    13  60  67  79  80

        root = 0;

        do {
            c = 2 * root + 1; // 1, 3, 7

            if(heap[c] < heap[c + 1] && c < j - 1) // 79 < 67
            {
                c++;
            }

            //rearrange heap array
            if(heap[root] < heap[c] && c < j)
            {
                temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }

            root = c; // 1, 3
        }while(c < j);
    }

    printf("\nSorted Array:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d  ", heap[i]);
    }

    return 0;
}
