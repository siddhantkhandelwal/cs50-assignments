#include <cs50.h>
#include <stdio.h>
#include <string.h>

int cipher(string s, int k); 

int main(int argc, char *argv[]) 
{
	if (argc != 2)
	{
		printf("incorrect entry .ERROR\n");
		return 1;
	}

	printf("plaintext: ");
	string s = get_string();
	
	int k = atoi(argv[1]) % 26;
	
	printf("ciphertext: ");
	cipher(s, k);
	printf("\n");
}

int decipher(string s, int k)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (islower(s[i]))
	    {
	        printf("%c", (s[i] -97 + k) % 26 + 97);
	    }
	    else if (isupper(s[i]))
	    {
	        printf("%c", (s[i] - 65 + k) % 26 + 65);
	    }
	    else
	    {
	        printf("%c", s[i]);
	    }
    }
    return 0;
}
