#include <iostream>
using namespace std;

int funOdd (int n){
	if (n == 1 || n == 2) return true;
	if (n == 0) return false;
	for (int i= 2; i < n; i++){
		if (n%i==0) return false;
	}
	return true;
	
}

 int main () {
	for (int i = 0; i < 100; i ++)
	{
		if (funOdd (i))
		cout << i << endl;
	}
}
