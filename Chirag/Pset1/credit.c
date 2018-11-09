#import <stdio.h>
#import <cs50.h>
#import <string.h>

int main(void)
{
    string s = "";
    bool valid = false;
    while(!(valid))
    {
        s = get_string("Number: ");
        valid = true;
        for(int i = 0; i < strlen(s); i++)
        {
            if(!(s[i] >= '0' && s[i] <= '9'))
            {
               valid = false;
               break;
            }
        }
        if(!strcmp(s,"")) valid = false;
    }
    int tot = strlen(s);
    int i = 0;
    int sum = 0;
    while(i < tot)
    {
        if(i%2)
        {
            if(s[tot - i - 1] - '0' >= 5)
            {
                sum += (2 * (s[tot - i - 1] - '0')) - 9;
            }
            else sum += (2 * (s[tot - i - 1] - '0'));
        }
        else sum += (s[tot - i - 1] - '0');
        i++;
    }
    if(sum % 10)
    {
        printf("INVALID\n");
        return 0;
    }
    if((s[0] == '4') && ((tot == 13) || (tot == 16)))
    {
        printf("VISA\n");
        return 0;
    }
    if((s[0] == '3') && ((s[1] == '4') || (s[1] == '7')) && (tot == 15))
    {
        printf("AMEX\n");
        return 0;
    }
    if((s[0] == '5') && ((s[1] >= '1') && (s[1] <= '5')) && (tot == 16))
    {
        printf("MASTERCARD\n");
        return 0;
    }
    printf("INVALID\n");
    return 0;
 }
