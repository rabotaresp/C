#include <iostream>
#include <fstream>
#include <cstring>

struct reader
{
	int Id_r;
	char Name_r[20];
	char Book_r[2][25];
	char Hist_book[100][25];
	int Flag_r;
}; 

void reader_book_rw()
{
	int count;
	std::fstream count_r ("count.txt"); 										// создай переменную для работы с файлом, открой файл
	if (count_r)																//если файл есть и не пустой
	{
		count_r >> count; 														//запомни в переменную значение из файла
		count_r.close(); 														// закрой переменную и файл
		reader arr_r[count]; 													// создай массив, размера как указано в файле
		std::fstream read_book ("Reader.bin"); 									//создай переменную для работы с файлом
		if (read_book)															// если файл не пустой
		{
			for (int i = 0; read_book; i++) 									// читай пока файл не закончится
			{
				read_book.read(reinterpret_cast<char*>(&arr_r),sizeof(arr_r));	// запомни в массив все, что прочитал
			}
			read_book.open("Reader.bin", std::ios::trunc); 						//очисти файл
			read_book.close();													// закрой переменную и файл
			arr_r[count-1].Id_r = count;
			std::cout << "input Name reader: ";
			std::cin.getline(arr_r[count-1].Name_r, 20);
			for (int j=0; j<2; j ++)
			{
				std::cout << "input Name Book: ";
				std::cin.getline(arr_r[count-1].Book_r[j], 25);
			}
			arr_r[count-1].Flag_r = 1;
			count++;
			std::ofstream count_r ("count.txt");
			count_r << count;
			count_r.close();
			std::ofstream read_book ("Reader.bin");
			read_book.write(reinterpret_cast<char*>(&arr_r),sizeof(arr_r));
			read_book.close();
		}
	}
	else 																		// если файла нет
	{	
		std::ofstream count_r ("count.txt");
		count = 1;
		count_r << count;
		count_r.close();
		reader arr_r[1]; 
			arr_r[0].Id_r = count;
			std::cout << "input Name reader: ";
			std::cin.getline(arr_r[0].Name_r, 20);
			for (int j=0; j<2; j ++)
			{
				std::cout << "input Name Book: ";
				std::cin.getline(arr_r[0].Book_r[j], 25);
			}
			arr_r[0].Flag_r = 1;
		count++;
		std::ofstream count_rw ("count.txt");
		count_rw << count;
		count_rw.close();
		std::ofstream read_book ("Reader.bin");
		read_book.write(reinterpret_cast<char*>(&arr_r),sizeof(arr_r));
		read_book.close();
	}	
}
void reader_book_r()
{	
	int count;
	int choice;
	std::cout << "Full listing reader, imput value 1: " << std::endl;
	std::cout << "Selecyive listing reader, imput value 2: " << std::endl;
	std::cin >> choice;
	std::fstream count_r ("count.txt");
	count_r >> count;
	count_r.close();
	reader arr_r[count-1];
	std::fstream read_book ("Reader.bin");
	if (read_book)
	{
		if (choice ==1)
		{
			for (int i = 0; read_book; i++)
			{
				read_book.read(reinterpret_cast<char*>(&arr_r),sizeof(arr_r));
			}
			read_book.close();
			for (int i = 0; i < count-1; i++)
			{
				if (arr_r[i].Flag_r == 1)
				{
					std::cout << arr_r[i].Id_r << ' ' << arr_r[i].Name_r << std::endl;
					for (int j = 0; j<2; j++)
					{
						std::cout << "#"<< j+1 << ':' << arr_r[i].Book_r[j] << ' ';
					}
					std::cout << std::endl;
				}
			}
		}
		if (choice ==2)
		{
			int numb_r;
			std::cout << "Input numb reader: ";
			std::cin >> numb_r;
			for (int i = 0; read_book; i++)
			{
				read_book.read(reinterpret_cast<char*>(&arr_r),sizeof(arr_r));
			}
			read_book.close();
			if (arr_r[numb_r-1].Flag_r == 1)
			{
				std::cout << arr_r[numb_r-1].Id_r << ' ' << arr_r[numb_r-1].Name_r << std::endl;
				for (int j = 0; j<2; j++)
				{
					std::cout << "#"<< j+1 << ':'  << arr_r[numb_r-1].Book_r[j] << ' ';
				}
				std::cout << std::endl;
			}
			else
			{
				std::cout << "Reader not found. Maybe removed.";
			}
		}
	}
	else
	{
		std::cout << "File readers is Empty" << std::endl;
	}
}

