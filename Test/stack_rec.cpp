#include <iostream>

struct Elem{
	int num;
	Elem * p_prev;
};
class Stack{
	Elem * top;
public:
	Stack() {top = NULL;} 
	Stack(Stack const & ob): top(NULL) 
	{
		r_copy(ob.top);
	}
	void r_copy(Elem* const &  el)
	{
		if(!el) return;
		r_copy(el->p_prev);
		push(el->num);
	}
	void push(int);
	int pop();
	~Stack() {while(top) pop();}
};
void Stack::push(int n){
	Elem * tmp = new Elem;
	tmp->num = n;
	tmp->p_prev = top;
	top = tmp;
}
int Stack::pop(){
	Elem tmp = *top;
	delete top;
	top = tmp.p_prev;
	return tmp.num;
}
int main() {
	Stack obj;
	obj.push(1);
	obj.push(2);
	obj.push(3);
	obj.push(4);
	obj.push(5);
	obj.push(6);
	Stack ob2(obj);
	std::cout << obj.pop() << std::endl;
	std::cout << obj.pop() << std::endl;
	std::cout << obj.pop() << std::endl;
	std::cout << obj.pop() << std::endl;
	std::cout << obj.pop() << std::endl;
	std::cout << obj.pop() << std::endl;
	std::cout << ob2.pop() << std::endl;
	std::cout << ob2.pop() << std::endl;
	std::cout << ob2.pop() << std::endl;
	std::cout << ob2.pop() << std::endl;
	std::cout << ob2.pop() << std::endl;
	std::cout << ob2.pop() << std::endl;
}
