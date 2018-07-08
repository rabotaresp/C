#include <iostream>

template<typename T>
class Array
{
	T num;
	public:
	T &get(){return this->num;}
	Array (int num)
	{
		this->num = num;
	}
	bool operator==(Array ob)
	{
		return (ob.num == num)?1:0;
	}
	bool operator!=(Array ob)
	{
		return (ob.num != num)?1:0;
	}
	bool operator<(Array ob)
	{
		return (ob.num < num)?1:0;
	}
	bool operator>(Array ob)
	{
		return (ob.num > num)?1:0;
	}
	T operator++(T)
	{
		return this->num=num+1;
	}
	T operator--(T)
	{
		return this->num=num-1;
	}
	T operator=(T num)
	{
		return this->num=num;
	}
	T operator*()
	{
		return this->num=num;
	}
};

int main()
{
	Array<int>ob(5);
	Array<int> *p = &ob;
	std::cout<<p->get();
}
