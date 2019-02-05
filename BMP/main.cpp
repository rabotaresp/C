
#include "main.h"

using namespace std;
int main()
{
	char strf[80];
	cout << "input link for file" << endl;
	cin >> strf;
	//"d:\Downloads\002(1).bmp"
    FILE *pFile = fopen("d:\\Downloads\\39.bmp", "rb");
 
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
    int count = 0;
          for (int i = 0; i < bmiHeader.biHeight * bmiHeader.biWidth; i++)
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
        
	cout << "Width: " <<bmiHeader.biWidth << " " << "Height: " << bmiHeader.biHeight << endl;
	cout << count << endl;
	cout << "Pixel count :" << countpix(bmiHeader.biHeight,bmiHeader.biWidth);
	fclose(oFile);    
	delete pixels;
    return 0;
    
}
