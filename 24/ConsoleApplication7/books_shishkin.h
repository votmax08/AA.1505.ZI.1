#pragma once
#include "stdafx.h"

class books_shishkin 
{
public:
	books_shishkin();
	~books_shishkin();
	template <class T>
	T prov(T min, T max, string s = "");
	string author, name, genre;
	int pages, publishing;
	void input(books_shishkin* book), output(books_shishkin* book);
	books_shishkin * file_input(ifstream& fin);
	void file_output(ofstream& fout, books_shishkin* book);
};

template<class T>
inline T books_shishkin::prov(T min, T max, string s)
{
	T res;
	do {
		cout << s;
		cin >> res;
		cin.clear();
	} while ((cin.get() != '\n') || (res < min) || (res > max));
	
	return res;
}
