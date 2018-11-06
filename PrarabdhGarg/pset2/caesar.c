#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    int key=atoi(argv[1]);
    string text=get_string("plaintext: ");
    char crypt[1000];
    strcpy(crypt,text);
    string alphas="abcdefghijklmnopqrstuvwxyz";
    string alphac="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(int i=0;text[i]!='\0';i++)
    {
        if(text[i]==32)
        {
            crypt[i]=' ';
        }
        if(text[i]>=65 && text[i]<91)
        {
            int j=(text[i]-65+key)%26;
            crypt[i]= alphac[j];
        }
        else if(text[i]>=97 && text[i]<123)
        {
            int j=(text[i]-97+key)%26;
            crypt[i]= alphas[j];
        }
    }
    printf("\nciphertext: %s\n",crypt);
}
