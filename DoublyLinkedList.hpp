#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP

#include "Node.hpp"
#include <iostream>
#include <stdexcept>

template <typename T>
class DoublyLinkedList {
private:
    std::shared_ptr<DNode<T>> head;
    std::shared_ptr<DNode<T>> tail;
    size_t listSize;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), listSize(0) {}

    bool isEmpty() const { return listSize == 0; }
    size_t size() const { return listSize; }

    // Додавання на початок
    void pushFront(T value) {
        auto newNode = std::make_shared<DNode<T>>(value);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        listSize++;
    }

    // Додавання в кінець
    void pushBack(T value) {
        auto newNode = std::make_shared<DNode<T>>(value);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        listSize++;
    }

    // Вилучення першого
    void popFront() {
        if (isEmpty()) throw std::underflow_error("Список порожній!");
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev.reset(); // Очищуємо weak_ptr
        }
        listSize--;
    }

    // Вилучення останнього
    void popBack() {
        if (isEmpty()) throw std::underflow_error("Список порожній!");
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev.lock(); // Перетворюємо weak_ptr у shared_ptr для доступу
            tail->next.reset();
        }
        listSize--;
    }

    // Доступ за індексом
    T& operator[](size_t index) {
        if (index >= listSize) throw std::out_of_range("Індекс поза межами!");
        auto temp = head;
        for (size_t i = 0; i < index; ++i) {
            temp = temp->next;
        }
        return temp->data;
    }

    // Пошук
    bool find(const T& value) const {
        auto temp = head;
        while (temp) {
            if (temp->data == value) return true;
            temp = temp->next;
        }
        return false;
    }

    // Виведення списку
    friend std::ostream& operator<<(std::ostream& os, const DoublyLinkedList& list) {
        auto temp = list.head;
        os << "null <-> ";
        while (temp) {
            os << temp->data << " <-> ";
            temp = temp->next;
        }
        os << "null";
        return os;
    }
};