void reader_removed()
{	
	int count;
	int choice_rem;
	std::fstream count_r ("count.txt");
	count_r >> count;
	count_r.close();
	reader arr_r[count-1];
	std::fstream read_book ("Reader.bin");
	if (read_book)
	{
		for (int i = 0; read_book; i++)
		{
			read_book.read(reinterpret_cast<char*>(&arr_r),sizeof(arr_r));
		}
		read_book.close();
		for (int i = 0; i < count-1; i++)
		{
			if (arr_r[i].Flag_r == 1)
			{
				std::cout << arr_r[i].Id_r << ' ' << arr_r[i].Name_r << std::endl;
				for (int j = 0; j<2; j++)
				{
					std::cout << arr_r[i].Book_r[j] << ' ';
				}
				std::cout << std::endl;
			}
		}
		std::cout << "Imput numb reader for removed: " << std::endl;
		std::cin >> choice_rem;
		arr_r[choice_rem-1].Flag_r = 0;
		std::ofstream read_book ("Reader.bin");
		read_book.write(reinterpret_cast<char*>(&arr_r),sizeof(arr_r));
		read_book.close();
	}	
}

void rw_read()
{
	int count;
	int choice_b;
	int numb_r;
	std::fstream count_r ("count.txt");
	count_r >> count;													
	count_r.close(); 
	reader arr[count];
	std::fstream read_book ("Reader.bin");
	for (int i = 0; read_book; i++)
	{
		read_book.read(reinterpret_cast<char*>(&arr),sizeof(arr));
	}
	read_book.open("Reader.bin", std::ios::trunc);
	read_book.close();
	std::cout << "Imput numb reader for view: ";
	std::cin >> numb_r;
	if (arr[numb_r-1].Flag_r == 1)
		{
			std::cout << arr[numb_r-1].Id_r << ' ' << arr[numb_r-1].Name_r << std::endl;
			for (int j = 0; j<2; j++)
			{
				std::cout << "#"<< j+1 << ':' << arr[numb_r-1].Book_r[j] << ' ';
			}
			std::cout << std::endl;
		}
	else
		{
			std::cout << "Reader not found. Maybe removed.";
		}
	std::cout <<"Which book to replace, enter the book number: ";
	std::cin >> choice_b;
	std::cout << "input Name Book: ";
	std::cin.ignore();
	std::cin.getline(arr[numb_r-1].Book_r[choice_b-1], 25);	
	std::ofstream read_book_rw ("Reader.bin");
	read_book_rw.write(reinterpret_cast<char*>(&arr),sizeof(arr));
	read_book_rw.close();
}

/*void answer ()
{
	int answer = 0;
	do
	{
	std::cout << "Choice value" << std::endl;
	std::cout << "Add a book, input 1: " << std::endl;
	std::cout << "Add reader, input 2: " << std::endl;
	std::cout << "Removed a book, input 3: " << std::endl;
	std::cout << "Removed reader, input 4: " << std::endl;
	std::cout << "History reader, input 5: " << std::endl;
	std::cout << "For EXIT input 0: " << std::endl;
	std::cin >> answer;
		switch (answer)
		{
			//case 1: Add_a_Book (); break;
			case 2: reader_book_rw(); break;
			//case 3: Remove_book (); break;
			//case 4: reader_removed(); break;
			//case 5: reader_book_r(); break;
			case 0: break;
			default: std::cout << "Not correct value!" << std::endl;
						answer = 9;
		}
	}
		while(answer == 9);
}	*/

int main ()
{
	
	//reader_book_rw();
	reader_book_r();
	//reader_removed();
	//rw_read();
}

