#include <iostream>
#include <fstream>
void answer ();
struct Reader
{
	int Id_r;
	char Name_r[80];
	char book_r[3][80];
	int Flag_r;
};
struct Book
{
	int Id_b;
	char Title_b[80] = {None};
	int Flag_b;
};
void Add_a_Book ()
{
	int choice;
	char book_val[80];
	std::fstream count_Book ("count.txt");
	int count_temp;
	count_Book >> count_temp;
	count_Book.close();
	int count = count_temp;
	Book new_book[count];
	/*if (book.txt){
	Book new_book[count];
		for (int i = 0; i<count; i ++)
		{
			new_book[i].Id_b = count;
			for (int j=0; j<80; j++)
			{
				new_book[i].Title_b[j]=;
			}
		}
	}*/
	do
		{
			int Flag_b;
			for (int i = 0; i<count; i ++)
			{
				new_book[i].Flag_b = 1;
				Flag_b = new_book[i].Flag_b;
			}
			std::cout << "Input a book: ";
			std::cin >> book_val;
			std::ofstream Add_Book ("book.txt", std::ios::app);
			Add_Book << count << "\n" << book_val << "\n" << Flag_b << "\n";
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

void Remove_book()
{
	std::cout << "Remove a book, input 3: " << std::endl;
}

void Remove_reader()
{
	std::cout << "Remove reader, input 4: " << std::endl;
}

void History_reader ()
{
	std::cout << "History reader, input 5: " << std::endl;
}

void answer ()
{
	int answer = 0;
	do
	{
	std::cout << "Choice value" << std::endl;
	std::cout << "Add a book, input 1: " << std::endl;
	std::cout << "Add reader, input 2: " << std::endl;
	std::cout << "Remove a book, input 3: " << std::endl;
	std::cout << "Remove reader, input 4: " << std::endl;
	std::cout << "History reader, input 5: " << std::endl;
	std::cout << "For EXIT input 0: " << std::endl;
	std::cin >> answer;
		switch (answer)
		{
			case 1: Add_a_Book (); break;
			case 2: Add_reader(); break;
			case 3: Remove_book (); break;
			case 4: Remove_reader (); break;
			case 5: History_reader (); break;
			case 0: break;
			default: std::cout << "Not correct value!" << std::endl;
						answer = 9;
		}
	}
		while(answer == 9);
	
}

int main ()
{
	answer ();	
}
