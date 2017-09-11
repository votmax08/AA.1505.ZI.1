#include "stdafx.h"
#include "library_shishkin.h"


library_shishkin::library_shishkin()
{
}


library_shishkin::~library_shishkin()
{	
	books.clear();
}

void library_shishkin::add_book(books_shishkin* book)
{
	books.push_back(book);
}

void library_shishkin::print_book()
{
	for (auto it = books.begin(); it != books.end(); ++it)
	{
		/*cout << "name:  " << (*it)->name << endl << "author:  " << (*it)->author << endl << "genre:  " << (*it)->genre << endl << "number of pages:  " << (*it)->pages << endl << "year of publising:  " << (*it)->publishing << endl << endl;*/
		(*it)->output(*it);
	}
	
}

void library_shishkin::input_from_file(ifstream& fin)
{
	fin.open("in");
	books_shishkin* book;
	if (fin.is_open())
	{
		while(!fin.eof())
		{
			book = new books_shishkin;
			books.push_back(book->file_input(fin));
		}	
	}
	fin.close();
}

void library_shishkin::output_to_file(ofstream& fout)
{
	fout.open("in");

	for (auto it = books.begin(); it != books.end(); ++it)
	{
		(*it)->file_output(fout, *it);
	}

	fout.close();
}

