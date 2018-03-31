#include <iostream>

int main ()
{
	int a = 0;
	int b = 0;
	int c = 0;
	std::cin >> a;
	for (int i=0; i<3; ++i)
	{
		b = a%10;
		c=b+c;
		a = a/10;
	}
	std::cout << c << std::endl;
}
