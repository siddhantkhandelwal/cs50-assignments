//Program to encrypt a string
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc == 2){
    }
    else{
        printf("Error");
        return 1;
    }

    int k = atoi(argv[1]);

    if (k <= 0)
    {
        printf("Error");
        return 1;
    }

    int key = k % 26;

    string p = get_string("PLAINTEXT: ");

    for (int i = 0; i < strlen(p); i++)
    {
        if (islower(p[i]) != 0)
        {
            //p[i] += key;
            printf("%c\n", p[i]);
            if ((p[i] + key) >= 122)
            {
                p[i] += key;
                p[i] -= 26;
            }
            else
            {
                p[i] += key;
            }
        }
        else if (isupper(p[i]) != 0)
        {
            //p[i] += key;
            //printf("%c\n", p[i]);
            if ((p[i] + key) >= 90)
            {
                p[i] += key;
                p[i] -= 26;
            }
            else
            {
                p[i] += key;
            }
        }
    }

    printf("ciphertext: %s\n", p);
    return 0;
}