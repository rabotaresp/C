#include <iostream>
using namespace std;

int main () {
	// Верх звезды
	for (int i=0; i<6; i++)
	{
		for(int k=7; k>i; k--)
		{
			cout << ' ' ;
		}
			for (int j=1; j<i; j++)
			{
			cout << '*' ;
			}
				for (int n=0; n<i; n++)
				{
				cout << '*' ;
				}
	cout <<endl;
	}
}
