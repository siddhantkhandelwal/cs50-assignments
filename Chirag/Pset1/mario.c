#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int h = -1;
    while(!((h >= 0) && (h <= 23)))
    {
        h = get_int("Height: ");
    }
    int i = 1;
    while(i <= h)
    {
        int j = 0;
        while(j < (h - i))
        {
            printf(" ");
            j++;
        }
        while(j < h)
        {
            printf("#");
            j++;
        }
        printf("  ");
        while(j > (h - i))
        {
            printf("#");
            j--;
        }
        i++;
        printf("\n");
    }
}
