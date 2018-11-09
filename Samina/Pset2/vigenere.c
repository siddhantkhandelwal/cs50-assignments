#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if(argc!=2)
    {
        printf("ERROR!\n");
        return 1;
    }
    int i=0,j=0,factor;
    while(argv[1][i]!='\0')
    {
        if(!(isalpha(argv[1][i])))
        {
            printf("ERROR!\n");
            return 1;
        }
        i++;
    }
    string s=get_string("plaintext: ");
    i=0;
    while(s[i]!='\0')
    {
        if(!isalpha(s[i])) {i++;continue;}

        if(j==strlen(argv[1]))
            j=0;

        if(islower(argv[1][j]))
            factor=97;
        else
            factor=65;

        if(isupper(s[i]))
           s[i]= ((s[i]-64+argv[1][j]-factor)!=26)? (((s[i]-64+argv[1][j]-factor)%26)+64):26+64;
        else if(islower(s[i]))
            s[i]= ((s[i]-96+argv[1][j]-factor)!=26)? (((s[i]-96+argv[1][j]-factor)%26)+96):26+96;

        i++;
        j++;
    }
    printf("ciphertext: %s\n",s);
}
