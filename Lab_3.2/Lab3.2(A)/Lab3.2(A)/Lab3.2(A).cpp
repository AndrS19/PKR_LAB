﻿#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>               // забезпечення відображення кирилиці

using namespace std;

enum Specialty { KOMP_NAYK, INFORMATUKA, MATEM_EKONOM, FIZ_MATEM, TRUD_NAVCH };

string specialtyStr[] = { "Комп'ютерні науки", "Інформатика", "Математика та економіка", "Фізика та інформатика", "Трудове навчання" };

struct Student
{
	string surname;
	int course;
	Specialty specialty;
	int physics;
	int maths;
	int comp_science;
};

void Create(Student* p, const int N);
void Print(Student* p, const int N);
void Sort(Student* p, const int N);
int BinSearch(Student* p, const int N, const string surname, const int course, const Specialty specialty);
int* IndexSort(Student* p, const int N);
void PrintIndexSorted(Student* p, int* I, const int N);

int main()
{                             // забезпечення відображення кирилиці:
	SetConsoleCP(1251);       // встановлення сторінки win-cp1251 в потік вводу
	SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу

	int N;
	cout << " Кількість студентів: ";
	cin >> N;

	Student* p = new Student[N];

	int ispecialty;
	Specialty specialty;
	string surname;
	int course;
	int found;

	int menuItem;
	do {
		cout << endl;
		cout << " Виберіть дію: " << endl << endl;
		cout << " [1] - введення даних з клавіатури " << endl;
		cout << " [2] - вивід даних на екран " << endl;
		cout << " [3] - фізичне впорядкування даних " << endl;
		cout << " [4] - бінарний пошук студента за вказаним прізвищем, курсом та спеціальністю " << endl;
		cout << " [5] - індексне впорядкування та вивід даних " << endl;
		cout << " [0] - вихід та завершення роботи програми " << endl << endl;
		cout << " Введіть значення: "; cin >> menuItem;
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
			cout << " Введіть ключі пошуку: " << endl;
			cout << " Прізвище: ";
			cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
			cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок
			getline(cin, surname);
			cout << " Курс: ";
			cin >> course;
			cout << " Спеціальність (0 - Комп'ютерні науки, 1 - Інформатика, 2 - Математика та економіка, 3 - Фізика та інформатика, 4 - Трудове навчання): ";
			cin >> ispecialty;
			specialty = (Specialty)ispecialty;
			cout << endl;
			if ((found = BinSearch(p, N, surname, course, specialty)) != -1)
				cout << " Знайдено студента в позиції № " << found + 1 << endl;
			else
				cout << " Шуканого студента не знайдено " << endl;
			break;
		case 5:
			PrintIndexSorted(p, IndexSort(p, N), N);
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

void Create(Student* p, const int N)
{
	int specialty;
	for (int i = 0; i < N; i++)
	{
		cout << " Студент № " << i + 1 << ":" << endl;

		cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
		cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок

		cout << " Прізвище: ";
		getline(cin, p[i].surname);
		cout << " Курс: ";
		cin >> p[i].course;
		cout << " Спеціальність (0 - Комп'ютерні науки, 1 - Інформатика, 2 - Математика та економіка, 3 - Фізика та інформатика, 4 - Трудове навчання): ";
		cin >> specialty;
		p[i].specialty = (Specialty)specialty;
		cout << " Оцінка з фізики: ";
		cin >> p[i].physics;
		cout << " Оцінка з математики: ";
		cin >> p[i].maths;
		cout << " Оцінка з інформатики: ";
		cin >> p[i].comp_science;
		cout << endl;
	}
}

void Print(Student* p, const int N)
{
	cout << "=========================================================================================================="
		<< endl;
	cout << " |  №  |    Прізвище    | Курс |      Спеціальність      | Фізика | Математика | Інформатика | "
		<< endl;
	cout << "----------------------------------------------------------------------------------------------------------"
		<< endl;

	for (int i = 0; i < N; i++)
	{
		cout << " | " << setw(2) << right << i + 1 << " ";
		cout << " | " << setw(14) << left << p[i].surname;
		cout << " |  " << setw(2) << right << p[i].course << " ";
		cout << " | " << setw(23) << left << specialtyStr[p[i].specialty];
		cout << " | " << setw(4) << right << p[i].physics << "  ";
		cout << " | " << setw(6) << right << p[i].maths << "    ";
		cout << " | " << setw(6) << right << p[i].comp_science << "   " << "   |";
		cout << endl;
	}
	cout << "=========================================================================================================="
		<< endl;
	cout << endl;
}

void Sort(Student* p, const int N)
{
	Student tmp;
	for (int i0 = 0; i0 < N - 1; i0++) // метод "бульбашки"
		for (int i1 = 0; i1 < N - i0 - 1; i1++)
			if ((p[i1].specialty > p[i1 + 1].specialty)
				||
				(p[i1].specialty == p[i1 + 1].specialty &&
					p[i1].surname < p[i1 + 1].surname)
				||
				(p[i1].specialty == p[i1 + 1].specialty &&
					p[i1].surname == p[i1 + 1].surname &&
					p[i1].course > p[i1 + 1].course))
			{
				tmp = p[i1];
				p[i1] = p[i1 + 1];
				p[i1 + 1] = tmp;
			}
}

int BinSearch(Student* p, const int N, const string surname, const int course, const Specialty specialty)
{   // повертає індекс знайденого елемента або -1, якщо шуканий елемент відсутній
	int L = 0, R = N - 1, m;
	do
	{
		m = (L + R) / 2;
		if (p[m].surname == surname && p[m].course == course && p[m].specialty == specialty)
			return m;
		if ((p[m].surname < surname)
			||
			(p[m].surname == surname &&
				p[m].course < course)
			||
			(p[m].surname == surname &&
				p[m].course == course &&
				p[m].specialty < specialty))
		{
			L = m + 1;
		}
		else
		{
			R = m - 1;
		}
	} while (L <= R);
	return -1;
}

int* IndexSort(Student* p, const int N)
{ // використовуємо метод вставки для формування індексного масиву
 // 
 // int i, j, value;
 // for (i = 1; i < length; i++) {
 // value = a[i];
 // for (j = i - 1; j >= 0 && a[j] > value; j--) {
 // a[j + 1] = a[j];
 // }
 // a[j + 1] = value;
 // }

	int* I = new int[N];

	for (int i = 0; i < N; i++)
		I[i] = i;

	int i, j, value;
	for (i = 1; i < N; i++)
	{
		value = I[i];
		for (j = i - 1;
			j >= 0 && ((p[I[j]].specialty > p[value].specialty)
				||
				(p[I[j]].specialty == p[value].specialty &&
					p[I[j]].surname > p[value].surname)
				||
				(p[I[j]].specialty == p[value].specialty &&
					p[I[j]].surname == p[value].surname &&
					p[I[j]].course > p[value].course));
			j--)
		{
			I[j + 1] = I[j];
		}
		I[j + 1] = value;
	}
	return I;
}

void PrintIndexSorted(Student* p, int* I, const int N)
{  // аналогічно функції Print(), але замість звертання p[i]... 
 // використовуємо доступ за допомогою індексного масиву І: p[I[i]]...

	cout << "=========================================================================================================="
		<< endl;
	cout << " |  №  |    Прізвище    | Курс |      Спеціальність      | Фізика | Математика | Інформатика | "
		<< endl;
	cout << "----------------------------------------------------------------------------------------------------------"
		<< endl;

	for (int i = 0; i < N; i++)
	{
		cout << " | " << setw(2) << right << i + 1 << " ";
		cout << " | " << setw(14) << left << p[I[i]].surname;
		cout << " |  " << setw(2) << right << p[I[i]].course << " ";
		cout << " | " << setw(23) << left << specialtyStr[p[I[i]].specialty];
		cout << " | " << setw(4) << right << p[I[i]].physics << "  ";
		cout << " | " << setw(6) << right << p[I[i]].maths << "    ";
		cout << " | " << setw(6) << right << p[I[i]].comp_science << "   " << "   |";
		cout << endl;
	}
	cout << "=========================================================================================================="
		<< endl;
	cout << endl;
}