# Questions

## What's `stdint.h`?

TODO

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

To have greater flexibility in the datatypes that we are using.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

1,4,4,2

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

424d

## What's the difference between `bfSize` and `biSize`?

bfSize : tells size of bitmap file in bytes
biSize : tells size of structure in bytes

## What does it mean if `biHeight` is negative?

It means it is a uncompressed RGB bitmap written in top to down format and the origin in on the upper left corner.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

if fopen couldn't open the file

## Why is the third argument to `fread` always `1` in our code?

There is only one BITMAPFILEHEADER and BITMAPINFOHEADER. In case of RGBTRIPLE, we want to read the structure one by one.

## What value does line 65 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

3

## What does `fseek` do?

skips over the padding so the that we the program doesn't waste time performing operations on those bytes.

## What is `SEEK_CUR`?

it tells fseek tp skip a specific number of bytes from the current position of the file

## Whodunit?

TODO
