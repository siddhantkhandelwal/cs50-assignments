#include<cs50.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main(int argc,char* argv[])
{

    if(argc!=2)
    {
        printf("%s\n","Usage: ./vigenere k");
        return 1;
    }
    string m=argv[1];
    for(int i=0;i<strlen(m);i++)
    {
        for(int j=0;j<10;j++)
        {
            if((m[i])==(j +'0'))
            {
                printf("%s\n","Usage: ./vigenere k");
                return 1;
            }
        }
    }
    string s = get_string("plaintext:  ");
    int k=0;
    int p=0;
    for(int i=0;i<strlen(s);i++)
    {
        if(isalpha(s[i]))
        {
            if(isupper(s[i]))
            {
                s[i]=(s[i]-65+toupper(m[k])-65)%26+65;
                k++;
                if(k>strlen(m)-1)
                    k-=strlen(m);
            }
            else
            {
                 s[i]=(s[i]-97+tolower(m[k])-97)%26+97;
                 k++;
                 if(k>strlen(m)-1)
                    k-=strlen(m);
            }
        }
     }
    printf("ciphertext: %s\n",s);
    return 0;
}
