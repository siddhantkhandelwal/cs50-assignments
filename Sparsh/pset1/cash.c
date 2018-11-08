#include <stdio.h>
#include <cs50.h>

 int main(void)
{
    float x;
    do
    {
         x=get_float("Change Owed: ");
    }while(x<0);

    int c=0;
    int m=x*100;

    while(m>0)
    {
        if(m/25>0)
        {
            c=c+(m/25);
            m=m%25;
        }
        else if(m/10>0)
        {
            c=c+(m/10);
            m=m%10;
        }
        else if(m/5>0)
        {
            c=c+(m/5);
            m=m%5;
        }
        else
        {
            c=c+m;
            m=m%1;
        }
    }
    printf("%i\n",c);
}
