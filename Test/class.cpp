#include <iostream>

class A 
{	public:
	double sum(double a, double b)
		{
			return a + b;		
		};
	double mult (double a, double b);
		{
			return a * b;
		}
};
class B: public A
{
	double func(double a, double b, double c, double d)
		{
			return (a*b) + (c*d);
		}
}

int main()
{
	B obj;
	
	std::cout << obj.func(5,6,8,4) << std::endl;
	
}
