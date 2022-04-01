#include <iostream>
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
double LowMark(Student* p, const int N);
int Physics_4(Student* p, const int N);
int Maths_4(Student* p, const int N);
int Comp_Science_4(Student* p, const int N);

int main()
{                             // забезпечення відображення кирилиці:
	SetConsoleCP(1251);       // встановлення сторінки win-cp1251 в потік вводу
	SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу

	int N;
	cout << " Кількість студентів: ";
	cin >> N;
	cout << endl;

	Student* p = new Student[N];

	Create(p, N);
	Print(p, N);
	LowMark(p, N);
	Physics_4(p, N);
	Maths_4(p, N);
	Comp_Science_4(p, N);

	cout << " Найменший середній бал: " << setprecision(3) << LowMark(p, N) << endl;

	cout << " Кількість оцінок ""добре"" з фізики: " << Physics_4(p, N) << endl;
	cout << " Кількість оцінок ""добре"" з математики: " << Maths_4(p, N) << endl;
	cout << " Кількість оцінок ""добре"" з інформатики: " << Comp_Science_4(p, N) << endl;

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

double LowMark(Student* p, const int N)
{
	double low = (p[0].physics + p[0].maths + p[0].comp_science) / 3.0;
	double low_mark;
	for (int i = 1; i < N; i++)
	{
		low_mark = (p[i].physics + p[i].maths + p[i].comp_science) / 3.0;
		if (low_mark < low)
		{
			low = low_mark;
		}
	}
	return low;
}

int Physics_4(Student* p, const int N)
{
	int ph = 0;
	for (int i = 0; i < N; i++)
	{
		if (p[i].physics == 4)
		{
			ph += 1;
		}
	}
	return ph;
}

int Maths_4(Student* p, const int N)
{
	int ma = 0;
	for (int i = 0; i < N; i++)
	{
		if (p[i].maths == 4)
		{
			ma += 1;
		}
	}
	return ma;
}

int Comp_Science_4(Student* p, const int N)
{
	int pr = 0;
	for (int i = 0; i < N; i++)
	{
		if (p[i].comp_science == 4)
		{
			pr += 1;
		}
	}
	return pr;
}