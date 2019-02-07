#ifndef PCH_H_F
#define PCH_H_F

#include "pch.h"
void TestFunc()
{
	char strf[80];
	int answ;
	std::cout << "Input of link on the file" << std::endl;
	std::cin >> strf;
	Image_BMP obj(strf);
	obj.ReadFileBmp();
	obj.HeightF();
	obj.WidthF();
	obj.counPix();
	std::cout << "select menu item"  << std::endl;	
	std::cout << "Convert picture B-W: 1" << std::endl;
	std::cout << "Convert picture B-W and add mask 8x8: 2" << std::endl;
	std::cout << "luminance pixels > 0x80: 3" << std::endl;	
	std::cout << "Exit on Win: 4" << std::endl;
	std::cin >> answ;
	switch(answ)
	{
		case 1:
		obj.WriteFile();
		break;
		case 2:
		obj.WRITEFILEQube();
		break;
		case 3:
		obj.WriteFile();
		std::cout << "luminance pixels > 0x80: " << obj.count;
		case 4:
		exit(0);
		default:
		std::cout << "Input correct value. 1, 2 or 3.";
		break;
    }
}
#endif
