#include <iostream>
#include <map>

using namespace std;
// Шаблонная функция для вывода содержимого карты на экран
template <typename M>
void print(const M& m)
{
	cout << "Race placement:\n";
    // Проходим по каждой паре ключ-значение в карте и выводим на экран
	for (const auto& [placement, driver] : m) {
		cout << placement << ": " << driver << '\n';
	}
}

int main()
{
    // Создаем карту с результатами гонки, где ключ - место, а значение - имя гонщикаs
	map<int, string> race_placement{
	{1, "Mario"}, {2, "Luigi"}, {3, "Bowser"},
	{4, "Peach"}, {5, "Yoshi"}, {6, "Koopa"},
	{7, "Toad"}, {8, "Donkey Kong Jr."}
	};
    // Выводим исходные результаты на экран 
	print(race_placement);

	{
        // Извлекаем элементы с ключами 3 и 8 из карты
		auto a(race_placement.extract(3));
		auto b(race_placement.extract(8));
         // Меняем ключи мест между извлеченными элементами
		swap(a.key(), b.key());
        // Вставляем обновленные элементы обратно в карту
		race_placement.insert(move(a));
		race_placement.insert(move(b));
	}
    // Выводим обновленные результаты на экран
	print(race_placement);
}