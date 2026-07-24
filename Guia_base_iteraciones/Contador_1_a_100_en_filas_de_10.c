#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    for (i = 1; i <= 100; i++)
    {
        printf("%6d", i);
        if (i % 10 == 0)
        {
            printf("\n");
        }
    }
    return 0;
}