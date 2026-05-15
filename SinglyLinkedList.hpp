#ifndef SINGLY_LINKED_LIST_HPP
#define SINGLY_LINKED_LIST_HPP

#include "Node.hpp"
#include <iostream>
#include <stdexcept>

template <typename T>
class SinglyLinkedList {
private:
    std::unique_ptr<Node<T>> head;
    size_t listSize;

public:
    SinglyLinkedList() : head(nullptr), listSize(0) {}

    // Перевірка чи порожній та розмір
    bool isEmpty() const { return head == nullptr; }
    size_t size() const { return listSize; }

    // Додавання на початок
    void pushFront(T value) {
        auto newNode = std::make_unique<Node<T>>(value);
        newNode->next = std::move(head);
        head = std::move(newNode);
        listSize++;
    }

    // Додавання в кінець
    void pushBack(T value) {
        auto newNode = std::make_unique<Node<T>>(value);
        if (isEmpty()) {
            head = std::move(newNode);
        } else {
            Node<T>* temp = head.get();
            while (temp->next) {
                temp = temp->next.get();
            }
            temp->next = std::move(newNode);
        }
        listSize++;
    }

    // Вилучення першого
    void popFront() {
        if (isEmpty()) throw std::underflow_error("Список порожній!");
        head = std::move(head->next);
        listSize--;
    }

    // Вилучення останнього
    void popBack() {
        if (isEmpty()) throw std::underflow_error("Список порожній!");
        if (listSize == 1) {
            head.reset();
        } else {
            Node<T>* temp = head.get();
            while (temp->next->next) {
                temp = temp->next.get();
            }
            temp->next.reset();
        }
        listSize--;
    }

    // Доступ за індексом
    T& operator[](size_t index) {
        if (index >= listSize) throw std::out_of_range("Індекс поза межами!");
        Node<T>* temp = head.get();
        for (size_t i = 0; i < index; ++i) {
            temp = temp->next.get();
        }
        return temp->data;
    }

    // Пошук елемента
    bool find(const T& value) const {
        Node<T>* temp = head.get();
        while (temp) {
            if (temp->data == value) return true;
            temp = temp->next.get();
        }
        return false;
    }

    // Вилучення за індексом
    void removeAt(size_t index) {
        if (index >= listSize) throw std::out_of_range("Індекс поза межами!");
        if (index == 0) {
            popFront();
            return;
        }
        Node<T>* temp = head.get();
        for (size_t i = 0; i < index - 1; ++i) {
            temp = temp->next.get();
        }
        temp->next = std::move(temp->next->next);
        listSize--;
    }

    // Виведення списку (cout)
    friend std::ostream& operator<<(std::ostream& os, const SinglyLinkedList& list) {
        Node<T>* temp = list.head.get();
        while (temp) {
            os << "[" << temp->data << "] -> ";
            temp = temp->next.get();
        }
        os << "nullptr";
        return os;
    }
};

#endif