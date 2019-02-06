#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <algorithm>
#include <time.h>

class RGBQUAD{
	public:
	int   rgbBlue;
    int   rgbGreen;
    int   rgbRed;
    int   rgbReserved;
};

class Image_BMP{

	char strf[80];
	//"d:\Downloads\002(1).bmp"
	public:
    FILE *pFile; // = fopen("d:\\P41017\\C++\0020.bmp", "rb");
	
	unsigned int    bfType;
    unsigned long   bfSize;
    unsigned int    bfReserved1;
    unsigned int    bfReserved2;
    unsigned long   bfOffBits;
    
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
        
    RGBQUAD *pixels;
    void ERR()
    {
		if(!pFile)
		{
			std::cout<< "File not open";
			}
    }
	Image_BMP()
	{	
		 pFile = fopen("d:\\P41017\\C++\0020.bmp", "rb");	 
		 void readfilebmp();
		 void ERR();
		 pixels = new RGBQUAD[this->biHeight * this->biWidth];		 
		 void WRITEFILE();
		 std::cout<< "constr";
	}
    
 void readfilebmp(){
    this->bfType      = read_u16(pFile);
    this->bfSize      = read_u32(pFile);
    this->bfReserved1 = read_u16(pFile);
    this->bfReserved2 = read_u16(pFile);
    this->bfOffBits   = read_u32(pFile);
 
    this->biSize          = read_u32(pFile);
    this->biWidth         = read_s32(pFile);
    this->biHeight        = read_s32(pFile);
    this->biPlanes        = read_u16(pFile);
    this->biBitCount      = read_u16(pFile);
    this->biCompression   = read_u32(pFile);
    this->biSizeImage     = read_u32(pFile);
    this->biXPelsPerMeter = read_s32(pFile);
    this->biYPelsPerMeter = read_s32(pFile);
    this->biClrUsed       = read_u32(pFile);
    this->biClrImportant  = read_u32(pFile);
    // инициализация массива пикселей
    // читаем байты цветов
    for (int i = 0; i < biHeight * biWidth; i++) {
        this->pixels[i].rgbBlue = getc(pFile);
        this->pixels[i].rgbGreen = getc(pFile);
        this->pixels[i].rgbRed = getc(pFile);
    }
    fclose(pFile);
}
 
 
 void WRITEFILE(){
    
	FILE *oFile = fopen("output.bmp", "wb");
    // записываем заголовок файла
    this->write_u16(this->bfType, oFile);
    this->write_u32(this->bfSize, oFile);
    this->write_u16(this->bfReserved1, oFile);
    this->write_u16(this->bfReserved2, oFile);
    this->write_u32(this->bfOffBits, oFile);
 
    // записываем заголовок изображения
    this->write_u32(this->biSize, oFile);
    this->write_s32(this->biWidth, oFile);
    this->write_s32(this->biHeight, oFile);
    this->write_u16(this->biPlanes, oFile);
    this->write_u16(this->biBitCount, oFile);
    this->write_u32(this->biCompression, oFile);
    this->write_u32(this->biSizeImage, oFile);
    this->write_s32(this->biXPelsPerMeter, oFile);
    this->write_s32(this->biYPelsPerMeter, oFile);
    this->write_u32(this->biClrUsed, oFile);
    this->write_u32(this->biClrImportant, oFile);

    int count = 0;
          for (int i = 0; i < this->biHeight * this->biWidth; i++)
        {			      
            int s= (pixels[i].rgbBlue+pixels[i].rgbGreen+pixels[i].rgbRed)/3;
            putc(s, oFile);
            putc(s, oFile);
            putc(s, oFile);   
            if(((pixels[i].rgbRed * 0.2126) + (pixels[i].rgbGreen * 0.7152) + (pixels[i].rgbBlue * 0.0722)) > 0x80) // link https://en.wikipedia.org/wiki/Relative_luminance
			{ 
				count++;
			} 
        }  
	fclose(oFile); 
}   
	

static unsigned short read_u16(FILE *fp)
{
    unsigned char b0, b1;
 
    b0 = getc(fp); // 1-st Byte
    b1 = getc(fp);
 
    return ((b1 *256) + b0);
}
 
//DWORD — 32-битное беззнаковое целое
static unsigned int read_u32(FILE *fp)
{
    unsigned char b0, b1, b2, b3;
 
    b0 = getc(fp); // 1-st Byte
    b1 = getc(fp);
    b2 = getc(fp);
    b3 = getc(fp);
 
    return ((((((b3 *256) + b2) *256) + b1) *256) + b0);
}
 
//LONG — 32-битное целое со знаком
static int read_s32(FILE *fp)
{
    unsigned char b0, b1, b2, b3;
 
    b0 = getc(fp); // 1-st Byte
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

 };
