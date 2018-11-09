#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./copy infile outfile\n");
        return 1;
    }

    int n = atoi(argv[1]);

    if (n < 1)
    {
        printf("Scale must be greater than 0\n");
        return 1;
    }
    char* infile = argv[2];
    char* outfile = argv[3];

    // open input file
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
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

    // create outfile's BITMAPFILEHEADER and BITMAPINFOHEADER
    BITMAPFILEHEADER bf_output = bf;
    BITMAPINFOHEADER bi_output = bi;

    // dimensions for the outfile
    bi_output.biWidth *= n;
    bi_output.biHeight *= n;

    // determine padding for scanlines
    int in_padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int out_padding = (4 - (bi_output.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // determine the outfile biSizeImage and bfSize (biSizeImage + 54 bytes header files)
    bi_output.biSizeImage = abs(bi_output.biHeight) * (bi_output.biWidth * sizeof(RGBTRIPLE) + out_padding);
    bf_output.bfSize = (bi_output.biSizeImage + 54);

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf_output, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi_output, sizeof(BITMAPINFOHEADER), 1, outptr);

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        for (int jj = 0; jj < n; jj++)
        {
            // set pointer to beginning of line
            fseek(inptr, 54 + (bi.biWidth * 3 + in_padding) * i, SEEK_SET);

            // iterate over pixels in scanline
            for (int k = 0; k < bi.biWidth; k++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                // iterate each pixel n times
                for (int ii = 0; ii < n; ii++)
                {
                    // write RGB triple to outfile
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }

            // then add it back to outfile
            for (int kk = 0; kk < out_padding; kk++)
            {
                fputc(0x00, outptr);
            }
        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    return 0;
}