#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 512

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        fprintf(stderr, "Usage: copy infile outfile\n");
        return 1;
    }

    FILE* input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file\n");
        return 1;
    }

    // create buffer
    unsigned char buffer[BUFFER_SIZE];

    int filecount = 0;

    FILE* picture = NULL;

    int jpeg_found = 0; //false

    while (fread(buffer, BUFFER_SIZE, 1, input) == 1)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && buffer[3] == 0xe0)
        {
            if (jpeg_found == 1)
            {
                fclose(picture);
            }
            else
            {
                jpeg_found = 1;
            }

            char filename[8];
            sprintf(filename, "%03d.jpg", filecount);
            picture = fopen(filename, "a");
            filecount++;
        }

        if (jpeg_found == 1)
        {
            // write 512 bytes to file once we start finding jpgs
            fwrite(&buffer, BUFFER_SIZE, 1, picture);
        }

    }

    // close files
    fclose(input);
    fclose(picture);

    return 0;
}