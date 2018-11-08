#include <cs50.h>
#include <stdio.h>
#include <ctype.h> //char adjustment
#include <string.h>

int main(void)
{
 printf("Enter your name "); 
 string s = get_string(); 
 int i;
 int n;
 if (s != NULL) //makes sure that the string entered is a valid
 {
   for (i=0, n= strlen(s); i<n; i++) 
   {
    if (i==0) //first letter
    {
      printf("%c", toupper(s[i])); //capitalised letter
    }
    if ( i-1== ' ') //looks for the character after a space
    {
      i++;
      printf("%c", toupper(s[i])); 
    }
   }
 }
  printf("\n");
}
