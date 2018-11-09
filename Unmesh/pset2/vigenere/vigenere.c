#include<cs50.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main(int argc,string arg[])
{
    if(argc!=2)
    {printf("Usage: ./vigenere k");return 1;}
    else
    {
        int l = strlen(arg[1]);
        int a[l];
        for(int i=0;i<l;i++)
        {
            if(!isalpha(arg[1][i]))
            {printf("Usage: ./vigenere k");return 1;}
            int t=arg[1][i];
            if((t>=65)&&(t<=90)) a[i]=t-65;
            else a[i]=t-97;
        }
        printf("plain text:");
        string s=get_string();
        printf("cipher text:");
        int other=0;
        for(int i=0;i<strlen(s);i++)
        {
            int t=s[i];
            if((t>=65)&&(t<=90))
            {
                t=((t-65)+a[(i-other)%l])%26;
                t+=65;
            }
            else if((t>=97)&&(t<=122))
            {
                t=((t-97)+a[(i-other)%l])%26;
                t+=97;
            }
            else other++;
            char ch=t;
            printf("%c",ch);
        }
        printf('\n');
    }
}