#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Invalid command-line argument\n");
        return 1;
    }
    string plaintext = get_string("plaintext: ");
    int k = atoi(argv[1]);
    int len = strlen(plaintext);
    for (int ii = 0; ii < len; ii++)
    {
        if (plaintext[ii] >= 65 && plaintext[ii] <= 90)
        {
            plaintext[ii] = 65 + ((plaintext[ii] - 65 + k)%26);
        }
        else if (plaintext[ii] >= 97 && plaintext[ii] <= 122)
        {
            plaintext[ii] = 97 + ((plaintext[ii] - 97 + k)%26);
        }
    }
    printf("ciphertext: %s",plaintext);
    printf("\n");




    return 0;
}