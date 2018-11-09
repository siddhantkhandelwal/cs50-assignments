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

    int k = atoi(argv[1]);


    string input = GetString();

    for(int i = 0, n = strlen(input); i < n; i++)
    {
        if(isupper(input[i]))
        {
            if(input[i] + (k % 26) > 'Z')
                input[i] -= 26;

            input[i] += k % 26;
        }
        else if(islower(input[i]))
        {
            if(input[i] + (k % 26) > 'z')
                input[i] -= 26;

            input[i] += k % 26;
        }

    }

    printf("%s\n", input);
}
