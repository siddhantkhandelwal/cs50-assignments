#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int key , i;

int main( int argc  , string argv[])
{
    if (argc == 2)
    {
        key = atoi(argv[1]);

        string input = get_string("plaintext: ");

        printf("ciphertext: ");

        for(i = 0; i < strlen (input); i++)
        {
            if(isalpha(input[i]))
            {
                if(isupper(input[i]))

                {

                    char gotcapital;
                     gotcapital = ((input[i] - 65) + key ) % 26 + 65;


                    printf("%c", gotcapital);
                    //now convert back to string

                }
                else if (islower(input[i]))
                {
                    char gotlower;
                    gotlower = ((input[i] - 97) + key ) % 26 + 97;

                    printf("%c", gotlower);
                }

            }
            else
            {
                printf("%c", input[i]);
            }
        }

        printf("\n");
        return 0;
    }

    else
    {
        printf("Usage: ./caeser k\n");

    return 1;

    }
}