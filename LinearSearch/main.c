#include <stdio.h>
#include <stdlib.h>

int main()
{
    // compile - time initialization
    int arr[] = {12, 15, 17, 19, 24, 29, 69, 90};
    int search, i;

    printf("Enter any value to be search:");
    scanf("%d", &search); // Read User Input
    //& - address of

    for(i = 0; i < 8; i++)
    {
        if(arr[i] == search)
        {
            printf("%d search value is found\n", search);
            break;
        }
    }

    if(i == 8)
    {
        printf("Search is not found");
    }

    return 0;
}
