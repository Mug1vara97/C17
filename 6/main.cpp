#include <iostream>
#include <set>
#include <string>
#include <iterator>

using namespace std;

int main()
{
     // Создаем множество строк
	set<string> s;
    // Создаем итератор для ввода
	istream_iterator<string> it{ cin };
    // Создаем итератор, который указывает на конец потока
	istream_iterator<string> end;
    // Считываем все строки из стандартного потока ввода и добавляем их в множество
	copy(it, end, inserter(s, s.end()));
    // Выводим все строки из множества
	for (const auto word : s) {
		cout << word << ", ";
	}
	cout << '\n';
}