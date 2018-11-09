#include<stdio.h>
#include<cs50.h>


long long power(double A, double B);
long digit(long long C);


int main(void)
{
    long long n;

    int oddplace, osum = 0, ovalue, oddsum;
    int evenplace, esum = 0, evalue, devalue, evensum;
    int totalsum ;

    n = get_long_long("Number: ");
    //finding whether valid with luhn's theorem or not
    for(oddplace = 1; oddplace < digit(n) + 2; oddplace += 2)
    {
        ovalue = (n % power(10, oddplace) - n % power(10,oddplace - 1)) / (power(10, oddplace-1));
        osum = osum + ovalue;
    }

    oddsum = osum + n % power(10, 1);

    //for even values

    for( evenplace = 1; evenplace < digit(n) + 2; evenplace += 2)
    {
        evalue = (n % power(10, evenplace + 1) - n % power(10, evenplace)) / (power(10, evenplace));

        if (evalue * 2 > 9 )
        {
            devalue = ((evalue * 2) - (evalue * 2) % power(10, 1)) / (power(10, 1)) + (evalue * 2) % 10;
        }
        else
        {
            devalue = evalue*2;

        }

        esum = esum + devalue;
    }

    evensum = esum;

    totalsum = evensum + oddsum;



    if ((n / 10000000000000 == 34 || n / 10000000000000 == 37) && totalsum % 10 == 0)
    {
        //can be american express
        printf("AMEX\n");
    }

    else if ((n / 100000000000000 <= 55 && n / 100000000000000 >= 51 ) && totalsum % 10 == 0)
    {
        //can be master card
        printf("MASTERCARD\n");
    }
    else if ((n / 1000000000000 == 4 || n / 1000000000000000 == 4) && totalsum % 10 == 0)
    {
        //can be a visa
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}


long long power(double A, double B)
{
    double ans = A;
    int i = 1;
    while(i<B)
    {
        ans= ans *A;
        i++;
    }
    return ans;
}

long digit(long long C)
{
    int x = 0;
    while(C/power(10,x)>1)
    {
        x++;
    }
    return x;
}