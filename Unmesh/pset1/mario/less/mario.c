#include <stdio.h>

int main(void)
{
    int h;
    printf("Height:");
    scanf("%i",&h);
    while(!((h>=0)&&(h<=23)))
    {
        printf("Height:");
        scanf("%i",&h);
    }
    for(int i=2;i<=h+1;i++)
    {
        for(int j=1;j<=(h+1-i);j++)
            printf(" ");
        for(int j=1;j<=i;j++)
            printf("#");
        printf("\n");
    }
}