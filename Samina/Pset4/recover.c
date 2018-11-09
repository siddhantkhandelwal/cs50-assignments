#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t  BYTE;

int main(int argc, char *argv[])
{
     // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }
    char *infile=argv[1];
    FILE *inptr=fopen(infile,"r");
    FILE *img=NULL;
    if(inptr==NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }
    int ctr=0;
    char filename[]="000.jpg";
    BYTE arr[512];
    while(fread(arr,512,1,inptr)==1)
    {
        if(arr[0]==0xff&&arr[1]==0xd8&&arr[2]==0xff&&(arr[3]&0xf0)==0xe0)
        {
            sprintf(filename,"%03i.jpg",ctr);
            if(ctr!=0) fclose(img);
            img=fopen(filename,"w");
            ctr++;
        }
        if(ctr>0)
        fwrite(arr,512,1,img);
    }
    fclose(inptr);
    return 0;
}
