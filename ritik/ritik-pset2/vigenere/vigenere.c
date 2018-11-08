#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int getnum(char letter)
{
    if(isupper(letter))
        return letter - 65;
    else if(islower(letter))
        return letter - 97;
    else return letter;
}

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Invalid command-line argument!\n");
        return 1;
    }
    string keyword = argv[1];
    string plaintext = get_string("plaintext: ");
    int len_p = strlen(plaintext);
    int len_k = strlen(keyword);
    for(int ii = 0; ii < len_p; ii++)
    {
        if(islower(plaintext[ii]))
        {
            int shift = getnum(keyword[ii%len_k]);
            plaintext[ii] = 97 + ((plaintext[ii] - 97 + shift)%26);
        }
        if(isupper(plaintext[ii]))
        {
            int shift  = getnum(keyword[ii%len_k]);
            plaintext[ii] = 65 + ((plaintext[ii] - 65 + shift)%26);
        }
    }
    printf("ciphertext: %s\n",plaintext);
    return 0;
}