#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[] = {10, 3, 1, 2, 5, 6};
    int n = 6;
    int i, j, temp;

    for(i = 1; i < n; i++) // 1, 2, 3
    {
        temp = arr[i]; // 3, 1
        j = i - 1; // 0, 1

        while(j >= 0 && arr[j] > temp) // (10 > 3) (3 > 1) (10 > 1)
        {
            arr[j + 1] = arr[j]; // 10, 3, 10
            j = j - 1; // -1, -1
        }

        arr[j + 1] = temp; // 3, 1
    }

    for(i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }

    return 0;
}
