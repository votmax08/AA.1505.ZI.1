// ConsoleApplication7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "books_shishkin.h"
#include "library_shishkin.h"
int menu(books_shishkin* book)
{
	int action;
	do {
		//cout << endl << "1: Add the book?" << endl;
		//cout << "2: Delete library" << endl;
		//cout << "3: Print information of the library to file?" << endl;
		//cout << "4: Add the library from file?" << endl;
		//cout << "5: Print information of the library?" << endl;
		//cout << "0: Exit" <<endl;
		//cout << endl << "Choose menu number: ";
		action = book->prov(0,5, "Choose menu number: \n1: Add the book?\n2: Delete library\n3: Print information of the library to file?\n4: Add the library from file?\n5: Print information of the library?\n0: Exit\n");
	} while ((action < 0) || (action > 5));
	return action;
}
int main()
{ 

	int action;
	library_shishkin library;
	books_shishkin* book;
	ifstream fin;
	ofstream fout;
	book = NULL;
		do
		{
			
			action = menu(book);
			switch (action)
			{
			case 0: return 0;
			case 1: book = new books_shishkin; book->input(book); library.add_book(book); break;
			case 2: library.books.clear(); break;
			case 3: library.output_to_file(fout); break;
			case 4: library.input_from_file(fin); break;
			case 5: library.print_book(); break;
			}
		} while (action);
		
	
    //return 0;
}

