#include <iostream>

template <typename T>
class Array
{
	T size;
	T *p;
	public:
	T get(int  ar)
	{
		if (ar < size)
		{
			return p[ar];
		}
		throw std::out_of_range("Out_of_range!");
	}
	Array(int size)
	{		
		try
		{
			if (size > 0)
			{
				this->size = size;
				p = new T [size];				
			}
			else
			throw std::logic_error("logic Error!");
		}		
		catch (const std::logic_error &e)
		{
			std::cout << e.what();
		}		
	}
	~Array ()
	{
		delete []p;
	}
	Array (const Array & ob)
	{
		size = ob.size;
		p = new T[size];
		for (int i = 0; i < size; i++)
		p[i] = ob.p[i];		
	}
	Array (Array && ob)
	{
		size = ob.size;
		p = ob.p;
		ob.size = 0;
		ob.p = NULL;
	}
	void set()
	{
		T val;
		p = new T[size];
		for (int i = 0; i < size; i++)
		{
			std::cout << "Input numb for array: " << ' ' << std::endl;
			std::cin >> val;
			p[i] = val;
		}
	}
};

int main ()
{
	Array<int> ob1(6);
	Array<int> ob2 = ob1;
	Array<int> ob3 = std::move(ob1);
	ob3.set();
	try
	{
		//std::cout << ob1.get(2)<<std::endl;
		//std::cout << ob2.get(2)<<std::endl;
		std::cout << ob3.get(2)<<std::endl;			
	}
	catch(const std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
	}	
}
