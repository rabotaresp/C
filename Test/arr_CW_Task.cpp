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
	/*int a[15] = {1,2,4,3,2,4,5,5,6,3,0,1,-2,-17};
	int min = -1;
	for (int i = 0; i<15; i++)
	{
		if (min > a[i] && a[i]%2 == 0)
		{
			min = a[i];
		}
	}	
	std::cout << min;*/
	
	int arr[3][4] = {{1,2,2,1},{11,5,5,10},{113,6,4,7}};
	int temp[2][4] = {{0},{0}};
	int countmax =0;
	int count = 0;
	int index = 0;
	
	for (int g = 0; g < 3; g++)
	{
		  for (int i = 0; i<3; i++)
		 {	
			 for (int j = 1, b = 0; j<4; j++, b++)
			{
				if (arr[i][i] == arr[i][j])
				{
					count++;
				}
			}
		 }
	}
		 for (int i = 0; i<2; i++)
		 {
			for (int j = 0; j<4; j++)
				{
					temp[i][j] = arr[i][j]; 					
				}
		 }
		 for (int i = 0; i<2; i++)
		 {	
			 for (int j = 0; j<4; j++)
			{
				std::cout << temp[i][j] <<std::endl;
			}
		 }
}
	
	 
 
