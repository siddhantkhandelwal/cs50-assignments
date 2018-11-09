#include<stdio.h>
#include<cs50.h>

int main(void)
{
    int n,i,j,k ;
    do
    {
        n = get_int("Height: ");
    }
    while (n<0||n>23);

    for(i=0;i<n;i++)
    {
        for(k=0;k<n-i-1;k++)
            {
                printf(" ");
            }
        for(j=0;j<i+2;j++)
        {
            printf("#");
        }
        printf("\n");
    }
}