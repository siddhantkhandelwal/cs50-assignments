#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



int main(int argc, string argv[])
{

    if(argc != 2)
    {
        printf("Desired format: ./caesar k");
        return 1;
    }

    string k = argv[1];

    //Checks if the key is only alphabetical
    for(int i = 0, n = strlen(k); i < n; i++)
    {
        if(!isalpha(k[i]))
        {
            printf("Key must contain only alphabets");
            return 1;
        }
    }

    string k_upper = k;


    //Converts the whole key into uppercase
    for(int i = 0, n = strlen(k_upper); i < n; i++)
    {
        k_upper[i] = toupper(k_upper[i]);
    }

    int letter = 0;
    int key_length = strlen(k_upper);

    string input = GetString();

    for(int i = 0, n = strlen(input); i < n; i++)
    {
        int shift = k_upper[letter % key_length] - 65; //Number of shifts needed for te current letter in plaintext

        if(isupper(input[i]))
        {
            if(input[i] + (shift % 26) > 'Z')
            {
                input[i] -= 26;
            }
            input[i] += shift % 26;
            letter++;
        }
        else if(islower(input[i]))
        {
            if(input[i] + (shift % 26) > 'z')
            {
                input[i] -= 26;
            }
            input[i] += shift % 26;
            letter++;
        }

    }

    printf("%s\n", input);
}
