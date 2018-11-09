#include <stdio.h>
#include <cs50.h>
#include <stdint.h>

#define BLOCK_SIZE 512

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        fprintf(stderr, "Usage: recover infile\n");
        return 1;
    }

    char *infile = argv[1];
    FILE *inptr = fopen(infile, "r");

    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    BYTE buffer[512];
    int imageCount = 0;
    char filename[8];
    FILE *outptr = NULL;

     while (!feof(inptr))
    {
        int bytesRead = fread(buffer, sizeof(BYTE), BLOCK_SIZE, inptr);

        bool containsJpegHeader = buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0;

        if (containsJpegHeader)
        {
           if(outptr!=NULL)
           {
            fclose(outptr);
            imageCount++;
            }
            sprintf(filename, "%03i.jpg", imageCount);
            outptr = fopen(filename, "w");
        }

        if (outptr != NULL)
        {
            fwrite(buffer, sizeof(BYTE), bytesRead, outptr);
        }
    }
    fclose(outptr);
    fclose(inptr);
}
