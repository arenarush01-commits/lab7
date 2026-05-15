#include <iostream>
#include <string>
#include "SinglyLinkedList.hpp"
#include "DoublyLinkedList.hpp"

int main() {
    // Встановлюємо підтримку UTF-8 для виводу в консоль (якщо потрібно)
    setlocale(LC_ALL, "Ukrainian");

    try {
        std::cout << "=== Тестування Однозв'язного Списку (int) ===" << std::endl;
        SinglyLinkedList<int> sList;

        sList.pushBack(10);
        sList.pushBack(20);
        sList.pushFront(5);

        std::cout << "Список: " << sList << std::endl;
        std::cout << "Розмір: " << sList.size() << std::endl;
        std::cout << "Елемент за індексом 1: " << sList[1] << std::endl;

        std::cout << "Видаляємо елемент за індексом 1..." << std::endl;
        sList.removeAt(1);
        std::cout << "Результат: " << sList << std::endl;

        std::cout << "\n=== Тестування Двозв'язного Списку (string) ===" << std::endl;
        DoublyLinkedList<std::string> dList;

        dList.pushBack("C++");
        dList.pushBack("Smart");
        dList.pushBack("Pointers");

        std::cout << "Список: " << dList << std::endl;

        std::cout << "Пошук 'Smart': " << (dList.find("Smart") ? "Знайдено" : "Не знайдено") << std::endl;

        dList.popFront();
        std::cout << "Після popFront: " << dList << std::endl;

        // Тест виключення (out_of_range)
        std::cout << "\n=== Тест обробки помилок ===" << std::endl;
        std::cout << "Спроба доступу до неіснуючого індексу 99..." << std::endl;
        std::cout << dList[99] << std::endl;

    } catch (const std::out_of_range& e) {
        std::cerr << "Помилка діапазону: " << e.what() << std::endl;
    } catch (const std::underflow_error& e) {
        std::cerr << "Помилка пустого списку: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Сталася невідома помилка: " << e.what() << std::endl;
    }

    return 0;
}