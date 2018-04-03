#include <iostream>

class A 
{	public:
	int *n;
	int *m;
	A (int n_, int m_){ n = new int (n_); m = new int (m_);}
	A (A const &o) {n = new int(*o.n); m = new int(*o.m);}
	~A() {delete n, delete m;}
};



int main()
{
	A obj(1,2);
	A ob2(obj);
	std::cout << *ob2.n << ' ' << *obj.m << std::endl;
}
