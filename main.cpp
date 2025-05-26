#include "vector.h"
#include <iostream>

// Функция для вывода вектора с информацией о размере и ёмкости
void printVector(const Vector& vec, const std::string& operation = "Вектор") {
    std::cout << operation << " (размер=" << vec.size() << ", ёмкость=" << vec.capacity() << "): [ ";
    for (size_t i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << " ";
    std::cout << "]\n";
}

int main() {
    try {
        // Демонстрация добавления элементов в конец вектора
        std::cout << "Добавление в конец (pushBack):\n";
        Vector v1;
        for (int i = 1; i <= 5; ++i)
            v1.pushBack(i); // Добавляем числа 1, 2, 3, 4, 5
        v1.shrinkToFit();
        printVector(v1);

        // Демонстрация добавления элементов в начало вектора
        std::cout << "\nДобавление в начало (pushFront):\n";
        Vector v2;
        for (int i = 1; i <= 5; ++i)
            v2.pushFront(i); // Добавляем числа 1, 2, 3, 4, 5 в начало
        v2.shrinkToFit();
        printVector(v2);

        // Демонстрация добавления элементов в начало существующего вектора v1
        std::cout << "\nДобавление в начало v1 (pushFront):\n";
        for (int i = 1; i <= 5; ++i)
            v1.pushFront(i); // Добавляем числа 1, 2, 3, 4, 5 в начало v1
        v1.shrinkToFit();
        printVector(v1);

        // Демонстрация вставки элемента по индексу
        std::cout << "\nВставка элемента (insert):\n";
        v1.insert(99, 2); // Вставляем 99 на позицию 2
        v1.shrinkToFit();
        printVector(v1);

        // Демонстрация удаления элементов с конца и начала
        std::cout << "\nУдаление с конца и начала (popBack & popFront):\n";
        if (v1.size() > 0) {
            v1.popBack();
            if (v1.size() > 0) {
                v1.popFront();
            }
            v1.shrinkToFit();
            printVector(v1);
        } else {
            std::cout << "Вектор пуст, удаление невозможно.\n";
        }

        // Демонстрация удаления элемента по индексу и диапазона
        std::cout << "\nУдаление элемента и диапазона (erase & eraseBetween):\n";
        if (v1.size() > 1) {
            v1.erase(1); // Удаляем элемент на позиции 1
            v1.shrinkToFit();
            printVector(v1, "После удаления элемента на позиции 1");
        } else {
            std::cout << "Вектор слишком мал для удаления элемента на позиции 1.\n";
        }

        if (v1.size() >= 2) {
            v1.eraseBetween(0, 2); // Удаляем элементы с позиции 0 до 2
            v1.shrinkToFit();
            printVector(v1, "После удаления диапазона [0,2)");
        } else {
            std::cout << "Вектор слишком мал для удаления диапазона [0,2).\n";
        }

        // Демонстрация поиска элемента
        std::cout << "\nПоиск элемента (find):\n";
        long long idx = v2.find(3);
        std::cout << "Индекс элемента 3 в v2: " << idx << "\n";

        // Демонстрация уменьшения ёмкости до размера
        std::cout << "\nУменьшение ёмкости (shrinkToFit):\n";
        v2.shrinkToFit();
        std::cout << "Ёмкость: " << v2.capacity() << " Размер: " << v2.size() << "\n";

        // Демонстрация работы итератора
        std::cout << "\nИтератор:\n";
        std::cout << "v2: [ ";
        if (v2.size() > 0) {
            for (auto it = v2.begin(); it != v2.end(); ++it)
                std::cout << *it << " ";
        }
        std::cout << "]\n";
    } catch (const std::out_of_range& e) {
        std::cerr << "Ошибка: " << e.what() << "\n";
    }

    return 0;
}
