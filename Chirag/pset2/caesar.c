#include <stdio.h>
#include <string.h>
#include <cs50.h>

int main(int argc, string argv[])
{
    if(argc!=2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }
    int k = atoi(argv[1]);
    k %= 26;
    int temp;
    string ptext = get_string("plaintext: ");
    printf("ciphertext: ");
    for(int i = 0; i < strlen(ptext); i++)
    {
        if((ptext[i] >= 'A') && (ptext[i] <= 'Z'))
        {
            temp = ptext[i] + k - 'A';
            temp %= 26;
            printf("%c", temp + 'A');
        }
        if((ptext[i] >= 'a') && (ptext[i] <= 'z'))
        {
            temp = ptext[i] + k - 'a';
            temp %= 26;
            printf("%c", temp + 'a');
        }
        if(!(((ptext[i] >= 'A') && (ptext[i] <= 'Z')) || ((ptext[i] >= 'a') && (ptext[i] <= 'z')))) printf("%c", ptext[i]);
    }
    printf("\n");
    return 0;
}