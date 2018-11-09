/* To recover jpeg files given a raw file
*
*  Usage: ./recover image
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[]){
    
    //proper usage
    if(argc != 2){
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }
    
    //store raw file name
    char *card = argv[1];
    
    //open raw file
    FILE *raw = fopen(card, "r");
    if (raw == NULL){
        fprintf(stderr, "Could not open %s.\n", card);
        return 2;
    }   
    
    uint8_t buffer[512]; //to store a temporary block of memory of size 512 bytes
    
    int count = 0; //keep track of number of jpegs created
    
    FILE *outjpeg = NULL; //to create the jpeg
    char name[8]; //names of jepgs to be created
    int firstJpgCreated = 0;
    
    //read in the bytes of the memory card, 512 blocks at a time, 1 byte each
    while(fread(buffer, 512, 1, raw)){
        
        //checking if start of a jpeg
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0){
            
            //closing previous files (excpet the first time)
            if(count != 0)
                fclose(outjpeg);
            //flag to know when the first jpg is created
            else
                firstJpgCreated = 1;
            
            //create a new jpg
            sprintf(name, "%03i.jpg", count++);
            outjpeg = fopen(name, "w");
            
        }
        
        //write the data to the jpeg
        if(firstJpgCreated)
            fwrite(buffer, 512, 1, outjpeg);
    }
    
    //close card
    fclose(raw);
    
    //close jpg
    fclose(outjpeg);
    
    //success
    return 0;
}