#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <Windows.h>						// забезпечення відображення кирилиці

using namespace std;

struct Price
{
	char product_name[64];
	char store_name[64];
	double money;
};

void CreateBIN(const char* filename);
void PrintBIN(const char* filename);
void fWrite(fstream& f, const int i, Price x);
Price fRead(fstream& f, const int i);
void fChange(fstream& f, const int i, const int j);
void SortBIN(const char* filename);
int SearchBIN(const char* filename, const char* product_name);

int main()
{											// забезпечення відображення кирилиці:
	SetConsoleCP(1251);						// встановлення сторінки win-cp1251 в потік вводу
	SetConsoleOutputCP(1251);				// встановлення сторінки win-cp1251 в потік виводу

	char filename[100] = "";
	char product_name[64];
	int found;
	int menuItem;

	do {
		cout << endl;
		cout << " Виберіть дію:" << endl << endl;
		cout << " [1] - введення даних з клавіатури" << endl;
		cout << " [2] - вивід даних на екран" << endl;
		cout << " [3] - впорядкування за алфавітним порядком назв магазинів" << endl;
		cout << " [4] - пошук за назвою товару" << endl;
		cout << " [0] - вихід та завершення роботи програми" << endl << endl;
		cout << "Введіть значення: "; cin >> menuItem;
		cout << endl;

		switch (menuItem)
		{
		case 1:
			if (strcmp(filename, "") == 0) {
				cout << "Введіть ім'я файлу: ";
				cin >> filename;
			}
			CreateBIN(filename);
			break;
		case 2:
			if (strcmp(filename, "") == 0) {
				cout << "Файл не існує, спочатку створіть файл (пункт 1)." << endl;
				break;
			}
			PrintBIN(filename);
			break;
		case 3:
			if (strcmp(filename, "") == 0) {
				cout << "Файл не існує, спочатку створіть файл (пункт 1)." << endl;
				break;
			}
			SortBIN(filename);
			PrintBIN(filename);
			break;
		case 4:
			if (strcmp(filename, "") == 0) {
				cout << "Файл не існує, спочатку створіть файл (пункт 1)." << endl;
				break;
			}
			cin.get();			// очищуємо буфер клавіатури – бо залишаються символи
			cin.sync();			// "кінець рядка", які не дають ввести наступний літерний рядок
			cout << "Введіть назву товару для пошуку : ";
			cin >> product_name;
			SearchBIN(filename, product_name);
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

void CreateBIN(const char* filename)
{
	ofstream f(filename, ios::binary); // відкрили файл для запису
	char ch; // відповідь користувача – чи продовжувати введення
	int n = 1;
	Price price;

	do {
		cout << " Товар № " << n << ":" << endl;
		cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
		cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок
		cout << " Назва товару: ";
		cin >> price.product_name;
		cout << " Назва магазину: ";
		cin >> price.store_name;
		cout << " Вартість товару (грн.): ";
		cin >> price.money;
		cout << endl;
		f.write((char*)&price, sizeof(Price)); // записали у файл
		n++;
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
	ifstream f(filename, ios::binary); // відкрили файл для зчитування
	if (!f) {
		cout << "PrintBIN: Помилка відкриття файлу." << endl;
		return;
	}

	cout << "========================================================="<< endl;
	cout << "| № |       Товар       |   Магазин   | Вартість (грн.) |"<< endl;
	cout << "---------------------------------------------------------"<< endl;

	Price price;
	int i = 1;

	while (f.read((char*)&price, sizeof(Price)))
	{
		cout << "|" << setw(2) << right << i;
		cout << " | " << setw(17) << left << price.product_name;
		cout << " | " << setw(12) << left << price.store_name;
		cout << "| " << setw(14) << right << price.money << "  | " << endl;
		i++;
	}
	cout << "========================================================="<< endl;
	cout << endl;
}

void fWrite(fstream& f, const int i, Price x)
{
	f.seekp(i * (long)sizeof(Price));   // встановили вказівник
	f.write((char*)&x, sizeof(Price));  // записали значення
}

Price fRead(fstream& f, const int i)
{
	Price x;
	f.seekg(i * (long)sizeof(Price));   // встановили вказівник
	f.read((char*)&x, sizeof(Price));   // прочитали значення
	return x;
}

void fChange(fstream& f, const int i, const int j)
{
	Price x = fRead(f, i);
	Price y = fRead(f, j);
	fWrite(f, i, y);
	fWrite(f, j, x);
}

void SortBIN(const char* filename)
{
	//сортування файлу – за допомогою прямого доступу до файлу
	fstream f(filename, ios::binary | ios::in | ios::out);
	f.seekg(0, ios::end);
	int size = f.tellg() / sizeof(Price);
	f.seekg(0, ios::beg);

	for (int i0 = 1; i0 < size; i0++) {
		for (int i1 = 0; i1 < size - i0; i1++)
		{
			Price a = fRead(f, i1);
			Price b = fRead(f, i1 + 1);
			if (strcmp(a.store_name, b.store_name) == 1)
			{
				fChange(f, i1, i1 + 1);
			}
		}
	}

	f.seekp(0, ios::end);
}

int SearchBIN(const char* filename, const char* product_name)
{
	ifstream f(filename, ios::binary);
	if (!f) {
		cout << "SearchBIN: Помилка відкриття файлу. " << filename << endl;
		return -1;
	}

	Price price;
	int i = 1;

	cout << endl;
	cout << "=========================================================================" << endl;
	cout << "| № |       Товар       |   Магазин   | Вартість (грн.) |" << endl;
	cout << "-------------------------------------------------------------------------" << endl;

	while (f.read((char*)&price, sizeof(Price)))
	{
		if (strcmp(price.product_name, product_name) == 0)
		{
			cout << "|" << setw(2) << right << i++;
			cout << " | " << setw(17) << left << price.product_name;
			cout << " | " << setw(12) << left << price.store_name;
			cout << "| " << setw(14) << right << price.money << "  | " << endl;

			cout << "========================================================================="<< endl;
			cout << endl;
		}
	}

	if (i == 1) {
		cout << endl;
		cout << "Такого товару в списку немає!" << endl << endl;
		return -1;
	}
	else {
		return 1;
	}
}