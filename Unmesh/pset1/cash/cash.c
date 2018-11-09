#include <stdio.h>

int main(void)
{
    float c=0.0;
    printf("Cash owed:");
    scanf("%f",&c);
    while((c<=0.0))
        {printf("Cash owed:");
        scanf("%f",&c);}
    int ch=(c*100);
    int ans= ch/25 + (ch%25)/10 + ((ch%25)%10)/5 + (((ch%25)%10)%5);
    printf("%i\n",ans);
}