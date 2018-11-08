#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int ht;
    int space;
    int hash;
    int i;
    do
    {
        ht = get_int("Height: ");
    }
    while (ht < 0 || ht > 23);
    for (i = 1; i <= ht; i++)
    {
        for (space=(ht - i); space> 0; space--)
        {
            printf(" ");
        }
        for (hash= 1; hash <= (i + 1); hash++)
        {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}
