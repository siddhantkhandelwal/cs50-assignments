#include <cs50.h>
#include <stdio.h>
#include <string.h>
int main(int argc, string argv[])
{
if (argc==2 && strspn(argv[1], "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM")==strlen(argv[1])){
    char s[100] ;
    char arg[100] ;
    printf("plaintext : ") ;
    scanf("%[^\n]s", s) ;
    //printf("%s   ", s) ;
    int ns = strlen(s) ;
    int narg = strlen(argv[1]) ;
    int sarg[narg] ;
    for (int i = 0; i<narg ; i++ ){
        int d = (int)argv[1][i] ;
        if(d>96 && d<123){
        // lower case letters
        sarg[i] = (int) (d-97) ;
        } else if ( d>64 && d<91){
        // upper case letters
        sarg[i] = (int) (d-65);
        }
    }
    int i = 0 ;
    int j ;
    while(i<ns){
        j = 0 ;
        while(i<ns && j<narg){
            int d = (int)s[i] ;
            int a = sarg[i] ;
            if(d>96 && d<123){
            // lower case letters
                s[i] = (char) (96 + (d-96+a)%26) ;
           } else if ( d>64 && d<91){
            // upper case letters
                s[i] = (char) (64 + (d-64+a)%26) ;
        }
                    j++ ;
                    i++ ;
            if (s[i]==' '){
                i++ ;
            }
    }

}
printf("ciphertext : %s\n", s) ;
}else {
    printf("Usage: ./vigenere keyword") ;
}
}