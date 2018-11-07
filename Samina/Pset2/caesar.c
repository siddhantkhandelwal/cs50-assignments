#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if(argc!=2)
    {
        printf("ERROR!\n");
        return 1;
    }
    int k=atoi(argv[1]);
    k=k%26;
    int i=0;
    string s=get_string("plaintext: ");
    while(s[i]!='\0')
    {
        if(isupper(s[i]))
            s[i]=((s[i]-64+k)%26)+64;
        else if(islower(s[i]))
            s[i]=((s[i] -96+k)%26)+96;
        i++;
    }
    printf("ciphertext: %s\n",s);
}
