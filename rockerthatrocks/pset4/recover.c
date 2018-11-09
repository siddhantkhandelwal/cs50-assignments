#include <stdio.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
        return 1;

    char *infile = argv[1];
    FILE* inptr = fopen(infile, "r");

    if (infile == NULL)
        return 2;

    BYTE buffer[512];

    int counter = 0;
    char filename[10];
    FILE* temp = NULL;

    while (!feof(inptr))
    {
        //fread(buffer, 512, 1, inptr);
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            if (temp != NULL)
                fclose(temp);

            sprintf(filename, "%03i.jpg", counter);

            temp = fopen(filename, "w");
            counter++;

            fwrite(buffer, sizeof(buffer), 1, temp);
        }
        else if (counter > 0)
            fwrite(buffer, sizeof(buffer), 1, temp);

        fread(buffer, sizeof(buffer), 1, inptr);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(temp);

    // success
    return 0;
}
