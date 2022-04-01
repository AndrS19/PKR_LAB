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
    union
    {
        int programming;
        int ch_methods;
        int pedagogy;
    };
};

void Create(Student* p, const int N);
void Print(Student* p, const int N);
double LowMark(Student* p, const int N);
int Physics_4(Student* p, const int N);
int Maths_4(Student* p, const int N);
int Programming_4(Student* p, const int N);
int Ch_methods_4(Student* p, const int N);
int Pedagogy_4(Student* p, const int N);

int main()
{                             // забезпечення відображення кирилиці:
    SetConsoleCP(1251);       // встановлення сторінки win-cp1251 в потік вводу
    SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу

    int N;
    cout << " Кількість студентів: ";
    cin >> N;

    Student* p = new Student[N];
    
    Create(p, N);
    Print(p, N);
    LowMark(p, N);
    Physics_4(p, N);
    Maths_4(p, N);
    Programming_4(p, N);
    Ch_methods_4(p, N);
    Pedagogy_4(p, N);

    cout << " Найменший середній бал: " << setprecision(3) << LowMark(p, N) << endl;

    cout << " Кількість оцінок ""добре"" з фізики: " << Physics_4(p, N) << endl;
    cout << " Кількість оцінок ""добре"" з математики: " << Maths_4(p, N) << endl;
    cout << " Кількість оцінок ""добре"" з програмування: " << Programming_4(p, N) << endl;
    cout << " Кількість оцінок ""добре"" з чисельних методів: " << Ch_methods_4(p, N) << endl;
    cout << " Кількість оцінок ""добре"" з педагогіки: " << Pedagogy_4(p, N) << endl;

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
        switch (p[i].specialty)
        {
        case KOMP_NAYK:
            cout << " Оцінка з програмування: ";
            cin >> p[i].programming;
            break;
        case INFORMATUKA:
            cout << " Оцінка з чисельних методів: ";
            cin >> p[i].ch_methods;
            break;
        default:
            cout << " Оцінка з педагогіки: ";
            cin >> p[i].pedagogy;
            break;
        }
        cout << endl;
    }
}

void Print(Student* p, const int N)
{
    cout << "==============================================================================================================================================================================="
        << endl;
    cout << " |  №  |    Прізвище    | Курс |      Спеціальність      | Фізика | Математика | Програмування | Чисельні методи | Педагогіка |"
        << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"
        << endl;

    for (int i = 0; i < N; i++)
    {
        cout << " | " << setw(2) << right << i + 1 << " ";
        cout << " | " << setw(14) << left << p[i].surname;
        cout << " |  " << setw(2) << right << p[i].course << " ";
        cout << " | " << setw(23) << left << specialtyStr[p[i].specialty];
        cout << " | " << setw(4) << right << p[i].physics << "  ";
        cout << " | " << setw(6) << right << p[i].maths << "    ";

        switch (p[i].specialty)
        {
        case KOMP_NAYK:
            cout << " | " << setw(7) << right << p[i].programming << "     " << "  | " << setw(18) << right << " | " << setw(12) << right << "|" << endl;
            break;
        case INFORMATUKA:
            cout << " | " << setw(16) << right << "| " << setw(8) << right << p[i].ch_methods << "      " << "  | " << setw(12) << right << "|" << endl;
            break;
        default:
            cout << " | " << setw(16) << right << "| " << setw(18) << right << "  | " << setw(6) << right << p[i].pedagogy << "     " << "|" << endl;
            break;
        }
    }
    cout << "==============================================================================================================================================================================="
        << endl;
    cout << endl;
}

double LowMark(Student* p, const int N)
{
    double low;
    double low_mark;

    switch (p[0].specialty)
    {
    case KOMP_NAYK:
        low = (p[0].physics + p[0].maths + p[0].programming) / 3.0;
        break;
    case INFORMATUKA:
        low = (p[0].physics + p[0].maths + p[0].ch_methods) / 3.0;
        break;
    case MATEM_EKONOM:
    case FIZ_MATEM:
    case TRUD_NAVCH:
        low = (p[0].physics + p[0].maths + p[0].pedagogy) / 3.0;
        break;
    }

    for (int i = 1; i < N; i++)
    {
        switch (p[i].specialty)
        {
        case KOMP_NAYK:
            low_mark = (p[i].physics + p[i].maths + p[i].programming) / 3.0;
            break;
        case INFORMATUKA:
            low_mark = (p[i].physics + p[i].maths + p[i].ch_methods) / 3.0;
            break;
        case MATEM_EKONOM:
        case FIZ_MATEM:
        case TRUD_NAVCH:
            low_mark = (p[i].physics + p[i].maths + p[i].pedagogy) / 3.0;
            break;
        }
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

int Programming_4(Student* p, const int N)
{
    int pr = 0;
    for (int i = 0; i < N; i++)
    {
        switch (p[i].specialty)
        {
        case KOMP_NAYK:
            if (p[i].programming == 4)
            {
                pr += 1;
            }
            break;
        }
    }
    return pr;
}

int Ch_methods_4(Student* p, const int N)
{
    int ch = 0;
    for (int i = 0; i < N; i++)
    {
        switch (p[i].specialty)
        {
        case INFORMATUKA:
            if (p[i].ch_methods == 4)
            {
                ch += 1;
            }
            break;
        }
    }
    return ch;
}

int Pedagogy_4(Student* p, const int N)
{
    int pe = 0;
    for (int i = 0; i < N; i++)
    {
        switch (p[i].specialty)
        {
        case KOMP_NAYK:
            break;
        case INFORMATUKA:
            break;
        default:
            if (p[i].pedagogy == 4)
            {
                pe += 1;
            }
            break;
        }
    }
    return pe;
}