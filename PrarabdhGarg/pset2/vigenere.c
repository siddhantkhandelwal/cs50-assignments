#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    string key=argv[1];
    int k;
    for(k=0;key[k]!='\0';k++);
    string text=get_string("plaintext: ");
    char crypt[1000];
    strcpy(crypt,text);
    string alphas="abcdefghijklmnopqrstuvwxyz";
    string alphac="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(int i=0,t=0;text[i]!='\0';i++,t++)
    {
        if(text[i]==32)
        {
            crypt[i]=' ';
            t--;
        }
        if(text[i]>=65 && text[i]<91)
        {
            int j=(text[i]-65+(key[t%k]-97))%26;
            crypt[i]= alphac[j];
        }
        else if(text[i]>=97 && text[i]<123)
        {
            int j=(text[i]-97+(key[t%k]-97))%26;
            crypt[i]= alphas[j];
        }
    }
    printf("\nciphertext: %s\n",crypt);
}
