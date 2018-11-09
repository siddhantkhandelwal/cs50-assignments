#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if(argc == 1)
        return 1;

    int k=0;
    for(int i = 0; argv[1][i] != '\0'; i++)
        k = k*10 + argv[1][i] - '0';

    k = k % 26;

    string plaintext = get_string("plaintext: ");
    int n = strlen(plaintext);

    for(int i = 0; i < n; i++)
    {
        if(isupper(plaintext[i]))
            plaintext[i] = (((plaintext[i] - 'A') + k ) % 26 ) + 'A';
        else if(islower(plaintext[i]))
            plaintext[i] = (((plaintext[i] - 'a') + k ) % 26 ) + 'a';
    }

    printf("ciphertext: %s\n", plaintext);
}
