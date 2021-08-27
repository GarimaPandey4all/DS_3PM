#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    int n = 5;
    int temp, i, j;

    // 4, 5, 3, 2, 1
    // 4, 3, 5, 2, 1
    // 4, 3, 2, 5, 1
    // 4, 3, 2, 1, 5

    for(i = 0; i < n - 1; i++) // i = 0, 1
    {
        for(j = 0; j < n - i - 1; j++)// j = 0, 1, 2, 3, 4
        {
            if(arr[j] > arr[j + 1]) // 5 > 4, 5 > 3
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for(i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }

    return 0;
}
