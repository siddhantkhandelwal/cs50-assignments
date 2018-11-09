#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
 int main(int argc, string argv[])
{
    if(argc!=2)
    {
        printf("An error has occured!\n");
        return 1;
    }

    int x=atoi(argv[1]);
    int y;
    y=x%26;
    int n=0;
    string text=get_string("plaintext: ");

    while(text[n]!='\0')
    {
        if(isupper(text[n]))
        {
            text[n]=((text[n]-64+y)%26)+64;
        }

        else if(islower(text[n]))
        {
            text[n]=((text[n]-96+y)%26)+96;
        }

        n++;
    }
    printf("ciphertext: %s\n",text);
}
