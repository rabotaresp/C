#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <algorithm>
#include <time.h>
#include "main.h"
using namespace std;
int main()
{
    setlocale(LC_ALL , "Russian");
    printf("Пожалуйста, выберете фильтр 1,2 или 3\n");
    FILE *pFile = fopen("002.bmp", "rb");
 
    // считываем заголовок файла
    BITMAPFILEHEADER header;
 
    header.bfType      = read_u16(pFile);
    header.bfSize      = read_u32(pFile);
    header.bfReserved1 = read_u16(pFile);
    header.bfReserved2 = read_u16(pFile);
    header.bfOffBits   = read_u32(pFile);
 
    // считываем заголовок изображения
    BITMAPINFOHEADER bmiHeader;
 
    bmiHeader.biSize          = read_u32(pFile);
    bmiHeader.biWidth         = read_s32(pFile);
    bmiHeader.biHeight        = read_s32(pFile);
    bmiHeader.biPlanes        = read_u16(pFile);
    bmiHeader.biBitCount      = read_u16(pFile);
    bmiHeader.biCompression   = read_u32(pFile);
    bmiHeader.biSizeImage     = read_u32(pFile);
    bmiHeader.biXPelsPerMeter = read_s32(pFile);
    bmiHeader.biYPelsPerMeter = read_s32(pFile);
    bmiHeader.biClrUsed       = read_u32(pFile);
    bmiHeader.biClrImportant  = read_u32(pFile);
 
 
    // инициализация массива пикселей
    RGBQUAD *pixels = new RGBQUAD[bmiHeader.biHeight * bmiHeader.biWidth];
 
    // читаем байты цветов
    for (int i = 0; i < bmiHeader.biHeight * bmiHeader.biWidth; i++) {
        pixels[i].rgbBlue = getc(pFile);
        pixels[i].rgbGreen = getc(pFile);
        pixels[i].rgbRed = getc(pFile);
    }
    fclose(pFile);
 
 
    FILE *oFile = fopen("output.bmp", "wb");
 
    // записываем заголовок файла
    write_u16(header.bfType, oFile);
    write_u32(header.bfSize, oFile);
    write_u16(header.bfReserved1, oFile);
    write_u16(header.bfReserved2, oFile);
    write_u32(header.bfOffBits, oFile);
 
    // записываем заголовок изображения
    write_u32(bmiHeader.biSize, oFile);
    write_s32(bmiHeader.biWidth, oFile);
    write_s32(bmiHeader.biHeight, oFile);
    write_u16(bmiHeader.biPlanes, oFile);
    write_u16(bmiHeader.biBitCount, oFile);
    write_u32(bmiHeader.biCompression, oFile);
    write_u32(bmiHeader.biSizeImage, oFile);
    write_s32(bmiHeader.biXPelsPerMeter, oFile);
    write_s32(bmiHeader.biYPelsPerMeter, oFile);
    write_u32(bmiHeader.biClrUsed, oFile);
    write_u32(bmiHeader.biClrImportant, oFile);
 
    // записываем байты цветов
    int fil;
    cout<<"1. Негатив\n2. Оттенок серого\n3. Random\n ";
    cin>>fil;
    if (fil==1)
       {cout<<"Вы выбрали негатив.\n ";
        for (int i = 0; i < bmiHeader.biHeight * bmiHeader.biWidth; i++)
        {
            putc(255-pixels[i].rgbBlue, oFile);
            putc(255-pixels[i].rgbGreen , oFile);
            putc(255-pixels[i].rgbRed , oFile);}
       }
 
    if (fil==2)
      {cout<<"Вы выбрали оттенок серого.\n";
          for (int i = 0; i < bmiHeader.biHeight * bmiHeader.biWidth; i++)
        {
            int s= (pixels[i].rgbBlue+pixels[i].rgbGreen+pixels[i].rgbRed)/3;
            putc (s, oFile);
            putc(s , oFile);
            putc(s, oFile);}
 
      }
      
    if (fil==3)
        {cout<<"Вы выбрали random.\n";
        int x,y,z;
        srand(time(NULL));
        x=rand();
        y=rand();
        z=rand();
        
            for (int i = 0; i < bmiHeader.biHeight * bmiHeader.biWidth; i++)
            {
            putc(pixels[i].rgbBlue+x, oFile);
            putc(pixels[i].rgbGreen+y , oFile);
            putc(pixels[i].rgbRed+z , oFile);}
 
        }
        
 
    fclose(oFile);
    printf("Можете открыть output.bmp\n");
    return 0;
}
 
 
static unsigned short read_u16(FILE *fp)
{
    unsigned char b0, b1;
 
    b0 = getc(fp);
    b1 = getc(fp);
 
    return ((b1 *256) + b0);
}
 
 
static unsigned int read_u32(FILE *fp)
{
    unsigned char b0, b1, b2, b3;
 
    b0 = getc(fp);
    b1 = getc(fp);
    b2 = getc(fp);
    b3 = getc(fp);
 
    return ((((((b3 *256) + b2) *256) + b1) *256) + b0);
}
 
 
static int read_s32(FILE *fp)
{
    unsigned char b0, b1, b2, b3;
 
    b0 = getc(fp);
    b1 = getc(fp);
    b2 = getc(fp);
    b3 = getc(fp);
 
    return ((int)(((((b3 *256) + b2) *256) + b1) *256) + b0);
}
 
static void write_u16(unsigned short input, FILE *fp)
{
    putc(input, fp);
    putc((input /256) % 256, fp);
}
 
static void write_u32(unsigned int input, FILE *fp)
{
    putc(input, fp);
    putc((input /256) % 256, fp);
    putc((input /256/256) % 256, fp);
    putc((input /256/256/256) % 256, fp);
}
 
static void write_s32(int input, FILE *fp)
{
    putc(input, fp);
    putc((input /256) % 256, fp);
    putc((input /256/256) % 256, fp);
    putc((input /256/256/256) % 256, fp);
}
