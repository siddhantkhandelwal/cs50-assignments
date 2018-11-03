#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<string.h>
#include<cs50.h>

int main(int argc, string argv[])
{
    if(argc!=2)
    { printf("Error");return 1;}
    else
    {
        int k = atoi(argv[1]);
        k=k%26;
        string s;
        printf("plain text:");
        s=get_string();
        printf("cipher text:");
        for(int i=0;i<strlen(s);i++)
        {
            int t=s[i];
            if((t>=65)&&(t<=90))
            {
                t=(t-65+k)%26+65;
            }
            if((t>=97)&&(t<=122))
            {
                t=(t-97+k)%26+97;
            }
            char ch=t;
            printf("%c",ch);
        }
    }
}