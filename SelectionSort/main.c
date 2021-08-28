#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[] = {10, 3, 1, 2, 5, 6};
    int n = 6;
    int i, j, min, temp;

    for(i = 0; i < n - 1; i++) // i = 0, 1
    {
        min = i; // 0, 1
        for(j = i + 1; j < n; j++) // j = 1, 2, 3, 4, 5, 6
        {
            if(arr[j] < arr[min]) //(3 < 10), (1 < 3) , (2 < 1), false
            {
                min = j; // 1, 2
            }
        }

        // swapping
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    for(i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }

    return 0;
}
