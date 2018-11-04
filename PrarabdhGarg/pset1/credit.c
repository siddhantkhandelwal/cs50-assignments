#include <cs50.h>
#include <stdio.h>
int product(int a);
int main(void)
{
    long number=get_long("Number: ");
    int sum=0;
    long n=number;
    int i=1;
    for(;number>0;i++)
    {
        int x=number%10;
        if(i%2==0)
        {
            sum += product(2*x);
        }
        else
        {
            sum += x;
        }
        number=number/10;
    }
    if(sum%10==0)
    {
        
        if(i==16)
        {
            printf("Valid\n");
            printf("American\n");
        }
        else if(i==17)
        {
            printf("Valid\n");
            if(n/1000000000000000==4)
            {
                printf("Visa\n");
            }
            else
            {
                printf("MasterCard\n");
            }
            
        }
        else if(i==14)
        {
            printf("Valid\n");
            printf("Visa\n");            
        }
        else
        {
            printf("Invalid\n");
        }
    }
    else
    {
        printf("Invalid\n");
    }
}
    
int product(int a)
{
    int sum=0;
    while(a>0)
    {
        int x=a%10;
        sum+=x;
        a=a/10;
    }
    return sum;
}

