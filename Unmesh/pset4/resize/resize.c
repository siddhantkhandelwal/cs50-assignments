// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: resize n infile outfile\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];
    int n=atoi(argv[1]);

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
        int h=abs(bi.biHeight);
        int w=bi.biWidth;
        int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
        bi.biWidth = bi.biWidth * n;
        bi.biHeight = bi.biHeight * n;
        int paddingo =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
        bi.biSizeImage = (bi.biWidth * abs(bi.biHeight) * 3) + (padding * bi.biWidth);
        bf.bfSize = bi.biSizeImage + 54;

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // determine padding for scanlines

    // iterate over infile's scanlines
    for (int i = 0; i < h; i++)
    {
        // iterate over pixels in scanline
        RGBTRIPLE* buffer=malloc(bi.biWidth*sizeof(RGBTRIPLE));
        for (int j = 0; j < w; j++)
        {
            // temporary storage
            RGBTRIPLE triple;
            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
            buffer[j]=triple;

            //fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
        }
        for(int k=0;k<n;k++){
        for (int j = 0; j < w; j++)
        {
            for(int q=0;q<n;q++)
            {
                fwrite(&buffer[j], sizeof(RGBTRIPLE), 1, outptr);
            }
        }}

        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);

        // then add it back (to demonstrate how)
        for (int k = 0; k < paddingo; k++)
        {
            fputc(0x00, outptr);
        }
        free(buffer);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
