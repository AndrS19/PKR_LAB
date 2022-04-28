#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <Windows.h>               // забезпечення відображення кирилиці

using namespace std;

enum Specialty { KOMP_NAYK, INFORMATUKA, MATEM_EKONOM, FIZ_MATEM, TRUD_NAVCH };

string specialtyStr[] = { "Комп'ютерні науки", "Інформатика", "Математика та економіка", "Фізика та інформатика", "Трудове навчання" };

struct Student
{
	char surname[64];
	unsigned course;
	Specialty specialty;
	unsigned physics;
	unsigned maths;
	unsigned comp_science;
};

void CreateBIN(const char* filename);
void PrintBIN(const char* filename);
double LowMark(const char* filename);
int Physics_4(const char* filename);
int Maths_4(const char* filename);
int Comp_Science_4(const char* filename);
void LoadBIN(char* filename);

int main()
{                             // забезпечення відображення кирилиці:
	SetConsoleCP(1251);       // встановлення сторінки win-cp1251 в потік вводу
	SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу

	char filename[100] = "";

	int menuItem;
	do {
		cout << endl;
		cout << " Виберіть дію: " << endl << endl;
		cout << " [1] - введення даних з клавіатури " << endl;
		cout << " [2] - вивід даних на екран " << endl;
		cout << " [0] - вихід та завершення роботи програми " << endl << endl;
		cout << " Введіть значення: ";
		cin >> menuItem;
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
			cout << " Найменший середній бал: " << LowMark(filename) << endl;
			cout << " Кількість оцінок ""добре"" з фізики: " << Physics_4(filename) << endl;
			cout << " Кількість оцінок ""добре"" з математики: " << Maths_4(filename) << endl;
			cout << " Кількість оцінок ""добре"" з інформатики: " << Comp_Science_4(filename) << endl;
			break;
		case 0:
			break;
		default:
			cout << " Ви ввели помилкове значення! "
				" Слід ввести число - номер вибраного пункту меню " << endl;
		}
	} while (menuItem != 0);

	return 0;
}

void CreateBIN(const char* filename)
{
	ofstream f(filename, ios::binary); // відкрили файл для запису
	char ch; // відповідь користувача – чи продовжувати введення
	int n = 1;
	int specialty;
	Student student;

	do {
		cout << " Студент № " << n << ":" << endl;
		cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
		cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок
		cout << " Прізвище: ";
		cin >> student.surname;
		cout << " Курс: ";
		cin >> student.course;
		cout << " Спеціальність (0 - Комп'ютерні науки, 1 - Інформатика, 2 - Математика та економіка, 3 - Фізика та інформатика, 4 - Трудове навчання): ";
		cin >> specialty;
		student.specialty = (Specialty)specialty;
		cout << " Оцінка з фізики: ";
		cin >> student.physics;
		cout << " Оцінка з математики: ";
		cin >> student.maths;
		cout << " Оцінка з інформатики: ";
		cin >> student.comp_science;
		cout << endl;
		f.write((char*)&student, sizeof(Student)); // записали у файл
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

	cout << "==============================================================================================="<< endl;
	cout << " |  №  |    Прізвище    | Курс |      Спеціальність      | Фізика | Математика | Інформатика | "<< endl;
	cout << "-----------------------------------------------------------------------------------------------"<< endl;

	Student student;
	int i = 1;

	while (f.read((char*)&student, sizeof(Student))) {
		cout << " | " << setw(2) << right << i << " ";
		cout << " | " << setw(14) << left << student.surname;
		cout << " |  " << setw(2) << right << student.course << " ";
		cout << " | " << setw(23) << left << specialtyStr[student.specialty];
		cout << " | " << setw(4) << right << student.physics << "  ";
		cout << " | " << setw(6) << right << student.maths << "    ";
		cout << " | " << setw(6) << right << student.comp_science << "   " << "   |";
		cout << endl;
		i++;
	}
	cout << "==============================================================================================="<< endl;
	cout << endl;
}

double LowMark(const char* filename)
{
	ifstream f(filename, ios::binary);

	Student student;
	double low = 5;
	double low_mark = 5;

	while (f.read((char*)&student, sizeof(Student)))
	{
		low_mark = (student.physics + student.maths + student.comp_science) / 3.0;
		if (low_mark < low)
		{
			low = low_mark;
		}
	}

	f.close();
	return low;
}

int Physics_4(const char* filename)
{
	ifstream f(filename, ios::binary);

	Student student;
	int ph = 0;

	while (f.read((char*)&student, sizeof(Student)))
	{
		if (student.physics == 4)
		{
			ph += 1;
		}
	}
	f.close();

	return ph;
}

int Maths_4(const char* filename)
{
	ifstream f(filename, ios::binary);

	Student student;
	int ma = 0;

	while (f.read((char*)&student, sizeof(Student)))
	{
		if (student.maths == 4)
		{
			ma += 1;
		}
	}
	f.close();

	return ma;
}

int Comp_Science_4(const char* filename)
{
	ifstream f(filename, ios::binary);

	Student student;
	int pr = 0;

	while (f.read((char*)&student, sizeof(Student)))
	{
		if (student.comp_science == 4)
		{
			pr += 1;
		}
	}
	f.close();

	return pr;
}