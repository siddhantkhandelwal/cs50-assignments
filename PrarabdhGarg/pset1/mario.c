#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n=get_int("Height: ");
    }while(n<1 || n>8);
    for(int i=1;i<=n;i++)
    {
        for(int j=n;j>0;j--)
        {
            if(j>i)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf(" ");
        for(int j=1;j<=n;j++)
        {
            if(j<=i)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}
