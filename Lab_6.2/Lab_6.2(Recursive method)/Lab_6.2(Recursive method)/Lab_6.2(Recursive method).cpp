#include <iomanip>
#include <iostream>
#include <time.h>

using namespace std;

typedef int Info;
struct L
{
    L* link;
    Info info;
};

void CreateList(L*& first, L*& last, int N, int Min, int Max, int K);
void PrintList(L* first);
void Enqueue(L*& first, L*& last, Info value);
Info Dequeue(L*& first, L*& last);
void DivideList(L*& first, L*& last, L*& first_1, L*& last_1, L*& first_2, L*& last_2, Info value);

void CreateList(L*& first, L*& last, int N, int Min, int Max, int K)  // Створення списку
{
    if (K < N)
    {
        int x = Min + rand() % (Max - Min + 1);
        Enqueue(first, last, x);
        CreateList(first, last, N, Min, Max, K + 1);
    }
}

void PrintList(L* first)    // Вивід на екран
{
    if (first != NULL)
    {
        cout << first->info << "  ";
        PrintList(first->link);
    }
}

void Enqueue(L*& first, L*& last, Info value)   // Добавлення елементу до списку
{
    L* tmp = new L;             //1
    tmp->info = value;          //2
    tmp->link = NULL;           //3
    if (last != NULL)
        last->link = tmp;       //4
    last = tmp;                 //5
    if (first == NULL)
        first = tmp;            //6
}

Info Dequeue(L*& first, L*& last)   // Вилучення елементу із списку
{
    L* tmp = first->link;       //1
    Info value = first->info;   //2
    delete first;               //3
    first = tmp;                //4
    if (first == NULL)
        last = NULL;            //5
    return value;               //6
}

void DivideList(L*& first, L*& last, L*& first_1, L*& last_1, L*& first_2, L*& last_2, Info value)
{
    if (first != NULL)
    {
        if (first->info > 0)
        {
            value = Dequeue(first, last);
            Enqueue(first_1, last_1, value);
            DivideList(first, last, first_1, last_1, first_2, last_2, value);
        }
        else if (first->info < 0)
        {
            value = Dequeue(first, last);
            Enqueue(first_2, last_2, value);
            DivideList(first, last, first_1, last_1, first_2, last_2, value);
        }
        else
            DivideList(first->link, last, first_1, last_1, first_2, last_2, value);
    }
}

int main()
{
    srand((unsigned)time(NULL));
    L* first = NULL,
        * last = NULL;
    L* first_1 = NULL,
        * last_1 = NULL;
    L* first_2 = NULL,
        * last_2 = NULL;

    int N, Min, Max;
    cout << "Enter list length = "; cin >> N;
    cout << "Interval with: "; cin >> Min;
    cout << "Interval to: "; cin >> Max;
    cout << endl;
    CreateList(first, last, N, Min, Max, 0);
    cout << "Created list L: ";
    PrintList(first);
    cout << endl;
    DivideList(first, last, first_1, last_1, first_2, last_2, 0);
    cout << "List L1: ";
    PrintList(first_1);
    cout << endl;
    cout << "List L2: ";
    PrintList(first_2);

    return 0;
}