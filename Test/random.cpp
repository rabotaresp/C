#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	srand( time( 0 ) ); 
	int a = 1 + rand() % 3;
	int b;
	cout << "Enter the number of the thimble '1' '2' '3' - ";
	cin >> b;
		if (b==a) cout << "CONGRATULATIONS! You won!";
		if (b!=a) cout << "Correct number -"  << a << " You did not guess :). Do you want to try again?"; 
  
}
