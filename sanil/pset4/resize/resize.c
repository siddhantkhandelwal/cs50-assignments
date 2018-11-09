//enlarge a BMP image by a factor of f

       
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./resize f infile outfile\n");
        return 1;
    }
    
    // remember resize factor
    float f = atof(argv[1]);
    
    // check resize factor boundaries
    if (f < 1 || f > 100.0)
    {
        fprintf(stderr, "Resize factor between [1, 100]\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file 
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
    // remember old size
    int oldWidth = bi.biWidth;
    int oldHeight = abs(bi.biHeight);
    
    // resize 
    bi.biWidth *= f;
    bi.biHeight *= f;
    
    // remember new size
    int newWidth = bi.biWidth; 
    int newHeight = abs(bi.biHeight);
    
    // determine paddings for old file and new file
    int old_padding = (4 - (oldWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int new_padding = (4 - (newWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    // change image size
    bi.biSizeImage = newHeight * ((newWidth * sizeof(RGBTRIPLE)) + new_padding);
    
    // change file size
    bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);


    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);
    
    // length of an infile line in bytes
    int offset = oldWidth * sizeof(RGBTRIPLE) + old_padding;

    // iterate over infile's scanlines
    for (int i = 0; i < oldHeight; i++)
    {
        // read each scanline f times
        for (int v = 0; v < f; v++)
        {
            // iterate over pixels in scanline
            for (int j = 0; j < oldWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
                
                // write each pixel f times
                for (int h = 0; h < f; h++)
                {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }

            }

            // skip over input padding, if any
            fseek(inptr, old_padding, SEEK_CUR);

            // add output padding if neccessary
            for (int k = 0; k < new_padding; k++)
            {
                fputc(0x00, outptr);
            }

            // return the pointer to the start of the infile line to write vertical copies
            fseek(inptr, -offset, SEEK_CUR); 
        }
        
        // return the pointer to the start of the next line
        fseek(inptr, offset, SEEK_CUR); 
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    return 0;
}
