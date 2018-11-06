#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long long creditnum = 0;
    do
    {
        creditnum = get_long_long("Please enter your credit card number: ");
    }
    while(creditnum < 0);
    // testing number of digits
    long long temp = creditnum;
    int count  = 0;
    while(temp != 0)
    {
        temp = temp / 10;
        count++;
    }
    long long a = creditnum;
    int sum_odd = 0;
    int sum_even = 0;
    int digit = 1;
    while(a != 0)
    {
        switch(digit%2)
        {
            case 0:
            {
                //even digit
                    int product = 0;
                    product = 2*(a%10);
                    while(product != 0)
                    {
                        sum_even += product%10;
                        product /= 10;
                    }
                    a = a/10;
                    digit ++;
                    break;
            }
            case 1:
            {
                    //odd digit
                    sum_odd += a%10;
                    a = a/10;
                    digit++;
                    break;
            }
        }
    }
    int sum = sum_even + sum_odd;
    if (sum%10 == 0)
    {
        switch(count)
        {
            case 13:
                printf("VISA\n");
                break;
            case 15:
                printf("AMEX\n");
                break;
            case 16:
                if(creditnum/1000000000000000 == 5)
                    printf("MASTERCARD\n");
                else printf("VISA\n");
                break;
            default:
                printf("INVALID\n");
                break;
        }
    }
    else printf("INVALID\n");

    return 0;
}