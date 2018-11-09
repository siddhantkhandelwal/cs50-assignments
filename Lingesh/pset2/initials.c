#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main (void)
{
    string user_name = GetString(); //Stores the name entered by user in user_name variable
    printf("%c", toupper(user_name[0])); //Prints the first character

    //For loop that prints every character after a space
    for(int i = 0, n = strlen(user_name); i < n; i++)
    {
        if(user_name[i] == ' ')
        {
            char c = toupper(user_name[i+1]); //an initial
            printf("%c", c);
        }
    }
    printf("\n");
}
