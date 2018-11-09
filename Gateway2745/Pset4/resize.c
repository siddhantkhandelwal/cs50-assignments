#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // Ensure proper usage
    if (argc != 4)
    {
        printf("Usage: resize factor infile outfile\n");
        return 1;
    }

    // remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];

    int n = atoi(argv[1]);

    if (n<1 || n>100)
    {
        printf("n must be in range 1 to 100\n");
        return 1;
    }

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
    BITMAPFILEHEADER bf, bfr;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    bfr = bf;

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi, bir;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    bir = bi;

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // Determine the new dimensions
    bir.biWidth  = bi.biWidth * n;
    bir.biHeight = bi.biHeight * n;

    // Determine the old and new paddings
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) %4) % 4;
    int npadding = (4 - (bir.biWidth * sizeof(RGBTRIPLE)) %4) % 4;

    // Determine new image sizes
    bir.biSizeImage = (bir.biWidth * sizeof(RGBTRIPLE) + npadding) * abs(bir.biHeight);
    bfr.bfSize = bf.bfSize - bi.biSizeImage + bir.biSizeImage;

    // write outfile's BITMAPFILEHEADER
    fwrite(&bfr, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bir, sizeof(BITMAPINFOHEADER), 1, outptr);

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // iterate over pixels in scanline
            for (int k = 0; k < bi.biWidth; k++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
                for (int l = 0; l < n; l++)
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
            }
            for (int l = 0; l < npadding; l++)
                fputc(0x00, outptr);
            if (j < n- 1)
                fseek(inptr, -bi.biWidth * sizeof(RGBTRIPLE), SEEK_CUR);
        }

        // Skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
