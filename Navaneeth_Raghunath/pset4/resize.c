// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: copy infile outfile\n");
        return 1;
    }


int n = atoi(argv[1]);
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
    //adding resf for BMPFileH of resultant image
    BITMAPFILEHEADER bf, resf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    resf = bf;

    // read infile's BITMAPINFOHEADER
    //adding resi for BMPInfoH of resultant image
    BITMAPINFOHEADER bi, resi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    resi = bi;

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    resi.biWidth *= n;
    resi.biHeight *= n;
    int newpad = (4 - (resi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    resi.biSizeImage=((sizeof(RGBTRIPLE) * resi.biWidth) + newpad) * abs(resi.biHeight);
    resf.bfSize=resi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);


    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // determine padding for scanlines
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int count = 0;
    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);



            //Repeat pixels to enlarge

            for(int x=0; x<n; x++) {

                fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
            }






        }
        count++;


    if (count==n) {
        count=0;
        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);
    }
    else {
        fseek(inptr,-(bi.biWidth * sizeof(RGBTRIPLE)), SEEK_CUR);
    }

        // then add it back (to demonstrate how)
        for (int k = 0; k < padding; k++)
        {
            fputc(0x00, outptr);
        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
