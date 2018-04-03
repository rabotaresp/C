#include <iostream>

class A 
{	public:
	double sum(double a, double b)
		{
			return a + b;		
		}
	double mult (double a, double b)
		{
			return a * b;
		}
};
class B: public A
{
	public:
	double func(double a, double b, double c, double d)
		{
			return sum(mult(a,b),mult(c,d));
			//(a*b) + (c*d);
		}
};

int main()
{
	B obj;
	
	std::cout << obj.func(5,6,34,4) << std::endl;
	
}
