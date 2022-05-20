#include <iomanip>
#include <iostream>

using namespace std;

typedef int Info;
struct Elem
{
	Elem* next,
		* prev;
	Info info;
};

void Enqueue(Elem*& first, Elem*& last, Info value)		// Добавлення елементу до списку
{
	Elem* tmp = new Elem;		// 1
	tmp->info = value;			// 2
	tmp->next = NULL;			// 3
	if (last != NULL)
		last->next = tmp;		// 4
	tmp->prev = last;			// 5
	last = tmp;					// 6
	if (first == NULL)
		first = tmp;			// 7
}

void CreateList(Elem*& first, Elem*& last, int i)		// Створення списку
{
	if (i <= 10) {
		Enqueue(first, last, i);
		CreateList(first, last, i + 1);
	}
}


void PrintList(Elem*& first, Elem*& last, Elem* tmp)		// Вивід на екран
{
	if (tmp != NULL) 
	{
		cout << tmp->info << " ";
		return PrintList(first, last, tmp = tmp->next);
	}
	else
	cout << endl;
}

int Process(Elem*& first, Elem*& last, Elem* tmp, int& result)		// Обчислення суми додатних елементів
{
	if (tmp != NULL)
	{
		if (tmp->info >= 0)//3
			result += tmp->info;//4
		return Process(first, last, tmp = tmp->next, result);
	}
}

int main()
{
	Elem* first = NULL,
		* last = NULL;

	CreateList(first, last, -10);
	PrintList(first, last, first);
	int res = 0;
	Process(first, last, first, res);
	cout << " Sum of list items = " << res << endl;

	return 0;
}