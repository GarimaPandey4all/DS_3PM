#include <stdio.h>
#include <stdlib.h>

void quickSort(int arr[], int first, int last)
{
    int pivot, i, j, temp;

    if(first < last) // lower bound < upper bound
    {
        pivot = first;
        i = first;
        j = last;
        while(i < j)
        {
            while(arr[pivot] >= arr[i] && i < last)
            {
                i++;
            }
            while(arr[pivot] < arr[j])
            {
                j--;
            }
            if(i < j)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        //swapping of pivot value
        temp = arr[pivot];
        arr[pivot] = arr[j];
        arr[j] = temp;

        //left - subarray
        quickSort(arr, 0, j - 1); // recursive call
        //right - subarray
        quickSort(arr, j + 1, last);
    }
}

int main()
{
    int arr[] = {10, 3, 7, 5, 2, 12, 1, 8};
    int n = 8;

    quickSort(arr, 0, n - 1);

    printf("\nSorted Array is:\n");
    for(int i = 0; i < n; i++){

        printf("%d  ", arr[i]);
    }

    return 0;
}
