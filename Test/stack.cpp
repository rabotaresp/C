#include <iostream>

struct Elem{
	int num;
	Elem * p_prev;
};
class Stack{
	Elem * top;
public:
	int *n;
	Stack() {top = NULL;} 
	Stack(Stack const & ob) {}
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
	Stack ob2(obj);
	std::cout << obj.pop() << std::endl;
	std::cout << obj.pop() << std::endl;
	std::cout << obj.pop() << std::endl;
}
