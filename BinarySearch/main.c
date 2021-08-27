#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[] = {13, 15, 18, 19, 20, 30, 60, 78};
    int n = 8;
    int search;
    int first = 0;
    int last = n - 1;
    int middle;

    printf("Enter any value to be search: ");
    scanf("%d", &search);

    middle = (first + last) / 2;

    while(first <= last) //(0 <= 7)
    {
        if(arr[middle] == search)
        {
            printf("Value is Found");
            break;
        }
        else if(arr[middle] < search)
        {
            first = middle + 1; // 4
        }
        else if(arr[middle] > search) //(30 > 20)
        {
            last = middle - 1; // 4
        }

        middle = (first + last) / 2; // 5, 4
    }

    if(first > last)
    {
        printf("Value is not Found");
    }

    return 0;
}
