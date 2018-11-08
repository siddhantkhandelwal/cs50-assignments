#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc , string argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./vigenere k\n");
        return 1;
    }

        string key = argv[1];

    for (int i = 0; i < strlen (argv[1]); i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Usage: ./vigenere k\n");
            return 1;
        }
    }

    // now capitalizing letters

    for (int j = 0; j < strlen(key); j++)
    {
        if(islower(key[j]))
        {
            key[j] = key[j]-32;
        }

    }



    //done till here

    string input = get_string("plaintext: ");

        printf("ciphertext: ");


        int l = 0;

        for( int k = 0; k < strlen (input);k++ )
        {

            if(isalpha(input[k]))
            {
                if(isupper(input[k]))

                {

                    char gotcapital;


                     gotcapital = ((input[k] - 65) + key[l % strlen(key)]-65 ) % 26 + 65;


                    printf("%c", gotcapital);
                    l++;


                }
                else if (islower(input[k]))
                {
                    char gotlower;
                    gotlower = ((input[k] - 97) + key[l % strlen(key)] - 65 ) % 26 + 97;

                    printf("%c", gotlower);
                    l++;
                }

            }
            else
            {
                printf("%c", input[k]);

            }
        }
        printf("\n");

    }
