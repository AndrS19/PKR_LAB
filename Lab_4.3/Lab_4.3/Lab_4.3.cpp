#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <Windows.h>						// забезпечення відображення кирилиці

using namespace std;

enum Name { PHONE, MONITOR, POTATO, CARROT };

string nameStr[] = { "телефон", "монітор", "картопля", "морква" };

struct Goods 
{
    Name name;
    string shop;
    double price;
    union 
    {
        int number_1kg;
        int number_1piece;
    };
};

void CreateTXT(char* filename, int N);
void PrintTXT(char* filename);
void SearchTXT(char* filename, char* Shop);
void AddGoods(char* filename, int N);

int main()
{                             // забезпечення відображення кирилиці:
    SetConsoleCP(1251);       // встановлення сторінки win-cp1251 в потік вводу
    SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу

    char Shop[20];
    char filename[100];
    int N;

    cout << "Введіть назву файлу: "; 
    cin >> filename;
    cout << endl;

    int menuItem;
    do {
        cout << endl;
        cout << " [1] - Створення списку" << endl;
        cout << " [2] - Перегляд списку" << endl;
        cout << " [3] - Поповнення списку" << endl;
        cout << " [4] - Вивід на екран інформації про товари, що продаються в певному магазині" << endl;
        cout << " [0] - Вихід та завершення роботи програми" << endl << endl;
        cout << " Введіть значення: "; cin >> menuItem;
        cout << endl << endl;

        switch (menuItem)
        {
        case 1:
            cout << " Введіть кількість товарів: "; cin >> N;
            CreateTXT(filename, N);
            break;
        case 2:
            PrintTXT(filename);
            break;
        case 3:
            cout << " Введіть кількість товарів: "; cin >> N;
            AddGoods(filename, N);
            break;
        case 4:
            cout << " Введіть назву магазину : "; cin >> Shop;
            SearchTXT(filename, Shop);
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

void CreateTXT(char* filename, int N)
{
    Goods p;
    ofstream f(filename);
    int name;

    f << "------------------------------------------------------------------"
        << endl
        << "|  №  |     Товар    |   Магазин   | Ціна |К-сть(шт.)|К-сть(кг.) |"
        << endl
        << "------------------------------------------------------------------" << endl;

    for (int i = 0; i < N; i++)
    {
        cout << "Товар № " << i + 1 << ":" << endl;

        cout << " Товар (0 - телефон, 1 - монітор, 2 - картопля, 3 - морква): "; 
        cin >> name;
        p.name = (Name)name;
        cout << " Назва магазину: "; cin >> p.shop;
        cout << " Ціна: "; cin >> p.price;

        f << "| " << setw(3) << right << i + 1 << " ";
        f << "| " << setw(13) << left << nameStr[p.name]
            << "| " << setw(12) << right << p.shop
            << "| " << setw(5) << left << p.price;

        switch (p.name)
        {
        case PHONE:
            cout << " Кількість(шт.): "; cin >> p.number_1piece;
            f << "| " << setw(11) << right << "|" << " " << setw(8) << right
                << p.number_1piece << " |" << endl;
            break;
        case MONITOR:
            cout << " Кількість(шт.): "; cin >> p.number_1piece;
            f << setw(0) << right << "|" << " " << setw(9) << right
                << p.number_1piece << " | " << setw(10) << "|" << endl;
            break;
        case POTATO:
            cout << " Кількість(кг.): "; cin >> p.number_1kg;
            f << "| " << setw(11) << right << "|" << " " << setw(8) << right
                << p.number_1kg << " |" << endl;
            break;
        case CARROT:
            cout << " Кількість(кг.): "; cin >> p.number_1kg;
            f << "| " << setw(11) << right << "|" << " " << setw(8) << right
                << p.number_1kg << " |" << endl;
            break;
        }
        f << "------------------------------------------------------------------" << endl;
    }

}

void PrintTXT(char* filename)
{
    ifstream fin(filename);
    string s;

    while (getline(fin, s))
    {
        cout << s << endl;
    }
}

void AddGoods(char* filename, int N)
{
    Goods p;
    ofstream f(filename, ios::app);

    int name;
    for (int i = 0; i < N; i++)
    {
        cout << "Товар № " << i + 1 << ":" << endl;

        cout << " товар (0 - телефон, 1 - монітор, 2 - картопля, 3 - морква): "; cin >> name;
        p.name = (Name)name;
        cout << " назва магазину: "; cin >> p.shop;
        cout << " ціна: "; cin >> p.price;

        f << "| " << setw(3) << right << i + 1 << " ";
        f << "| " << setw(13) << left << nameStr[p.name]
            << "| " << setw(12) << right << p.shop
            << "| " << setw(5) << left << p.price;

        switch (p.name)
        {
        case PHONE:
            cout << " кількість(шт.): "; cin >> p.number_1piece;
            f << "| " << setw(11) << right << "|" << " " << setw(8) << right
                << p.number_1piece << " |" << endl;
            break;
        case MONITOR:
            cout << " кількість(шт.): "; cin >> p.number_1piece;
            f << setw(0) << right << "|" << " " << setw(9) << right
                << p.number_1piece << " | " << setw(10) << "|" << endl;
            break;
        case POTATO:
            cout << " кількість(кг.): "; cin >> p.number_1kg;
            f << "| " << setw(11) << right << "|" << " " << setw(8) << right
                << p.number_1kg << " |" << endl;
            break;
        case CARROT:
            cout << " кількість(кг.): "; cin >> p.number_1kg;
            f << "| " << setw(11) << right << "|" << " " << setw(8) << right
                << p.number_1kg << " |" << endl;
            break;
        }
        f << "------------------------------------------------------------------" << endl;
    }
}

void SearchTXT(char* filename, char* Shop)
{
    ifstream fin(filename);
    string s;
    bool ShoworNOT = 0;
    cout << "=================================================================="
        << endl;
    cout << "|  №  |     Товар    |   Магазин   | Ціна |К-сть(шт.)|К-сть(кг.) |"
        << endl;
    cout << "------------------------------------------------------------------" << endl;

    while (getline(fin, s))
    {
        if (s.find(Shop, 0) != -1 && s[s.find(Shop, 0) - 1] == ' ' && (s.find('|', s.find(Shop, 0) - 1) - s.find(Shop, 0) == strlen(Shop)))
        {
            cout << s << endl;
            ShoworNOT = 1;
        }
    }
    if (ShoworNOT == 0) cout << "                         Товару не знайдено!                 " << endl;
    cout << "------------------------------------------------------------------" << endl;
}