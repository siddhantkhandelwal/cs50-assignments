#include <stdio.h>
#include <cs50.h>

int main (void)
{
    long long card_num;
    int odd_sum = 0; //sum of digits having odd face values
    int even_sum = 0; //sum of digits having even face values
    int digit_pos = 1; //odd number indicates odd position of digit, even indicates even position
    int total_sum;
    
    printf("Enter credit card number: ");
    card_num = GetLongLong();
    
    int card_num_copy = card_num; //creates a copy of credit card number
    
    while(card_num_copy > 0)
    {
        
        int digit = card_num % 10;
        
        if(digit_pos % 2 == 1)
        {
            odd_sum = digit + odd_sum;
        }
        else if(digit_pos % 2 == 0)
        {
            digit *= 2;
            
            if(digit > 9)
            {
                int digit2; //seperates digits if there are 2 digits
                digit2 = digit % 10;
                even_sum += digit2 + 1;    
            }
            else
            {
                even_sum += digit;
            }
        }
        digit_pos++;
        card_num_copy /= 10;
    }
    
    total_sum = even_sum + odd_sum;
    if(total_sum % 10 == 0)
    {
        if(card_num / 10000000000000 == 34 || card_num / 10000000000000 == 37)
        {
            printf("AMEX\n");
        }
        else if(card_num / 100000000000000 >=51 && card_num / 100000000000000 <= 55)
        {
            printf("MASTERCARD\n");
        }
        else if(card_num / 1000000000000000 == 4 || card_num / 1000000000000 == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
}
    else
    {
        printf("INVALID\n");
    }
}