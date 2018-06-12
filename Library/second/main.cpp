#include <iostream>
#include <fstream>
#include <cstring>
void answer ();
struct book{
	int Id_b = 0;
	char Name_b[25] = {};
	int Flag_b = 0;
}; 
struct reader{
	int Id_r;
	char Name_r[20];
	book library[3];
	char Hist_book[100][25] = {};
	int Flag_r;
}; 
void return_book_lib (){
		int count_b;
		std::fstream count_r_b ("count_b.txt");
		count_r_b >> count_b;
		count_r_b.close();
		book arr_b[count_b-1];
		int count;
		std::fstream count_r ("count.txt");
		count_r >> count;
		count_r.close();
		reader arr_r[count-1];
		std::fstream book_r ("Book.bin"); // открываем файл с книгами
		if (book_r)
		{	
			for (int i = 0; book_r; i++)
			{
				book_r.read(reinterpret_cast<char*>(&arr_b),sizeof(arr_b));
			}
			book_r.close();
		}
		int numb_r; 		//выбор номера читателя
		int numb_b; 		//выбор номера книги которую выдать чителю
		std::fstream read_book ("Reader.bin"); //нужно, чтобы перезаписать файл с читателями
		for (int i = 0; read_book; i++)
		{
			read_book.read(reinterpret_cast<char*>(&arr_r),sizeof(arr_r));
		}
		read_book.open("Reader.bin", std::ios::trunc); 	// очистил файл
		read_book.close();
		std::cout << "Readers:" << std::endl;
		for (int i = 0; i < count-1; i++)
		{
			if (arr_r[i].Flag_r == 1)
			{
				std::cout << arr_r[i].Id_r << ' ' << arr_r[i].Name_r << std::endl;
			}
		}
		std::cout << "Input number reader: ";
		std::cin >> numb_r;
		std::cout << arr_r[numb_r-1].Id_r << ' ' << arr_r[numb_r-1].Name_r << std::endl;
		for (int j = 0; j<3; j++)
		if (arr_r[numb_r-1].library[j].Flag_b == 1)
		{
			{
				std::cout << "Id_Book: "<< arr_r[numb_r-1].library[j].Id_b << ':' << arr_r[numb_r-1].library[j].Name_b << std::endl;
			}
		}
		read_book.open("Reader.bin", std::ios::trunc); 	// очистил файл
		read_book.close();
		if (arr_r[numb_r-1].Flag_r == 1 && arr_r[numb_r-1].library[0].Flag_b == 1 || arr_r[numb_r-1].library[1].Flag_b == 1 || arr_r[numb_r-1].library[2].Flag_b == 1) 		// если пользователь есть, открой его и верни книгу в библиотеку
		{
			std::cout << "input Id_Book for return: ";
			std::cin >> numb_b;
			for (int i = 0; i < 3; i++)
			{
				if (arr_r[numb_r-1].library[i].Id_b == numb_b)
				{
					arr_r[numb_r-1].library[i].Id_b = 0;
					arr_r[numb_r-1].library[i].Flag_b = 0; 	// зудаляет книгу из ячейки читателя
					arr_b[numb_b-1].Flag_b = 1;
					//std::cerr << "Break\n";
					break;
				}
				if (arr_r[numb_r-1].library[i+1].Id_b == numb_b)
				{
					arr_r[numb_r-1].library[i+1].Id_b = 0;
					arr_r[numb_r-1].library[i+1].Flag_b = 0; 	// зудаляет книгу из ячейки читателя
					arr_b[numb_b-1].Flag_b = 1;
					//std::cerr << "Break\n";
					break;
				}
				if (arr_r[numb_r-1].library[i+2].Id_b == numb_b)
				{
					arr_r[numb_r-1].library[i+2].Id_b = 0;
					arr_r[numb_r-1].library[i+2].Flag_b = 0; 	// зудаляет книгу из ячейки читателя
					arr_b[numb_b-1].Flag_b = 1;
					//std::cerr << "Break\n";
					break;
				}
				else
				{
					 std::cout << "Not a Book for read";
					break;
				} 
			}
		}
		else 
		{
			std::cout << "Reader not a Book for read";
		}
		std::ofstream book_add_read ("Reader.bin");
		book_add_read.write(reinterpret_cast<char*>(&arr_r),sizeof(arr_r));
		book_add_read.close();
		std::ofstream flag_book ("Book.bin");
		flag_book.write(reinterpret_cast<char*>(&arr_b),sizeof(arr_b));
		flag_book.close();
}
void add_book_read (){
		int count_b;
		std::fstream count_r_b ("count_b.txt");
		count_r_b >> count_b;
		count_r_b.close();
		book arr_b[count_b-1];
		int count;
		std::fstream count_r ("count.txt");
		count_r >> count;
		count_r.close();
		reader arr_r[count-1];
		std::fstream book_r ("Book.bin"); // открываем файл с книгами
		if (book_r)
		{	
			for (int i = 0; book_r; i++)
			{
				book_r.read(reinterpret_cast<char*>(&arr_b),sizeof(arr_b));
			}
			book_r.close();
			std::cout << "Books:" << std::endl;
			for (int i = 0; i < count_b-1; i++)
			{
				if (arr_b[i].Flag_b == 1)
				{
					std::cout << arr_b[i].Id_b << ' ' << arr_b[i].Name_b << std::endl;
				}
			}
		}
		int numb_r; 		//выбор номера читателя
		int numb_b; 		//выбор номера книги которую выдать чителю
		std::fstream read_book ("Reader.bin"); //нужно, чтобы перезаписать файл с читателями
		for (int i = 0; read_book; i++)
		{
			read_book.read(reinterpret_cast<char*>(&arr_r),sizeof(arr_r));
		}	
		read_book.open("Reader.bin", std::ios::trunc); 	// очистил файл
		read_book.close();
		std::cout << "Readers:" << std::endl;
		for (int i = 0; i < count-1; i++)
		{
			if (arr_r[i].Flag_r == 1)
			{
				std::cout << arr_r[i].Id_r << ' ' << arr_r[i].Name_r << std::endl;
			}
		}
		std::cout << "Input number reader: ";
		std::cin >> numb_r;
		if (arr_r[numb_r-1].Flag_r == 1) 		// если пользователь есть, открой его и запиши ему книгу
		{
			std::cout << "input number Book: ";
			std::cin >> numb_b;
			for (int i = 0; i < 3; i++)
			{
				if (arr_r[numb_r-1].library[i].Flag_b == 0)
				{
					arr_r[numb_r-1].library[i] = arr_b[numb_b-1]; 	// записали книгу в 1 ячейку читателя
					arr_b[numb_b-1].Flag_b = 0;
					//std::cerr << "Break\n";
					break;
				}
				if (arr_r[numb_r-1].library[i+1].Flag_b == 0)
				{
					arr_r[numb_r-1].library[i+1] = arr_b[numb_b-1]; 	// записали книгу в 1 ячейку читателя
					arr_b[numb_b-1].Flag_b = 0;
					//std::cerr << "Break\n";
					break;
				}
				if (arr_r[numb_r-1].library[i+2].Flag_b == 0)
				{
					arr_r[numb_r-1].library[i+2] = arr_b[numb_b-1]; 	// записали книгу в 1 ячейку читателя
					arr_b[numb_b-1].Flag_b = 0;
					//std::cerr << "Break\n";
					break;
				}
				else
				{
					 std::cout << "Return book";
					break;
				} 
			}
		}
		else 
		{
			std::cout << "Reader not found. Maybe removed.";
		}
		std::ofstream book_add_read ("Reader.bin");
		book_add_read.write(reinterpret_cast<char*>(&arr_r),sizeof(arr_r));
		book_add_read.close();
		std::ofstream flag_book ("Book.bin");
		flag_book.write(reinterpret_cast<char*>(&arr_b),sizeof(arr_b));
		flag_book.close();	
}
void reader_book_rw(){
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
void reader_book_r(){	
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
		if (choice == 1)
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
				}
			}
		}
		if (choice ==2)
		{
			int numb_r;
			std::cout << "Input number reader: ";
			std::cin >> numb_r;
			for (int i = 0; read_book; i++)
			{
				read_book.read(reinterpret_cast<char*>(&arr_r),sizeof(arr_r));
			}
			read_book.close();
			if (arr_r[numb_r-1].Flag_r == 1)
			{
				std::cout << arr_r[numb_r-1].Id_r << ' ' << arr_r[numb_r-1].Name_r << std::endl;
				for (int j = 0; j<3; j++)
				if (arr_r[numb_r-1].library[j].Flag_b == 1)
				{
					{
						std::cout << "Id_Book: "<< arr_r[numb_r-1].library[j].Id_b << ':' << arr_r[numb_r-1].library[j].Name_b << std::endl;
					}
					std::cout << std::endl;
				}
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
void reader_removed(){	
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
				for (int j = 0; j<3; j++)
					{
						std::cout << "#"<< j+1 << ':' << arr_r[i].library[j].Name_b << ' ' << "ID_Book: " << arr_r[i].library[j].Id_b << std::endl;
					}
					std::cout << std::endl;
			}
		}
		std::cout << "Imput number reader for removed: " << std::endl;
		std::cin >> choice_rem;
		arr_r[choice_rem-1].Flag_r = 0;
		std::ofstream read_book ("Reader.bin");
		read_book.write(reinterpret_cast<char*>(&arr_r),sizeof(arr_r));
		read_book.close();
	}
}
void book_rw(){
	int count_b;
	std::fstream count_r_b ("count_b.txt"); 										// создай переменную для работы с файлом, открой файл
	if (count_r_b)																	//если файл есть и не пустой
	{
		count_r_b >> count_b; 														//запомни в переменную значение из файла
		count_r_b.close(); 															// закрой переменную и файл
		book arr_b[count_b]; 														// создай массив, размера как указано в файле
		std::fstream book_r ("Book.bin"); 											//создай переменную для работы с файлом
		if (book_r)																// если файл не пустой
		{
			for (int i = 0; book_r; i++) 											// читай пока файл не закончится
			{
				book_r.read(reinterpret_cast<char*>(&arr_b),sizeof(arr_b));		// запомни в массив все, что прочитал
			}
			book_r.open("Book.bin", std::ios::trunc); 								//очисти файл
			book_r.close();														// закрой переменную и файл
			arr_b[count_b-1].Id_b = count_b;
			std::cout << "input Name a Book: ";
			std::cin.getline(arr_b[count_b-1].Name_b, 25);
			arr_b[count_b-1].Flag_b = 1;
			count_b++;
			std::ofstream count_r_b ("count_b.txt");
			count_r_b << count_b;
			count_r_b.close();
			std::ofstream book_r ("Book.bin");
			book_r.write(reinterpret_cast<char*>(&arr_b),sizeof(arr_b));
			book_r.close();
		}
	}
	else 																			// если файла нет
	{	
		std::ofstream count_r_b ("count_b.txt");
		count_b = 1;
		count_r_b << count_b;
		count_r_b.close();
		book arr_b[1]; 
		arr_b[0].Id_b = count_b;
		std::cout << "input Name a Book: ";
		std::cin.getline(arr_b[0].Name_b, 25);
		arr_b[0].Flag_b = 1;
		count_b++;
		std::ofstream count_rw ("count_b.txt");
		count_rw << count_b;
		count_rw.close();
		std::ofstream book_r ("Book.bin");
		book_r.write(reinterpret_cast<char*>(&arr_b),sizeof(arr_b));
		book_r.close();
	}
}
void book_r(){	
	int count_b;
	std::fstream count_r_b ("count_b.txt");
	count_r_b >> count_b;
	count_r_b.close();
	book arr_b[count_b-1];
	std::fstream book_r ("Book.bin");
	if (book_r)
	{	
		for (int i = 0; book_r; i++)
		{
			book_r.read(reinterpret_cast<char*>(&arr_b),sizeof(arr_b));
		}
		book_r.close();
		for (int i = 0; i < count_b-1; i++)
		{
			if (arr_b[i].Flag_b == 1)
			{
				std::cout << "Id_Book: "<< arr_b[i].Id_b << ' ' << arr_b[i].Name_b << std::endl;
			}
		}
	}
	else
	{
		std::cout << "File book is Empty" << std::endl;
	}
}
void answer (){
	int answer = 0;
	std::cout << "Choice value" << std::endl;
	std::cout << "Add a book, input 1: " << std::endl;
	std::cout << "Full listing a book, input 2: " << std::endl;
	std::cout << "Add reader, input 3: " << std::endl;
	std::cout << "Full listing reader, input 4: " << std::endl;
	std::cout << "Add a book reader, input 5: " << std::endl;
	std::cout << "Return a book in library, input 6: " << std::endl;
	std::cout << "Removed reader, input 7: " << std::endl;
	//std::cout << "History reader, input 5: " << std::endl;
	std::cout << "For EXIT input 0: " << std::endl;
	std::cin >> answer;
	switch (answer)
		{
			case 1: book_rw(); break;
			case 2: book_r(); break;
			case 3: reader_book_rw(); break;
			case 4: reader_book_r(); break;
			case 5: add_book_read(); break;
			case 6: return_book_lib (); break;
			case 7: reader_removed(); break;
			case 0: break;
			default: std::cout << "Not correct value!" << std::endl;
		}
}
int main ()
{
	//answer ();
	//book_rw(); 
	//book_r(); 
	//reader_book_rw(); 
	//reader_book_r(); 
	//add_book_read(); 
	//return_book_lib (); 
	//reader_removed(); 
}
