#include <iostream>
#include <map>
#include <string>

int main()
{
 // создаем ассоциативный массив map, инициализируем его значениями
 std::map<std::string, size_t> m {{"b", 1}, {"c", 2}, {"d", 3}};
 // создаем итератор для вставки элементов в map, инициализируем его указателем на конец map
 auto insert_it (std::end(m));
 // проходим по массиву строк
 for (const auto &s : {"z", "y", "x", "w"}) {
    // вставляем каждую строку из массива в map, с значением 1
    insert_it = m.insert(insert_it, {s, 1});
 }
  // вставляем строку "a" в map со значением 1
  m.insert(std::end(m), {"a", 1});
  // проходим по элементам map
  for (const auto & [key, value] : m) {
    // выводим на экран ключ и значение каждого элемента
    std::cout << "\"" << key << "\": " << value << ", ";
 }
 std::cout << '\n';
}