#include <stdio.h>
#include <stdlib.h>

void shellSort(int arr[], int n)
{
    int i, j, m, temp;

    m = n / 2;

    // 2, 8, 4, 3, 10

    while(m > 0)
    {
        for(j = m; j < n; j++)
        {
            for(i = j - m; i >= 0; i = i - m)
            {
                if(arr[i] > arr[i + m])
                {
                    temp = arr[i];
                    arr[i] = arr[i + m];
                    arr[i + m] = temp;
                }
                else
                {
                    break;
                }
            }
        }
        m = m / 2;
    }
}

int main()
{
    int arr[5];

    printf("Enter values in an array:");
    for(int i = 0; i < 5; i++)
        scanf("%d", &arr[i]);

    shellSort(arr, 5);

    printf("Sorted array:");
    for(int i = 0; i < 5; i++)
        printf("%d  ", arr[i]);

    return 0;
}
