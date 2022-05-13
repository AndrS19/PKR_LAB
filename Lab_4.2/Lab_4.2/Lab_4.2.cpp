#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int ProcessTXT(char* fname){

	string shortest, word;
	ifstream fin(fname); // відкрили файл для зчитування
	fin >> word; 
	shortest = word;
	while (getline(fin, word)) // поки можна прочитати рядок
	{
		if (word.size() < shortest.size()) {
			shortest = word;
		}
	}
	cout << "The shortest word: " << shortest << endl;
	return shortest.size();
}

int main()
{
	char fname[10] = "t.txt"; // ім'я файлу
	cout << "Length = " << ProcessTXT(fname) << endl;
	cin.get();
	return 0;
}