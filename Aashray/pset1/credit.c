#include <cs50.h>
#include <stdio.h>
int noofdigits(unsigned long long n){
int number = 0 ;
while(n!=0){
    n = n/10 ;
    number++ ;
}
return number ;
}
int firsttwodigits(unsigned long long N){
   unsigned long long a = N ;
   for (int i=0;i<noofdigits(N)-2 ;i++){
       a = (unsigned long long)(a/10) ;
   }
   return (int)a ;
}
bool check(unsigned long long N, int n){
    int a =0 ;
    int b = 0 ;
    for (int i=1;i<=n;i++){
        if (i%2==1) {
            a = a + N%10  ;
        } else {
            b = b + (2*(N%10))%10 + (2*(N%10))/10 ;
        }
        N=N/10 ;
            }
    if ((a+b)%10==0){
        return true ;
    } else {
        return false ;
    }
}
int main(void) {
unsigned long long creditcard = get_long_long("Number : ") ;
int b = firsttwodigits(creditcard) ;
int n = noofdigits(creditcard) ;
if((b==34||b==37)&&n==15){
  // for AMEX check
  if (check(creditcard, n)){
      printf("AMEX\n") ;
  }else {
      printf("INVALID\n") ;
  }
}else {
    if (b>=40 && b<=49 && (n==13 || n==16)){
     // for VISA check
       if (check(creditcard, n)){
      printf("VISA\n") ;
  }else {
      printf("INVALID\n") ;
  }
    } else {
        if (b>50 && b<56 &&n==16){
         //for MASTERCARD check
           if (check(creditcard, n)){
      printf("MASTERCARD\n") ;
  }else {
      printf("INVALID\n") ;
  }
        }else {
            printf("INVALID\n") ;
        }
    }

    }
    return 0 ;
}