#include <stdio.h>
#include <cs50.h>
#include <math.h>
int main (void)
{ 
    float amt = -1;
    int k = 0;
    int counter = 0;
    do
    {
        printf("How much change do we owe you? ");
        amt = GetFloat();
    } 
    while (n< 0);
    amt = amt*100;
    amt = round(amt);
    k = amt;
    //quarters
     while (k>=25)
     {
        k = k-25;
        counter++;
     }
     //dimes
     while (k>=10) 
     {
        k = k-10;
        counter++;
     }
    //nickels 
    while (k>=5)
    {
        k = k-5;
        counter++;
    }
    //pennies
    while (k>=1) 
    {
        k = k-1;
        counter++;
    }   
    printf("Minimum coins needed %d ", counter);
    
}
