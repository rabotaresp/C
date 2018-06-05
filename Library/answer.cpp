#include <iostream>
#include <fstream>
void answer ();
void Add_a_Book ()
{
	int choice;
	char book_val[80];
	std::fstream count_Book ("count.txt");
	int count_temp;
	count_Book >> count_temp;
	count_Book.close();
	int count = count_temp;
	do
		{
			std::cout << "Input a book: ";
			std::cin >> book_val;
			std::ofstream Add_Book ("book.txt", std::ofstream::app);
			Add_Book << count << ' ' << book_val << "\n";
			std::cout << "Yet again input a book? If YES input - 1. If NO input - 0. ";
			std::cin >> choice;
			Add_Book.close();
			count ++;
			std::ofstream count_Book ("count.txt");
			count_Book << count;
			count_Book.close();
		}
	while (choice !=0);
}

void Add_reader()
{
	std::cout << "Add reader, input 2: " << std::endl;
}

void History_reader ()
{
	std::cout << "History reader, input 3: " << std::endl;
}

void answer ()
{
	int answer = 0;
	std::cout << "Choice value" << std::endl;
	std::cout << "Add a book, input 1: " << std::endl;
	std::cout << "Add reader, input 2: " << std::endl;
	std::cout << "History reader, input 3: " << std::endl;
	std::cin >> answer;
	switch (answer)
	{
		case 1: Add_a_Book (); break;
		case 2: Add_reader(); break;
		case 3: History_reader (); break;
		default: std::cout << "Not correct value!";
	}
}

int main ()
{
	answer ();	
}
