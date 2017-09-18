// L1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;



int _tmain(int argc, _TCHAR* argv[])
{

	ifstream fin;
	ofstream fout;
	string key;
	char c;
	unsigned char symbol;
	unsigned char c_symbol;
	unsigned char dec_symbol;
	int i = 0;

	cout << "Enter key for coding: ";
	cin >> key;
	fin.open("input.txt", ios::binary);
	fout.open("output.txt", ios::binary);
	if (fin.is_open())
	{
		for (;;)
		{
			fin.get(c);
			symbol = c;
			if (fin.eof())
			{
				break;
			}
			else
			{

				c_symbol = symbol + key[i];
				if (i == key.size())
					i = 0;
				else
					i++;
				fout << c_symbol;
			}
		}
	}
	fin.close();
	fout.close();

	i = 0;
	fin.open("output.txt", ios::binary);
	fout.open("test.txt", ios::binary);
	for (;;)
	{
		fin.get(c);
		symbol = c;
		if (fin.eof())
		{
			break;
		}
		else
		{

			dec_symbol = symbol - key[i];
			if (i == key.size())
				i = 0;
			else
				i++;
			fout << dec_symbol;
		}
	}

	fin.close();
	fout.close();
	return 0;

}