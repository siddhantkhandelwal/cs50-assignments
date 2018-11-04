#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n=0, i=0, j=0;
    do{
        n = get_int("Height: ");
    }while(n < 1 || n > 23);

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n-i-1; j++)
            printf(" ");
        for(; j < n; j++)
            printf("#");

        printf(" ");

        for(; j > n-i-1; j--)
            printf("#");
        for(; j > 0; j--)
            printf(" ");

        printf("\n");
    }
}
