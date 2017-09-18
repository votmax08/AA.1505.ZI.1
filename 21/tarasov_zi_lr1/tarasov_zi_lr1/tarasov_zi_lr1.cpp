#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string key;

int main()
{
	int i = 0;
	int flag = 0;
	ofstream fout("fileOut.txt", std::ofstream::binary);
	ifstream finFlag("fileIn.txt", std::ifstream::binary);

	cin >> key;
	
	while (!finFlag.eof())
	{
		char a;
		finFlag.get(a);
		flag++;
	}
	cout << key.length();
	finFlag.close();

	ifstream fin("fileIn.txt", std::ifstream::binary);
	
	for (int k = 0; k < flag-1; k++)
	{
		char a;
		unsigned char b;

		fin.get(a);
		b = ((unsigned char)a + (unsigned char)key[i]) % 256;
		fout << b;
		i = i + 1;
		if (i == key.length()) i = 0;
	}
	fin.close();
	fout.close();

	ofstream fout1("fileTest.txt", ifstream::binary);
	ifstream fin1("fileOut.txt", ifstream::binary);

	i = 0;
	for (int k = 0; k < flag-1; k++)
	{
		char a;
		unsigned char b;

		fin1.get(a);
		b = ((unsigned char)a - (unsigned char)key[i]) % 256;
		fout1 << b;
		i = i + 1;
		if (i == key.length()) i = 0;
	}

	return 0;
}

