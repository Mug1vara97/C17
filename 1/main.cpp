#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <cassert>

using namespace std;

void insert_sorted(vector<string> &v, const string &word)
{
 // находим позицию, куда нужно вставить новое слово, чтобы сохранить порядок сортировки
 const auto insert_pos (lower_bound(begin(v), end(v), word));
 // вставляем слово на найденную позицию
 v.insert(insert_pos, word);
}


int main()
{
 // создаем вектор со строками
 vector<string> v {"some", "random", "words",
 "without", "order", "aaa",
 "yyy"};
 // проверяем, что вектор не отсортирован
 assert(false == is_sorted(begin(v), end(v)));
 // сортируем вектор
 sort(begin(v), end(v));
 // проверяем, что вектор отсортирован
 assert(true == is_sorted(begin(v), end(v)));
 // вставляем новые слова на правильные позиции
 insert_sorted(v, "foobar");
 insert_sorted(v, "zzz");
 // выводим все слова из вектора
 for (const auto &w : v) {
 cout << w << " ";
 }
 cout << '\n';
}