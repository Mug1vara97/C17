#include <iostream>
#include <unordered_map>
//Определение структуры, представляющей координаты
struct coord {
	int x;
	int y;
};
// Перегрузка оператора сравнения для структуры
bool operator==(const coord& l, const coord& r)
{
	return l.x == r.x && l.y == r.y;
}
// Определение специализации хеш-функции для структуры coord
namespace std
{
	template <>
	struct hash<coord>
	{
		using argument_type = coord; // Тип аргумента хеш-функции
		using result_type = size_t; // Тип результата хеш-функции

		result_type operator()(const argument_type& c) const // Перегрузка оператора для вычисления хеша
		{
			return static_cast<result_type>(c.x) // Преобразование величин x и y в размерный тип
				+ static_cast<result_type>(c.y);
		}
	};
}

int main()
{
    // Создание и инициализация unordered_map с координатами и значениями
	std::unordered_map<coord, int> m{ {{0, 0}, 1}, {{0, 1}, 2},
	{{2, 1}, 3} };
	for (const auto& [key, value] : m) {
		std::cout << "{(" << key.x << ", " << key.y
			<< "): " << value << "} ";
	}
	std::cout << '\n';
}