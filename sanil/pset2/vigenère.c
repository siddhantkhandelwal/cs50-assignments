
#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>


int encoder(string s, string keyword);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("incorrect entry. ERROR\n");
        return 1;
    }
    
    for (int i = 0, n_k = strlen(argv[1]); i < n_k; i++)
    {   
        if (!isalpha(argv[1][i]))
        {
            printf("keyword must be entirely alphabetical\n");
            return 1;
        }
    } 
  
    printf("plaintext: ");
    string s = get_string();
  
    printf("ciphertext: ");
    encoder(s, argv[1]);
    
    printf("\n");
}

int encoder(string s, string keyword)
{
	
    for (int i = 0, j = 0, n_s = strlen(s), n_k = strlen(keyword); i < n_s; i++)
    {
    	
        char key = keyword[j % n_k];
        if (isupper(key))
        {
            key -= 65;
        }
        else if (islower(key))
        {
            key -= 97;
        }
        
        if (isupper(s[i]))  
        {
            printf("%c", (s[i] - 65 + key) % 26 + 65);
            j++;
        }
        else if (islower(s[i]))
        {
            printf("%c", (s[i] - 97 + key) % 26 + 97);
            j++;
        }
        else 
        {
            printf("%c", s[i]);
        }
    }
    
    return 0;
}
