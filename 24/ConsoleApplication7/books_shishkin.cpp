#include "stdafx.h"
#include "books_shishkin.h"


books_shishkin::books_shishkin()
{

}

books_shishkin::~books_shishkin()
{
}

void books_shishkin::input(books_shishkin* book)
{
	cout << "Enter the book name : ";
	cin >> book->name;
	cout <<"Enter the author of book : ";
	cin >> book->author;
	cout << "Enter the genre of book : ";
	cin >> book->genre;
	book->pages = prov(1,100000, "Enter the numbers of pages of book : ");
	book->publishing = prov(-10000, 2018, "Enter the year of publishing of book : ");
	cout << endl;
}

void books_shishkin::output(books_shishkin* book)
{
	cout << "name:  " <<book->name <<endl <<"author:  "<<book->author <<endl <<"genre:  "<<book->genre <<endl <<"number of pages:  " <<book->pages <<endl <<"year of publising:  " <<book->publishing <<endl << endl;
}

books_shishkin* books_shishkin::file_input(ifstream& fin)
{
	books_shishkin* book;
	book = new books_shishkin;
	fin >> book->name >> book->author >> book->genre >> book->pages >> book->publishing;
	return book;
}

void books_shishkin::file_output(ofstream& fout, books_shishkin* book)
{
	fout << endl << book->name << endl << book->author << endl<< book->genre << endl << book->pages << endl << book->publishing;
}


