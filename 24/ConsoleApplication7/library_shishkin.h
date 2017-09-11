#pragma once
#include"stdafx.h"
#include"books_shishkin.h"
class library_shishkin
{
public:
	library_shishkin();
	~library_shishkin();
	vector <books_shishkin*> books;
	void add_book(books_shishkin* book);
	void print_book(), input_from_file(ifstream& fin), output_to_file(ofstream& fout);
};

