#include <iostream>
#include <windows.h>
#include <iomanip>
#include <string>

using namespace std;

struct Student
{
    Student* link;
    string surname;
    double gpa;
    int stipend;
};

void CreateList(Student*& first, Student*& last, int N);
void PrintList(Student* first, int i);
void Enqueue(Student*& first, Student*& last, string surname, double gpa, int stipend);
void DequeueBegStudent(Student*& first, Student*& last);
void DequeueStudent(Student*& first, Student*& last);
int Find(Student* first, int i, double x);
void Checking(Student* first, Student* last);

void CreateList(Student*& first, Student*& last, int N)  // Створення списку
{
    string surname;
    double gpa;
    int stipend;
    for (int i = 0; i < N; i++)
    {
        cin.sync();
        cout << "Прізвище: "; cin >> surname;
        cout << "Середній бал: "; cin >> gpa;
        do
        {
            cout << "Стипендія (0 - Ні, 1 - Так): "; cin >> stipend;
        } while (stipend < 0);
        Enqueue(first, last, surname, gpa, stipend);
        cout << endl;
    }
}

void PrintList(Student* first, int i)    // Вивід на екран
{
    while (first != NULL)
    {
        if (i == 0)
            cout << " Прізвище:     | " << setw(8) << left << first->surname << " " << " | ";
        else if (i == 1)
            cout << " Середній бал: | " << setw(8) << left << first->gpa << " " << " | ";
        else
            cout << " Стипендія:    | " << setw(8) << left << first->stipend << " " << " | ";

        first = first->link;
    }
    cout << endl;
}

void Enqueue(Student*& first, Student*& last, string surname, double gpa, int stipend)   // Добавлення елементу до списку
{
    Student* tmp = new Student;
    tmp->surname = surname;
    tmp->gpa = gpa;
    tmp->stipend = stipend;
    tmp->link = NULL;
    if (last != NULL)
        last->link = tmp;
    last = tmp;
    if (first == NULL)
        first = tmp;
}

void DequeueBegStudent(Student*& first, Student*& last)   // Вилучення елементу із списку
{
    Student* tmp = first->link;
    delete first;
    first = tmp;
}

void DequeueStudent(Student*& first, Student*& last)   // Вилучення елементу із списку
{
    Student* tmp = first->link->link;
    delete first->link;
    first->link = tmp;
}

int Find(Student* first, int i, double x)   // Пошук студента із заданим середнім балом
{
    int k = 0;
    while (first != NULL)
    {
        if (first->gpa == x)
        {
            if (i == 0)
                cout << " Прізвище:     | " << setw(8) << left << first->surname << " " << " | ";
            else if (i == 1)
                cout << " Середній бал: | " << setw(8) << left << first->gpa << " " << " | ";
            else
                cout << " Стипендія:    | " << setw(8) << left << first->stipend << " " << " | ";
            k++;
        }
        first = first->link;
    }
    cout << endl;
    return k;
}

void Checking(Student* first, Student* last)   // Студенти, що не мають стипендії
{
    while (first != NULL && first->stipend == 0)
        DequeueBegStudent(first, last);
    while (first != NULL && first->link != NULL)
    {
        if (first->link->stipend == 0)
            DequeueStudent(first, last);
        else
            first = first->link;
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Student* first = NULL,
        * last = NULL;

    int N;
    double x;
    cout << "Кількість студентів: "; cin >> N;
    cout << endl;
    CreateList(first, last, N);
    cout << endl;
    for (int i = 0; i < 3; i++)
        PrintList(first, i);
    cout << endl;
    cout << "Студенти із заданим середнім балом: "; cin >> x;
    for (int i = 0; i < 3; i++)
        Find(first, i, x);
    cout << endl;
    cout << "Студенти, що мають стипендію: " << endl;
    Checking(first, last);
    for (int i = 0; i < 3; i++)
        PrintList(first, i);

    system("pause");
    return 0;
}