#include <iostream>
using namespace std;

int funVar (int a){
	
	if (a !=0){
	cout << "Output odd numbers? Input - 1" << endl;
	cout << "Output even numbers? Input - 2" << endl;
	cout << "Output numbers multiples 7. Input - 3" << endl;
	} 
}
int funOdd(int a){
	for (int i = 1; i <= a; i ++){
		if ( i%2 !=0)
		{
		cout << i << endl;
		}
	}
}
int funEven (int a){
	for (int i = 1; i <= a; i ++){
		if ( i%2 ==0)
		{
		cout << i << endl;
		}
	}
}
int funSev (int a){
	for (int i = 1; i <= a; i ++){
		if ( i%7 ==0)
		{
		cout << i << endl;
		}
	}
}
		
int main () {
	int a;
	int b;
	cout << "Input numb " ;
	cin >> a;
	funVar(a);
	cin >> b;
	if (b > 3) cout << "Numb not correct!";
	if (b == 1) funOdd(a); 
	if (b == 2) funEven(a);
	if (b == 3) funSev(a);
}
