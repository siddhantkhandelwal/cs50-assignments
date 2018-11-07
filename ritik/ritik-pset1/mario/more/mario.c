#include <stdio.h>

int main(void)
{
    int height = 0;
    do
    {
        printf("Please enter the height of your half-pyramids (between 0 and 23): ");
        scanf("%d",&height);
    }
    while(height < 0 || height > 23);
    for (int ii = 0; ii < height; ii++)
    {
        for(int jj = 0; jj < height - ii - 1; jj++)
        {
            printf(" ");
        }
        for(int kk = 0; kk < ii + 1; kk++)
        {
            printf("#");
        }
        printf(" ");
        printf(" ");
        for(int kk = 0; kk < ii + 1; kk++)
        {
            printf("#");
        }
        for(int jj = 0; jj < height - ii - 1; jj++)
        {
            printf(" ");
        }
        printf("\n");
    }

    return 0;
}