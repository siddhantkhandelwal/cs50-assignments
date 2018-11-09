#include <stdio.h>
#include <cs50.h>

int main(void)
{
    float p;
    do
    {
         p=get_float("Change Owed: ");
    }while(p<0);
    int ctr=0;
    p*=100;
    int f=p;
    while(f>0)
    {
        if(f/25>0)
        {
            ctr=ctr+(f/25);
            f=f%25;
        }
        else if(f/10>0)
        {
            ctr=ctr+(f/10);
            f=f%10;
        }
        else if(f/5>0)
        {
            ctr=ctr+(f/5);
            f=f%5;
        }
        else if(f>0)
        {
            ctr=ctr+f;
            f=f%1;
        }
    }
    printf("%i\n",ctr);
}
