#include <iostream>

int func(int num)
{
	if (num ==1 || num == 0) return 1;
	return func (num-1) * num;
} 
void show (int num)
{
	if (num < 10) {std:: cout << num << std::endl; return;}
	show(num/10);
	std::cout << num%10 << std::endl;
}

int main ()
{
	std::cout << func(5) << std::endl;
	show(12345);
}
