#include <stdio.h>
#include <cs50.h>

/**
 * This method prints stars on a line
 * For eg if the line number it 2, it prints 2 stars
 */


void StarPrinter(int n)
{
    for(int i = 0; i <= n; i++)
    {
        printf("#");
    }
}

int main(void)
{
    int height; //height of the pyramid, entered by user
    
    do
    {
        printf("Height: (less than 24)");
        height = GetInt();
    }while (height > 23 || height < 0);
    
    
    for(int i = 0; i < height; i++)
    {
        for(int j = height; j > i + 1; j--) //Prints the required number of spaces
        {
            printf(" ");
        }
        StarPrinter(i);
        
        printf(" ");
        printf(" ");
        
        StarPrinter(i);
        
        
        
        printf("\n");
    }
}

