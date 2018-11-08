#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
 int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("An error has occured\n");
        return 1;
    }
     string k = argv[1];
     for (int i = 0; i < strlen(k); i++)
    {
        if (isalpha(k[i]) == 0)
        {
            printf("An error has occured\n");
            return 1;
        }
    }
    int klen = strlen(argv[1]);

    string text = get_string("plaintext: ");
    int tlen = strlen(text);

    for (int i = 0, j = 0; i < tlen; i++, j++)
    {
         if (isupper(text[i]) != 0)
        {
            if (isupper(k[j % (klen)]) != 0)
            {
                if ((text[i] + k[j % (klen)] - 65) > 90)
                {
                    text[i] += (k[j % (klen)] - 65 - 26);
                }
                else
                {
                    text[i] += (k[j % (klen)] - 65);
                }
            }
            else if (islower(k[j % (klen)]) != 0)
            {
                if ((text[i] + k[j % (klen)] - 97) > 90)
                {
                    text[i] += (k[j % (klen)] - 97 - 26);
                }
                else
                {
                    text[i] += (k[j % (klen)] - 97);
                }
            }
         }
        else if (islower(text[i]) != 0)
        {
            if (isupper(k[j % (klen)]) != 0)
            {
                if ((text[i] + k[j % (klen)] - 65) > 122)
                {
                    text[i] += (k[j % (klen)] - 65 - 26);
                }
                else
                {
                    text[i] += (k[j % (klen)] - 65);
                }
            }
            else if (islower(k[j % (klen)]) != 0)
            {
                if ((text[i] + k[j % (klen)] - 97) > 122)
                {
                    text[i] += (k[j % (klen)] - 97 - 26);
                }
                else
                {
                    text[i] += (k[j % (klen)] - 97);
                }
            }
         }
        else
        {
            j--;
        }
    }
    printf("ciphertext: %s\n", text);
}
