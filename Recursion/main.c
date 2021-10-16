#include <stdio.h>
#include <stdlib.h>

//Recursion: function calls itself is called recursion.

//3 = 3 + 2 + 1 = 6

int func(int a)
{
    int s;

    if(a == 1)//stop condition / base case
    {
        return 1;
    }

    //s = a + func(a - 1); - processing logic
    s = a + func(a - 1); // func(a - 1) - small problem

    return s;
}

int main()
{
    int x;

    x = func(3);

    printf("%d", x);

    return 0;
}
