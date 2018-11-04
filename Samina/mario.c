#include <stdio.h>
#include <cs50.h>
int main(void)
{
    int i;
    do
    {
        i=get_int("Enter number : ");
        if(i<0||i>23) continue;
        for(int m=0;m<i;m++)
        {
            for(int n=0;n<=2*i+1;n++)
            {
                if(n<i)
                {
                    if(n<i-m-1)
                    printf(" ");
                    else
                    printf("*");
                }
                else if(n==i||n==i+1)
                printf(" ");
                else
                {
                    if(n<=i+m+2)
                    printf("*");
                    else
                    printf(" ");
                }
            }
            printf("\n");

        }
    }while(i<0||i>23);
}
