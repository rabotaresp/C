#include <iostream>
using namespace std;

int main()
{
	int a;
	int b;
	cout << "Input numb - ";
	cin >> a;
	cout << "Input second numb - ";
	cin >> b;
	
	//Задача 8
	/*if (a%3==0 && a%5==0)
		{
			if(b%2==0)
				{
					if (a<100)
					{
						cout << b*a << endl;
					}
					else 
					{
						cout << b+a << endl;
					}
				}
				else
				{
					cout << a-b << endl;
				}
		}
		else 
		{
			cout << a << " - Not a multiple of 3 and 5" << endl;
			cout << b << endl;
		}*/
		// Задача 9
		/*if (a>10 && a<80)
		{
			if (a<b && b==66)
			{
				cout << a+b << endl;
			}
			if (a>b && a!=44)
			{
				cout << a-b << endl;
			}
			if (a==44 || a==66)
			{
				cout << a/2 << endl;
			}
		}		*/
			//Задача 10
			if (a>0 && b>0)
			{
				if (a%2==0)
				{
					cout << "The first number is even" << endl; 
				}
				else 
				{
					cout << "The first number is odd" << endl;
				}
				if (b%2==0)
				{
					cout << "The second number is even" << endl; 
				}
				else 
				{
					cout << "The second number is odd" << endl;
				}
				if (a%5==0)
				{
					cout << "The first number is a multiple of 5" << endl; 
				}
				else 
				{
					cout << "The first number is a not multiple of 5" << endl;
				}
				if (b%5==0)
				{
					cout << "The second number is a multiple of 5" << endl; 
				}
				else 
				{
					cout << "The second number is a not multiple of 5" << endl;
				}
				if (a%7==0)
				{
					cout << "The first number is a multiple of 7" << endl; 
				}
				else 
				{
					cout << "The first number is a not multiple of 7" << endl;
				}
				if (b%7==0)
				{
					cout << "The second number is a multiple of 7" << endl; 
				}
				else 
				{
					cout << "The second number is a not multiple of 7" << endl;
				}
				if (a>b)
				{
					cout << "First number more" << endl;
				}
				else 
				{
					cout << "Second number more" << endl;
				}
			}
			else 
			{
				if (a<-100)
				{
					cout << "First number less -100" << endl;
				}
				else
				{
					cout << "First number more -100" << endl;
				}
				if (b<-100)
				{
					cout << "Second number less -100" << endl;
				}
				else
				{
					cout << "Second number more -100" << endl;
				}
				if (a<-17 && a>-130)
				{
					cout << "First number less -17 and more -130" << endl;
				}
				else
				{
					cout << "First number more -17 or less -130" << endl;
				}
				if (b<-17 && b>-130)
				{
					cout << "Second number less -17 and more -130" << endl;
				}
				else
				{
					cout << "Second number more -17 or less -130" << endl;
				}
				if (a*b>1500)
				{
					if (a<-17 && a>-130)
				{
					cout << "First number less -17 and more -130" << endl;
				}
				else
				{
					cout << "the product of two numbers is greater 1500" << endl;
				}
				}
			}
  
}
