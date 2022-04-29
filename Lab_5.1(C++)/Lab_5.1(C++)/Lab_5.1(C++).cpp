#include <iostream>
#include <fstream>
#include <Windows.h>              // забезпечення відображення кирилиці

using namespace std;

void CreateBIN(const char* filename);
void PrintBIN(const char* filename);
int ProcessBIN(const char* filename, const char* newfile);

int main()
{                             // забезпечення відображення кирилиці:
	SetConsoleCP(1251);       // встановлення сторінки win-cp1251 в потік вводу
	SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу

	CreateBIN("file.dat");
	PrintBIN("file.dat");
	ProcessBIN("file.dat", "newfile.dat");
	PrintBIN("newfile.dat");
	return 0;
}

void CreateBIN(const char* filename)
{
	char ch;
	ofstream f(filename, ios::binary);

	int x;
	do {
		cout << "Введіть числа: ";
		cin >> x;
		cout << endl;
		f.write((char*)&x, sizeof(x)); // записали у файл
		cout << "Додати ще? (y/n): ";
		cin >> ch;
		cout << endl;
	}

	while (ch == 'y' || ch == 'Y');
	cout << endl;
	f.close();
}

void PrintBIN(const char* filename)
{
	cout << endl << "\nfile \"" << filename << "\":\n";
	ifstream f(filename, ios::binary);

	int x;
	while (f.read((char*)&x, sizeof(x)))
		cout << x << endl;
	cout << endl;
}

int ProcessBIN(const char* filename, const char* newfile)
{
	ifstream f(filename, ios::binary);
	ofstream g(newfile, ios::binary);

	int x;
	int y = 0;
	while (f.read((char*)&x, sizeof(x)))
	{
		if (x < 0)
		{
			y += x;
			g.write((char*)&y, sizeof(y));
		}
	}
	return y;
}