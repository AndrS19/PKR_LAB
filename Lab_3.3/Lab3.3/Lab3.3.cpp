#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <Windows.h>						// забезпечення відображення кирилиці

using namespace std;

struct Price
{
	string product_name;
	string store_name;
	double money;
};

void Create(Price* p, const int N);
void Print(Price* p, const int N);
void Sort(Price* p, const int N);
int Search(Price* p, const int N, const string product_name);
void SaveToFile(Price* p, const int N, const char* filename);
void LoadFromFile(Price*& p, int& N, const char* filename);

int main()
{											// забезпечення відображення кирилиці:
	SetConsoleCP(1251);						// встановлення сторінки win-cp1251 в потік вводу
	SetConsoleOutputCP(1251);				// встановлення сторінки win-cp1251 в потік виводу

	int N;
	cout << " Введіть кількість товарів: "; 
	cin >> N;

	Price* p = new Price[N];

	string product_name;
	int found;
	char filename[100];

	int menuItem;
	do {
		cout << endl;
		cout << " Виберіть дію:" << endl << endl;
		cout << " [1] - введення даних з клавіатури" << endl;
		cout << " [2] - вивід даних на екран" << endl;
		cout << " [3] - впорядкування за алфавітним порядком назв магазинів" << endl;
		cout << " [4] - пошук за назвою товару" << endl;
		cout << " [5] - запис даних у файл" << endl;
		cout << " [6] - зчитування даних із файлу" << endl << endl;
		cout << " [0] - вихід та завершення роботи програми" << endl << endl;
		cout << "Введіть значення: "; cin >> menuItem;
		cout << endl;

		switch (menuItem)
		{
		case 1:
			Create(p, N);
			break;
		case 2:
			Print(p, N);
			break;
		case 3:
			Sort(p, N);
			break;
		case 4:
			cin.get();						// очищуємо буфер клавіатури – бо залишаються символи
			cin.sync();						// "кінець рядка", які не дають ввести наступний літерний рядок
			cout << "Введіть назву товару для пошуку : "; 
			getline(cin, product_name);
			Search(p, N, product_name);
			break;
		case 5:
			cin.get();						// очищуємо буфер клавіатури – бо залишаються символи
			cin.sync();						// "кінець рядка", які не дають ввести наступний літерний рядок
			cout << " Введіть ім'я файлу: "; 
			cin.getline(filename, 99);
			SaveToFile(p, N, filename);
			break;
		case 6:
			cin.get();						// очищуємо буфер клавіатури – бо залишаються символи
			cin.sync();						// "кінець рядка", які не дають ввести наступний літерний рядок
			cout << " Введіть ім'я файлу: "; 
			cin.getline(filename, 99);
			LoadFromFile(p, N, filename);
			break;
		case 0:
			break;
		default:
			cout << " Ви ввели помилкове значення! "
				" Слід ввести число - номер вибраного пункту меню" << endl;
		}
	} while (menuItem != 0);
	return 0;
}

void Create(Price* p, const int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << " Товар № " << i + 1 << ":" << endl;
		cin.get();							// очищуємо буфер клавіатури – бо залишаються символи
		cin.sync();							// "кінець рядка", які не дають ввести наступний літерний рядок
		cout << " Назва товару: "; 
		getline(cin, p[i].product_name);
		cout << " Назва магазину: "; 
		cin >> p[i].store_name;
		cout << " Вартість товару (грн.): ";
		cin >> p[i].money;
		cout << endl;
	}
}

void Print(Price* p, const int N)
{
	cout << "========================================================================="
		<< endl;
	cout << "| № |       Товар       |   Магазин   | Вартість (грн.) |"
		<< endl;
	cout << "-------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "|" << setw(2) << right << i + 1;
		cout << " | " << setw(17) << left << p[i].product_name;
		cout << " | " << setw(12) << left << p[i].store_name;
		cout << "| " << setw(14) << right << p[i].money << "  | " << endl;
	}
	cout << "========================================================================="
		<< endl;
	cout << endl;
}

void Sort(Price* p, const int N)
{
	Price tmp;
	for (int i0 = 0; i0 < N - 1; i0++)						// метод "бульбашки"
		for (int i1 = 0; i1 < N - i0 - 1; i1++)
			if ((p[i1].store_name > p[i1 + 1].store_name))
			{
				tmp = p[i1];
				p[i1] = p[i1 + 1];
				p[i1 + 1] = tmp;
			}
}

int Search(Price* p, const int N, const string product_name)
{
	int k = 0;
	for (int i = 0; i < N; i++) 
	{ 
		if (p[i].product_name == product_name) 
		{
			cout << endl;
			cout << "========================================================================="
				<< endl;
			cout << "| № |       Товар       |   Магазин   | Вартість (грн.) |"
				<< endl;
			cout << "-------------------------------------------------------------------------"
				<< endl;

				cout << "|" << setw(2) << right << i + 1;
				cout << " | " << setw(17) << left << p[i].product_name;
				cout << " | " << setw(12) << left << p[i].store_name;
				cout << "| " << setw(14) << right << p[i].money << "  | " << endl;

			cout << "========================================================================="
				<< endl;
			cout << endl;
			k++;
		}
	}
	if (k == 0)
	{
		cout << "Такого товару в списку немає!" << endl;
	}
	return 0;
}

void SaveToFile(Price* p, const int N, const char* filename)
{
	ofstream fout(filename, ios::binary);			// відкрили бінарний файл запису
	fout.write((char*)&N, sizeof(N));				// записали кількість елементів
	for (int i = 0; i < N; i++)
		fout.write((char*)&p[i], sizeof(Price));	// записали елементи масиву
	fout.close();									// закрили файл
}

void LoadFromFile(Price*& p, int& N, const char* filename)
{
	delete[] p;										// знищили попередні дані
	ifstream fin(filename, ios::binary);			// відкрили бінарний файл зчитування
	fin.read((char*)&N, sizeof(N));					// прочитали кількість елементів
	p = new Price[N];								// створили динамічний масив
	for (int i = 0; i < N; i++)
		fin.read((char*)&p[i], sizeof(Price));		// прочитали елементи масиву
	fin.close();									// закрили файл
}