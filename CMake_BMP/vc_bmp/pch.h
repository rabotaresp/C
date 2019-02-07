// Данный класс имеет следующий функционал:
//- Загрузка\сохранение данных из файла bmp формата. (во время загрузки файл конвертироваться в ч\б изображение).
//- Функции доступа к данным изображения (пикселям (counPix()), строкам (WidthF()), столбцам (HeightF())).


#ifndef PCH_H
#define PCH_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <algorithm>
#include <time.h>

class RGBQUAD {
public:
        int   rgbBlue;
        int   rgbGreen;
        int   rgbRed;
        int   rgbReserved;
};

class Image_BMP {

public:
        FILE *pFile = NULL;

    int count = 0;

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

        Image_BMP(char strf[80])
        {
                pFile = fopen(strf, "rb");
        }
        void ReadFileBmp() {

                this->bfType = read_u16(pFile);
                this->bfSize = read_u32(pFile);
                this->bfReserved1 = read_u16(pFile);
                this->bfReserved2 = read_u16(pFile);
                this->bfOffBits = read_u32(pFile);

                this->biSize = read_u32(pFile);
                this->biWidth = read_s32(pFile);
                this->biHeight = read_s32(pFile);
                this->biPlanes = read_u16(pFile);
                this->biBitCount = read_u16(pFile);
                this->biCompression = read_u32(pFile);
                this->biSizeImage = read_u32(pFile);
                this->biXPelsPerMeter = read_s32(pFile);
                this->biYPelsPerMeter = read_s32(pFile);
                this->biClrUsed = read_u32(pFile);
                this->biClrImportant = read_u32(pFile);
                // инициализация массива пикселей
                pixels = new RGBQUAD[biHeight * biWidth];
                // читаем байты цветов
                for (int i = 0; i < biHeight * biWidth; i++) {
                        pixels[i].rgbBlue = getc(pFile);
                        pixels[i].rgbGreen = getc(pFile);
                        pixels[i].rgbRed = getc(pFile);
                }

                fclose(pFile);
        }

        void HeightF()
        {
                std::cout << "Height: " <<  biHeight << std::endl;
        }

        void WidthF()
        {
                std::cout << "Width: " <<  biWidth << std::endl;
        }

        void counPix()
        {
                std::cout << "Pixels: " << biHeight * biWidth << std::endl; //Количество пикселей во всем файле. Если нужно получить указатель, то это pixels.
        }

