// 24.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <fstream> 
#include <string> 

int size(ifstream& in)
{
	in.seekg(0, in.end);
	int length = in.tellg();
	in.seekg(0, in.beg);
	return length;
}

int main(int argc, const char *argv[])
{
	string in, out, k;
	int cod = 0;
	for (int i = 1; i < argc; i++)
	{
		if (!strcmp(argv[i], "-c")) cod = stoi(argv[i + 1]);
		if (!strcmp(argv[i], "-i")) in = argv[i + 1];
		if (!strcmp(argv[i], "-o")) out = argv[i + 1];
		if (!strcmp(argv[i], "-k")) k = argv[i + 1];
	}
	ifstream fin(in, std::ifstream::binary);
	ifstream keys(k, std::ifstream::binary);
	ofstream fout(out, std::ofstream::binary);
	if (keys.is_open()) {
		int length = size(keys);
		char * key = new char[length];
		for (int i = 0; i < length; i++)
		{
			key[i] = (char)keys.get();
		}
		if (fin.is_open() && fout.is_open())
		{
			int i = 0;
			int length_fin = size(fin);
			for (int j = 0; j < length_fin; j++)
			{
				if (i == length) i = 0;
				if (!cod) fout << (char)(((unsigned char)fin.get() + (unsigned char)key[i]) % 256);
				else fout << (char)(((unsigned char)fin.get() - (unsigned char)key[i]) % 256);
				i++;
			}
		}
	}
}