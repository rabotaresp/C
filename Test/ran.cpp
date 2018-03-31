#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

int main()
{

	srand( time( 0 ) ); 
	int a = 1 + rand() % 3;
	
	int b;
	
	cout << "Введите номер наперстка '1' '2' '3' - ";
	cin >> b;
		if (b==a) cout << "CONGRATULATIONS! You won!";
		if (b!=a) cout << "Correct number -"  << a; cout << "You did not guess :). Do you want to try again?"; 
  
  
    //cout << "Введите номер наперстка '1' '2' '3'= " << 1 + rand() % 3 << endl;
    //system("pause");
     
}
