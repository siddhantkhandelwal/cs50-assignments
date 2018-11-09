#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string key[])
{
    if(argc!=2)
    {
        printf("Usage: ./vigenere k\n");
        return 1;
    }
    string k = key[1];
    int kset[strlen(k)];
    for(int i = 0; i < strlen(k); i++)
    {
        if(!(((k[i] >= 'A') && (k[i] <= 'Z')) || ((k[i] >= 'a') && (k[i] <= 'z'))))
        {
            printf("Usage: ./vigenere k\n");
            return 1;
        }
        else
        {
            if ((k[i] >= 'a') && (k[i] <= 'z')) kset[i] = k[i] - 'a';
            if ((k[i] >= 'A') && (k[i] <= 'Z')) kset[i] = k[i] - 'A';
        }
    }
    string ptext = get_string("plaintext: ");
    printf("ciphertext: ");
    int temp;
    int j = 0;
    for(int i = 0; i < strlen(ptext); i++)
    {
        if((ptext[i] >= 'A') && (ptext[i] <= 'Z'))
        {
            temp = ptext[i] + kset[j] - 'A';
            temp %= 26;
            printf("%c", temp + 'A');
            j += 1;
        }
        if((ptext[i] >= 'a') && (ptext[i] <= 'z'))
        {
            temp = ptext[i] + kset[j] - 'a';
            temp %= 26;
            printf("%c", temp + 'a');
            j += 1;
        }
        if(!(((ptext[i] >= 'A') && (ptext[i] <= 'Z')) || ((ptext[i] >= 'a') && (ptext[i] <= 'z')))) printf("%c", ptext[i]);
        if(j == strlen(k)) j -= strlen(k);
    }
    printf("\n");
    return 0;
}