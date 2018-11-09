#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t  BYTE;
BYTE elem[512];

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: recover infile\n");
        return 1;
    }

    char *infile = argv[1];

    int jpg_no = 0;

    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    FILE *outptr = NULL;
    char fn [8];

    while(fread(elem,512,1,inptr)==1)
    {
        if(elem[0] == 0xff && elem[1] == 0xd8 && elem[2] == 0xff && elem[3]>=0xe0 && elem[3]<=0xef)
        {
            if(jpg_no!=0)
            {
                fclose(outptr);
            }
            snprintf (fn, sizeof fn, "%03d.jpg", jpg_no);
            outptr = fopen(fn, "w");
            fwrite(elem, 512, 1, outptr);
            jpg_no++;
        }
        else
        {
            if(jpg_no!=0)
            {
                fwrite(elem, 512, 1, outptr);
            }
        }
    }
    fclose(outptr);
    return 0;
}