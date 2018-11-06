//Program to verify Credit Card Numebrs
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//Function to verify Card Numbers
int checkfunction(long long n, int length){
    int sum = 0;
    for (int i = 1; i <= length; i++){
        long long div = 1;
        for (int p = 1; p < i; p++){
            div *= 10;
        }
        long long b = n / div;
        int num = b % 10;
        if (i % 2 == 1){
            sum += num;
        }
        else{
            if (num == 9){
                sum += 9;
            }
            else{
                sum += (num * 2) % 9;
            }
        }
    }
    //printf("%i\n", sum);
    if (sum % 10 == 0){
        return 1;
    }
    else{
        return 0;
    }
}

int main(void)
{
    long long n;
    do
    {
        n = get_long_long("Enter Card Number: ");
    }
    while (n <= 0);
    int length = 1;
    for ( ; length < 17; length++){
        long long div = 1;
        for (int p = 0; p < length; p++){
            div *= 10;
        }
        if (n / div == 0){
            break;
        }
    }
    //printf("%i\n", length);
//To distinguish between the cards
    int firstdigit = n / pow(10, length-1);
    int buffer = (n / pow(10, length-2));
    int seconddigit = buffer % 10;
    //printf("%i %i\n", firstdigit, seconddigit);
    int check = checkfunction(n, length);
    if (check == 1){
        if (length == 15 && firstdigit == 3 && (seconddigit == 4 || seconddigit == 7)){
            printf("AMEX\n");
        }
        else if (length == 16 && firstdigit == 5 && seconddigit >= 1 && seconddigit <= 5){
            printf("MASTERCARD\n");
        }
        else if ((length == 13 || length == 16) && firstdigit == 4){
            printf("VISA\n");
        }
        else{
            printf("INVALID\n");
        }
    }
    else{
        printf("INVALID\n");
    }

    return 0;
}
