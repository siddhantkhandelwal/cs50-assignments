#include <cs50.h>
#include <stdio.h>

int sumdigits(int n)
{
    int sum = 0;
    while(n > 0)
    {
        sum += n%10;
        n /= 10;
    }
    return sum;
}

int getlength(long long card)
{
    int i;
    for(i = 0; card != 0; i++, card/=10);
    return i;
}

bool checksum(long long card)
{
    int sum = 0;
    while(card > 0)
    {
        sum = sum + card%10;
        card = card / 10;
        sum = sum + sumdigits(( card%10 ) * 2);
        card = card / 10;
    }
    if( sum%10 == 0 )
        return true;
    else
        return false;
}

int lasttwo(long long card)
{
    while(card > 100)
        card /= 10;

    return card;
}

int main(void)
{
    long long card;
    card = get_long_long("Number: ");

    int two = lasttwo(card);
    int length = getlength(card);

    if(checksum(card))
    {
        if(length == 15 && (two == 34 || two == 37))
            printf("AMEX\n");
        else if(length == 16 && (two >= 51 && two <=55))
            printf("MASTERCARD\n");
        else if((length == 13 || length == 16) && (two >= 40 && two <= 49))
            printf("VISA\n");
        else
            printf("INVALID\n");
    }
    else
        printf("INVALID\n");
}
