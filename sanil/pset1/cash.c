#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main()
{
    float amount;
    do
    {
        printf("wha is the amount of money owed?\n");
        amount = GetFloat();
    } 
    while (amount < 0);
   
    int number_of_coins = 0;
    int cents = (int) round(amount * 100);
    
    number_of_coins += cents / 25;
    cents %= 25;

    number_of_coins += cents / 10;
    cents %= 10;

    number_of_coins += cents / 5;
    cents %= 5;

    number_of_coins += cents;
    
    printf("%d\n", number_of_coins);
}
