#include <stdio.h>
void spaces(int n){
    for(int i=0;i<n;i++){
printf(" ") ;
    }
}
void hashes(int n){
    for(int i=0;i<n;i++){
printf("#") ;
    }
printf(" ") ;
    for(int i=0;i<n;i++){
printf("#") ;
    }
printf("\n") ;
}
int main(void)
{
int hieght = 0 ;
while(hieght<1 || hieght>8){
    printf("Hieght :") ;
    scanf("%d", &hieght) ;
}
for(int i=hieght-1;i>=0;i--){
    spaces(i) ;
    hashes(hieght-i) ;
}
    return 0 ;
}
