#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include "main_h.cpp"

typedef struct BITMAPFILEHEADER
{
    unsigned int    bfType;
    unsigned long   bfSize;
    unsigned int    bfReserved1;
    unsigned int    bfReserved2;
    unsigned long   bfOffBits;
} BITMAPFILEHEADER;
 
typedef struct BITMAPINFOHEADER
{
    unsigned int    biSize;
    int             biWidth;
    int             biHeight;
    unsigned short  biPlanes;
    unsigned short  biBitCount;
    unsigned int    biCompression;
    unsigned int    biSizeImage;
    int             biXPelsPerMeter;
    int             biYPelsPerMeter;
    unsigned int    biClrUsed;
    unsigned int    biClrImportant;
} BITMAPINFOHEADER;
 
typedef struct RGBQUAD
{
    int   rgbBlue;
    int   rgbGreen;
    int   rgbRed;
    int   rgbReserved;
} RGBQUAD;
int countpix(int x, int y);
#endif // MAIN_H_INCLUDED