        void WriteFile() {

                FILE *oFile = fopen("output.bmp", "wb");

                // записываем заголовок файла
                write_u16(this->bfType, oFile);
                write_u32(this->bfSize, oFile);
                write_u16(this->bfReserved1, oFile);
                write_u16(this->bfReserved2, oFile);
                write_u32(this->bfOffBits, oFile);

                // записываем заголовок изображения
                write_u32(this->biSize, oFile);
                write_s32(this->biWidth, oFile);
                write_s32(this->biHeight, oFile);
                write_u16(this->biPlanes, oFile);
                write_u16(this->biBitCount, oFile);
                write_u32(this->biCompression, oFile);
                write_u32(this->biSizeImage, oFile);
                write_s32(this->biXPelsPerMeter, oFile);
                write_s32(this->biYPelsPerMeter, oFile);
                write_u32(this->biClrUsed, oFile);
                write_u32(this->biClrImportant, oFile);

                for (int i = 0; i < biHeight * biWidth; i++)
                {
            int s = (pixels[i].rgbBlue + pixels[i].rgbGreen + pixels[i].rgbRed) / 3;
                        putc(s, oFile);
                        putc(s, oFile);
                        putc(s, oFile);
                        if (((pixels[i].rgbRed * 0.2126) + (pixels[i].rgbGreen * 0.7152) + (pixels[i].rgbBlue * 0.0722)) > 0x80) // link https://en.wikipedia.org/wiki/Relative_luminance
                                {
                                        count++;
                                }
                }
                fclose(oFile);
                delete pixels;
        }
        void WRITEFILEQube() {
        FILE *oFile = fopen("output.bmp", "wb");
        // записываем заголовок файла
        write_u16(this->bfType, oFile);
        write_u32(this->bfSize, oFile);
        write_u16(this->bfReserved1, oFile);
        write_u16(this->bfReserved2, oFile);
        write_u32(this->bfOffBits, oFile);
        // записываем заголовок изображения
        write_u32(this->biSize, oFile);
        write_s32(this->biWidth, oFile);
        write_s32(this->biHeight, oFile);
        write_u16(this->biPlanes, oFile);
        write_u16(this->biBitCount, oFile);
        write_u32(this->biCompression, oFile);
        write_u32(this->biSizeImage, oFile);
        write_s32(this->biXPelsPerMeter, oFile);
        write_s32(this->biYPelsPerMeter, oFile);
        write_u32(this->biClrUsed, oFile);
        write_u32(this->biClrImportant, oFile);
        int index = 0;
        int s;
        for(int h = 0; h<4;h++){
            for (int j = 0; j< biHeight/8; j++){
                for(int i = 0; i < 4; i++){
                    for(int k = 0; k<biWidth/8 ; k++, index++){
                       s = (pixels[index].rgbBlue + pixels[index].rgbGreen + pixels[index].rgbRed) / 3;
                       if((s+100)>255)s=255;
                       putc(s, oFile);
                       putc(s, oFile);
                       putc(s, oFile);
                    }
                    for(int m = 0; m<biWidth/8; m++, index++){
                        s = (pixels[index].rgbBlue + pixels[index].rgbGreen + pixels[index].rgbRed) / 3;
                        if((s-100)<0)s=20;
                        putc(s, oFile);
                        putc(s, oFile);
                        putc(s, oFile);
                    }
                }
            }
            for (int j = 0; j< biHeight/8; j++){
                for(int i = 0; i < 4; i++){
                    for(int k = 0; k<biWidth/8 ; k++, index++){
                        s = (pixels[index].rgbBlue + pixels[index].rgbGreen + pixels[index].rgbRed) / 3;
                        if((s-100)<0)s=20;
                        putc(s, oFile);
                        putc(s, oFile);
                        putc(s, oFile);
                    }
                    for(int m = 0; m<biWidth/8; m++, index++){
                        s = (pixels[index].rgbBlue + pixels[index].rgbGreen + pixels[index].rgbRed) / 3;
                        if((s+100)>255)s=255;
                        putc(s, oFile);
                        putc(s, oFile);
                        putc(s, oFile);
                    }
                }
            }
        }
        fclose(oFile);
        delete pixels;
}
        static unsigned short read_u16(FILE *fp)
        {
                unsigned char b0, b1;

                b0 = getc(fp); // 1-st Byte
                b1 = getc(fp);

                return ((b1 * 256) + b0);
        }

        //DWORD — 32-битное беззнаковое целое
        static unsigned int read_u32(FILE *fp)
        {
                unsigned char b0, b1, b2, b3;

                b0 = getc(fp); // 1-st Byte
                b1 = getc(fp);
                b2 = getc(fp);
                b3 = getc(fp);

                return ((((((b3 * 256) + b2) * 256) + b1) * 256) + b0);
        }

        //LONG — 32-битное целое со знаком
        static int read_s32(FILE *fp)
        {
                unsigned char b0, b1, b2, b3;

                b0 = getc(fp); // 1-st Byte
                b1 = getc(fp);
                b2 = getc(fp);
                b3 = getc(fp);

                return ((int)(((((b3 * 256) + b2) * 256) + b1) * 256) + b0);
        }

        static void write_u16(unsigned short input, FILE *fp)
        {
                putc(input, fp);
                putc((input / 256) % 256, fp);
        }

        static void write_u32(unsigned int input, FILE *fp)
        {
                putc(input, fp);
                putc((input / 256) % 256, fp);
                putc((input / 256 / 256) % 256, fp);
                putc((input / 256 / 256 / 256) % 256, fp);
        }

        static void write_s32(int input, FILE *fp)
        {
                putc(input, fp);
                putc((input / 256) % 256, fp);
                putc((input / 256 / 256) % 256, fp);
                putc((input / 256 / 256 / 256) % 256, fp);
        }

};
#endif
