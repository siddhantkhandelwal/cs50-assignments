#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int minutes;
    int bottles;
    
    printf("Minutes: ");
    minutes = GetInt();
    
    while(minutes < 1)
    {
        printf("Retry: ");
        minutes = GetInt();
    }
    
    bottles = minutes * 12;  //One minute in shower uses about 12 bottles of water
    
    printf("Bottles: %d\n", bottles);
}