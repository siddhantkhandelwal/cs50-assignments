//program to make a pattern
//two half pyramids
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //to input height of pyramid
    int n;
    do
    {
        n = get_int("Height of half Pyramid: ");
        if (n == 0)
        {
            return 0;
        }

    }
    while (n <= 0 || n > 23);

    //to print pattern
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            printf(" ");
        }
        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }
        printf("  ");
        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}