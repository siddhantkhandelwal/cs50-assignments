#include<stdio.h>
int main()
{

    long long int num;
    int oddsum=0,evensum=0,finalsum=0;
    printf("Enter your card number: ");
    scanf("%lld",&num);
    for(long long int a=num;a>0;a=a/100)
    {
            oddsum=oddsum+(a%10);
    }
    for(long long int b=num/10;b>0;b/=100)
    {
            evensum+=((2*(b%10))/10)+((2*(b%10))%10);
    }
    finalsum=oddsum+evensum;
    if(finalsum%10!=0)
        printf("Invalid card");
    else
    {
        if(num/1000000000000000==0)
            printf("It's an AMEX");
        else if(num/10000000000000==0)
            printf("It's a VISA");
        else if(num/1000000000000000==4)
            printf("It's a VISA");
            else
                printf("It's a MASTERCARD");
    }
 }



