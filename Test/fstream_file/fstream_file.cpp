#include <iostream>
#include <fstream>

int main()
{
	char buf1[4];
	char buf2[4];
	std::ofstream file ("numb.txt");
	file << "1234 5678 4567";
	file.close();
	std::fstream file_rw("numb.txt");
	file_rw.seekp(5,std::ios::beg);
	file_rw>>buf1;
	file_rw.seekp(9,std::ios::beg);
	file_rw>>buf2;
	file_rw.clear();
	file_rw.seekp(5,std::ios::beg);
	file_rw<<buf2;
	std::cout<<buf2<<' ';
	file_rw.seekp(10,std::ios::beg);
	file_rw<<buf1;
	std::cout<<buf1<<' ';
	file_rw.close();
}
