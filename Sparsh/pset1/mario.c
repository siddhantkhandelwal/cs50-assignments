#include <cs50.h>
#include <stdio.h>

void func1(int i)
{
    for(int n = 0; n < i; n++)
    {
        for(int p=0; p<i-n-1; p++)
        {
            printf(" ");
        }
        for(int q=0; q<n+2; q++)
        {
            printf("#");
        }
        printf("\n");
    }
}

int main(void)
{
    int height=100; //height of the pyramid, initially given a value so that func executes

    while (height > 23 || height < 0)
    {
        printf("Height: (less than 24)");
        height = get_int();
    }


    func1(height);

}
