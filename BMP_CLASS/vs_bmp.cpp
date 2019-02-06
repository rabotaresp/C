// vs_bmp.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"


int main()
{
	char strf[80] = "d:\\Downloads\\20.bmp";
	
	Image_BMP obj(strf);
	obj.readfilebmp();
	obj.WRITEFILE();
	std::cout << obj.count << std::endl;
	obj.HeightF();
	obj.WidthF();	
	obj.counPix();
}
