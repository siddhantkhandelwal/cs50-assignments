#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>
typedef uint8_t BYTE;
int main(int argc, char *argv[])
{
    if (argc != 2){
        printf("Usage: ./recover image\n");
        return 1;
    }
    //sprintf(result, "%f", num);
    FILE *file = fopen(argv[1], "r");
    if (file == NULL){
        printf("Could not open the file.\n");
        return 2;
    }
    FILE *outptr = NULL ;
    int image_no = 0 ;
    char outputfile[16] ;
    BYTE buffer[512] ;
    while(!feof(file)){
        int bytesRead = fread(buffer, sizeof(BYTE), 512, file);
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && buffer[3]>=0x00 & buffer[3]<=0xef ){
            if(outptr!=NULL){
                fclose(outptr);
                image_no++;
            }
            sprintf(outputfile, "%03i.jpg", image_no);
            outptr = fopen(outputfile, "w");
        }
        if (outptr != NULL){
            fwrite(buffer, sizeof(BYTE), bytesRead, outptr);
        }
    }
    fclose(outptr);
    fclose(file);
}