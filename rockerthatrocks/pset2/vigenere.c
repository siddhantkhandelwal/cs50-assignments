#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(const int argc, string argv[])
{
    int i, j;

    if(argc != 2)
        return 1;
    for(i = 0; argv[1][i] != '\0'; i++)
        if(!isalpha(argv[1][i]))
            return 1;

    int len = strlen(argv[1]);
    int k[len];

    string plaintext = get_string("plaintext: ");

    for(i = 0; argv[1][i] != '\0'; i++)
    {
        // eprintf("%c\n", argv[1][i])
        if(isupper(argv[1][i]))
            k[i] = argv[1][i] - 'A';
        else
            k[i] = argv[1][i] - 'a';
    }

    for(i = 0, j = 0; plaintext[i] != '\0'; i++)
    {
        if(isupper(plaintext[i]))
            plaintext[i] = (((plaintext[i] - 'A') + k[j++%len] ) % 26 ) + 'A';
        else if(islower(plaintext[i]))
            plaintext[i] = (((plaintext[i] - 'a') + k[j++%len] ) % 26 ) + 'a';
    }
    printf("ciphertext: %s\n", plaintext);
}
