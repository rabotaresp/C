#include <iostream>
int func (int *a, int size)
{
	int temp = 0;
		for (int i = 0; i<13; i++)
		{
			for (int j = i+1; j<13; j++)
			{
				if (a[i] == a[j])
				{	
						for (int g = i+1; g<j; g++)
						{
							temp = temp + a[g];
						}
					return temp;
				}
			}
		}
	return 0;				
}
 int main () {
	 /*int arr[3][4] = {{1,2,3,38},{12,5,9,10},{113,6,4,7}};
	 int temp[3] = {0};
	 int max = 0;
	 int g = 0;	
		 for (int i = 0; i<3; i++)
		 {
			for (int j = 0; j<4; j++)
				{
					temp[i] = temp[i] + arr[i][j]; 
					if (max < temp[i])
					{
						max = temp[i];
						g = i;
					}
				}
		 }
	std::cout << g <<std::endl;*/
	//Task 1
	/*int s = 13; 
	int a[s] = {1,2,4,3,2,4,5,5,6,3,0,1,0};
	int n[s] = {0};
	int f = 0;
	for (int i = 0; i<13; i++)
		{
			for (int j = i+1; j<13; j++)
			{
				if (a[i] == a[j])
				{
					a[i] = -1;
					s--;
				}	
			}
			if (a[i]!= -1)
			{
				n[f] = a[i];
				f++;
			}	
		}
	for (int i = 0; i < s; i++)
	std::cout <<n[i]<<std::endl;*/
	//Task 2
	/*int a[13] = {1,2,3,1,2,4,5,5,6,3,0,1,0};
	std::cout << func(a, sizeof(a)/4);	*/	
	//Task 3
	int a[13] = {1,2,4,3,2,4,5,5,6,3,0,1,-2};
	int min = a[0];
	for (int i = 0; i<13; i++)
	{
		if (min > a[i])
		{
			min = a[i];
		}
	}	
	if (min%2==0)
	{
		std::cout << min;
	}
}
	
	 
 
