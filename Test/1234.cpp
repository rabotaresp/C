#include <iostream>
using namespace std;

struct ArrMax
{
	int a, b;
	public:
			int NumIn (int num)
			{
				if (num > 0)
				{   
					int arr[num];
						for (int i=0; i<num; i++)
						{
							cout << "Imput num in arr - ";
							cin >> b;
							arr[i] = b;
						}
						
							int temp;

								 // Сортировка массива от меньшего к большему
								for (int i = 0; i < num - 1; i++) 
								{
									for (int j = 0; j < num - i - 1; j++) 
									{
										if (arr[j] > arr[j + 1]) 
										{
								// меняем элементы местами
										temp = arr[j];
										arr[j] = arr[j + 1];
										arr[j + 1] = temp;
										}
									}
								}
								// Вывод отсортированного массива на экран
											for (int i = 0; i < num; i++) 
											{
												return arr[i];
											}
											cout << endl;
							
											}
			}
	
};
struct ArrMin
{
	int a, b;
	public:
			int NumIn (int num)
			{
				if (num > 0)
				{   
					int arr[num];
						for (int i=0; i<num; i++)
						{
							cout << "Imput num in arr - ";
							cin >> b;
							arr[i] = b;
						}
						
							int temp;

								 // Сортировка массива от меньшего к большему
								for (int i = 0; i < num - 1; i++) 
								{
									for (int j = 0; j < num - i - 1; j++) 
									{
										if (arr[j] < arr[j + 1]) 
										{
								// меняем элементы местами
										temp = arr[j];
										arr[j] = arr[j + 1];
										arr[j + 1] = temp;
										}
									}
								}
								// Вывод отсортированного массива на экран
											for (int i = 0; i < num; i++) 
											{
												return arr[i] ;
											}
											cout << endl;
							
											}
			}
		
};
int funVar (int a)
{
	if (a !=0)
	{
	cout << "If you want to sort the numbers in ascending order, type -1- " << endl;
	cout << "If you want to sort the numbers in descending order, enter -2- " << endl;
	} 
	else
	{
	cout <<"Not true, the number must be greater than 0" << endl;
}
}
int main () 
{
	int a;
	int b;
	ArrMax max;
	ArrMin min;
	cout << "How many digits do you want to enter? - ";
	cin >> a;
	min.a = a;
	max.a = a;
	funVar(a);
	cin >> b;
	if (b > 2) cout << "Numb not correct!";
	if (b == 1) cout << max.NumIn (max.a) << " ";
	if (b == 2) cout << min.NumIn (min.a) << " ";
	
	
	
}
