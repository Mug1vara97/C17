#include <iostream>
#include <stack>
#include <iterator>
#include <map>
#include <sstream>
#include <cassert>
#include <vector>
#include <stdexcept>
#include <cmath>

using namespace std;

//Функция evaluate_rpn вычисляет результат выражения 
template <typename IT>
double evaluate_rpn(IT it, IT end)
{
    stack<double> val_stack;
    // Создание стека для хранения значений
    auto pop_stack([&]() {
        // Функция для извлечения значения из стека
        auto r(val_stack.top());
        val_stack.pop();
        return r;
        });
    // Словарь операций с их функциями
    map<string, double (*)(double, double)> ops{
    {"+", [](double a, double b) { return a + b; }},
    {"-", [](double a, double b) { return a - b; }},
    {"*", [](double a, double b) { return a * b; }},
    {"/", [](double a, double b) { return a / b; }},
    {"^", [](double a, double b) { return pow(a, b); }},
    {"%", [](double a, double b) { return fmod(a, b); }},
    };
    // Проход по каждому элементу
    for (; it != end; ++it) {
        stringstream ss{ *it };
        if (double val; ss >> val) { // Если элемент - число, помещаем его в стек
            val_stack.push(val);
        }
        else {
            const auto r{ pop_stack() }; // Извлекаем два значения из стека
            const auto l{ pop_stack() };
            try {
                const auto& op(ops.at(*it)); // Пытаемся найти операцию в словаре
                const double result{ op(l, r) }; // Вычисляем результат с помощью операции
                val_stack.push(result); // Помещаем результат обратно в стек
            }
            catch (const out_of_range&) { // Перехватываем ошибку, если оператор отсутствует
                throw invalid_argument(*it); // Выбрасываем исключение
            }

        }
        return val_stack.top(); // Возвращаем результат после обработки всех элементов
    }
}

int main()
{
    try {
        cout << evaluate_rpn(istream_iterator<string>{cin}, {})
            << '\n';
    }
    catch (const invalid_argument& e) { //Обработка исключения
        cout << "Invalid operator: " << e.what() << '\n';
    }
}