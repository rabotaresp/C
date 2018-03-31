#include <iostream>
using namespace std;

			
int main () 
{
	int a;
	cout << "Input num - ";
	cin >> a;
	//int b;
	//cout << "Input second num - ";
	//cin >> b; 
	/*if (a < 0) 
		{
			 cout << "This number sub zero" << endl;
		 }
		 else 
		 {
			 cout << "This number morethen zero" << endl;
		 }
			if (a%2==0)
			{
			 cout << "This number even" << endl;
			}
			else 
			{
				cout << "This number odd" << endl;
			}
				if (a > 10)
				{
					cout << "This number two digit numb" << endl;
				}
				else 
				{
					cout << "This number singl valued numb" << endl;
				}
					if (a > -100 && a < 100)
					{
						cout << "This number enters the range (-100 100)" << endl;
					}
					else 
					{ 
						cout << "This num not included in the range (-100 100)" << endl;
					}
						if (a%3==0 && a%5==0)
						{
							cout << "This number is a multiple of 3 and 5" << endl;
						}
						else 
						{
							cout << "This number is not a multiple of 3 and 5" << endl;
						}
							if (a%2==0 || a%7==0)
							{
								cout << "This number is divided by 2 or 7" << endl;
							}
							else
							{
								cout << "This number is not divisible by 2 or 7" << endl;
							}
								cout << "This number " << -a <<endl;
								
									if (a > 1000)
									{
										cout << a/10 << endl;
									}
										if (a%10==3)
										{
											cout << (a+1)/2 << endl;
										}
											if (a>100)
											{
																														
												cout << ((a/100)*100)+80+a%10 << endl;
											}
				if (a>0)
				{
					if (b>0)
					{			
						cout << a+b << endl;
					}
					else 
					{
						cout << a-b << endl;
					}
				}
				else 
				{
					if (b>0)
					{
						cout << a*b << endl;
					}
					else
					{
						cout << a/b << endl;
					}
				}		
						if (a<0)
						{
							if (b>0)
							{
								cout << "Number b is even " << endl;
							}
						}
							if (a > 0 && a < 10)
								{
									if (b<a)
									{
										cout << "Number b is " << b << endl;
									}
								}
							if (a < 0 || a > 10)
								{
									if (b > 100) 
									{ 
										cout << b << endl;
									}
								}
										if (b<a)
										{
											if (b>0)
											{
												cout << b << endl;
											}
										}
										else 
										{
											if (a>0)
											{
												cout << a << endl;
											}
										}*/
										/*if (a%b==0)
										{
											if (b>0)
											{
												cout << b << endl;
											}
										}
										else 
										{
											if(a>0)
											{
												cout << a << endl;
											}
										}*/
											/*if (a!=0 && a<b)
											{
												cout << b*2 << endl;
												if (b<100 && b>10)
													{
														cout << b*3 << endl;
													}
													else 
													{
														cout << b << endl;
													}
											}
											if ( a == 0 || a > b)
											{
												return 0;
											}
												if (a >=-100 || a<=100)
												{
													if (a<0 && a%10!=1)
													{
														if (b >=-100 || b<=100)
															{
																if (b<0 && b%10!=1)
																{
																cout << b << endl;
																}
															}
													}
												}*/
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
			/*if (a>0 && b>0)
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
			}*/
	//While 1
	/*if (a>10 && b<a && b==10)
	{   
		while (b<a)
		{
			cout << b << endl;
			b++;
		}
	}
		else if(a<10 && b>a && b==10)
		{
				while (b>a)
		{
			cout << b << endl;
			b--;
		}	
	}	*/
	// while 2
		/*if (a>0)
	{   
		while (a>=0)
		{
			cout << a << endl;
			a--;
		}
	}
	else 
	{
		while (a<=0)
		{
			cout << a << endl;
			a++;
		}
	}*/
	//while 3
	/*int i = 1;
	while (i!=a)
	{
		if (a%i==0)
		{
			cout << i << endl;
		}
		i++;
	}*/
	//while 4
	/*if (a%2==0)
	{
		int i = 0;
		while (i<5)
		{
			cout << a << endl;
			i++;
		}
	}
	else
	{
		int i = 0;
		while (i<3)
		{
			cout << a << endl;
			i++;
		}
	}*/
	//while 5
	/*while(a>0)
		{
			a = a/10;
			cout << "1" << endl;
		}*/
	//while 6
	/*int b = 0;
	int c = b;
	while (a>0)
	{
		
		b ++;
			if(a%10==3)
			{
				c = b;
			}
			a = a/10;
	}
		cout << c << endl;									
	
}*/
	//while 7
	/*int b = 0;
	while (a>0)
	{
		b = a%10;
		cout << b;
		a = a/10;
	}
										
	
}*/
	//while 8
	/*int b = 2;
	int c = 0;
	while (((b*2)-a)<(a-b))
	{
		b = b*2;
		c ++;
		
	}
	c++;
		
		cout << c << endl;									
	
}*/
	//while 9
	/*int c = 0;
	while (a<=1000000)
	{
		a = a*2;
		c ++;
		
	}
	if (a==100000)
	{
		c++;
	}
	cout << c << endl;									
	cout << a << endl;
}*/
	//while 10
	int b = 1;
	int c = 0;
	while (a)
	{

			c = c + (a%10*b);
			b = b + b;
			a = a/10;
			
	}
		cout << c << endl;									
	
}

