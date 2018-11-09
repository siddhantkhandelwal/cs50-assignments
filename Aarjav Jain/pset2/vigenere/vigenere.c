#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Error\n");
        return 1;
    }

    string key = argv[1];

    for (int i = 0; i < strlen(key); i++)
    {
        if (isalpha(key[i]) == 0)
        {
            printf("Error\n");
            return 1;
        }
    }

    int keylen = strlen(argv[1]);
    string s = get_string("plaintext: ");
    int slen = strlen(s);
    /*char fkey[slen];
    if (keylen < slen)
    {
        for (int i = 0; i < slen; i++)
        {
            fkey[i] = key[i % (keylen + 1)];
        }
    }*/

    //printf("%i %s \n%i %s", slen, s, (int)strlen(fkey), fkey);

    for (int i = 0, j = 0; i < slen; i++, j++)
    {
        /*if (isupper(key[i % (keylen + 1)]) != 0)
        {
            if ((s[i] + key[i % (keylen + 1)] - 65) > 90)
            {
                s[i] += (key[i % (keylen + 1)] - 65 - 90);
            }
            else
            {
                s[i] += (key[i % (keylen + 1)] - 65);
            }
        }
        else if (islower(key[i % (keylen + 1)]) != 0)
        {
            if ((s[i] + key[i % (keylen + 1)] - 97) > 122)
            {
                s[i] += (key[i % (keylen + 1)] - 97 - 122);
            }
            else
            {
                s[i] += (key[i % (keylen + 1)] - 97);
            }
        }*/

        if (isupper(s[i]) != 0)
        {
            if (isupper(key[j % (keylen)]) != 0)
            {
                if ((s[i] + key[j % (keylen)] - 65) > 90)
                {
                    s[i] += (key[j % (keylen)] - 65 - 26);
                }
                else
                {
                    s[i] += (key[j % (keylen)] - 65);
                }
            }
            else if (islower(key[j % (keylen)]) != 0)
            {
                if ((s[i] + key[j % (keylen)] - 97) > 90)
                {
                    s[i] += (key[j % (keylen)] - 97 - 26);
                }
                else
                {
                    s[i] += (key[j % (keylen)] - 97);
                }
            }

        }
        else if (islower(s[i]) != 0)
        {
            if (isupper(key[j % (keylen)]) != 0)
            {
                if ((s[i] + key[j % (keylen)] - 65) > 122)
                {
                    s[i] += (key[j % (keylen)] - 65 - 26);
                }
                else
                {
                    s[i] += (key[j % (keylen)] - 65);
                }
            }
            else if (islower(key[j % (keylen)]) != 0)
            {
                if ((s[i] + key[j % (keylen)] - 97) > 122)
                {
                    s[i] += (key[j % (keylen)] - 97 - 26);
                }
                else
                {
                    s[i] += (key[j % (keylen)] - 97);
                }
            }

        }
        else
        {
            j--;
        }

        /*if (isupper(key[i % (keylen)]) != 0)
        {
            if ((s[i] + key[i % (keylen)] - 65) > 90)
            {
                s[i] += (key[i % (keylen)] - 65 - 26);
            }
            else
            {
                s[i] += (key[i % (keylen)] - 65);
            }
        }
        else if (islower(key[i % (keylen)]) != 0)
        {
            if ((s[i] + key[i % (keylen)] - 97) > 122)
            {
                s[i] += (key[i % (keylen)] - 97 - 26);
            }
            else
            {
                s[i] += (key[i % (keylen)] - 97);
            }
        }*/
    }
    printf("ciphertext: %s\n", s);
    return 0;
}