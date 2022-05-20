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

void PrintList(Elem*& first, Elem*& last, string desc)		// Вивід на екран
{
	cout << desc << endl;
	Elem* tmp = first;
	while (tmp != NULL)
	{
		cout << tmp->info << " ";
		tmp = tmp->next;
	}
	cout << endl;
}

int Process(Elem*& first)		// Обчислення суми додатних елементів
{
	Elem* tmp = first;
	int result = 0;
	while (tmp != NULL)
	{
		if (tmp->info >= 0)
			result += tmp->info;
		tmp = tmp->next;
	}
	return result;

}

int main()
{
	Elem* first = NULL,
		* last = NULL;

	int len;
	cout << "Enter List length = "; cin >> len; cout << endl;
	for (int i = -5; i < len; i++) {
		Enqueue(first, last, i);
	}

	PrintList(first, last, "List before changes : ");
	cout << " Sum of list items = " << Process(first) << endl;

	return 0;
}
