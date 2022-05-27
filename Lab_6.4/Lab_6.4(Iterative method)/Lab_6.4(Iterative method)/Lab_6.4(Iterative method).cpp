#include <iostream>
#include <iomanip>
#include <windows.h>
#include <time.h>

using namespace std;

typedef int Info;
struct Elem
{
	Elem* link;
	Info info;
};

void Create(Elem*& first, int N, int Low, int High);
void Insert(Elem*& L, Info value);
void Remove(Elem*& L);
void Scanning(Elem* L, int x);
void Print(Elem* L);

void Create(Elem*& first, int N, int Low, int High)
{
	for (int i = 0; i < N; i++)
	{
		int value = Low + rand() % (High - Low + 1);
		Insert(first, value);
	}
}

void Insert(Elem*& L, Info value)
{
	Elem* tmp = new Elem;
	tmp->info = value;
	if (L != NULL)
	{
		Elem* T = L;
		while (T->link != L)
			T = T->link;
		T->link = tmp;
	}
	else
	{
		L = tmp;
	}
	tmp->link = L;
}

void Remove(Elem*& L)
{
	Elem* T = L->link;
	while (T->link != L->link)
		T = T->link;

	Info value = L->info;

	if (T != L->link)
	{
		Elem* tmp = L->link->link;
		delete L->link;
		L->link = tmp;
		T->link = L->link;
	}
	else
	{
		delete L->link;
		L->link = NULL;
	}
}

void Scanning(Elem* L, int x)
{
	if (L == NULL)
		return;

	Elem* first = L;
	while (L->link != first)
	{
		if (L->info == x)
			Remove(L);
		else
			L = L->link;
	}
}

void Print(Elem* L)
{
	if (L == NULL)
		return;

	Elem* first = L;
	cout << setw(4) << L->info;
	while (L->link != first)
	{
		L = L->link;
		cout << setw(4) << L->info;
	}
	cout << endl;
}

int main()
{
	srand((unsigned)time(NULL));
	Elem* L = NULL;

	int Low, High, N, x;
	cout << "Interval with: "; cin >> Low;
	cout << "Interval to: "; cin >> High;
	cout << "Enter list length = "; cin >> N;
	Create(L, N, Low, High);
	cout << endl;
	cout << "Created list L: " << endl;
	Print(L);
	cout << endl;
	cout << "Number after which to delete all items: "; cin >> x;
	cout << endl;
	cout << "List without deleted elements:" << endl;
	Scanning(L, x);
	Print(L);
	cout << endl;

	system("pause");
	return 0;
}