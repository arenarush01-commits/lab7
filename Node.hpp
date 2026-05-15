#ifndef NODE_HPP
#define NODE_HPP

#include <memory>

// Структура вузла для однозв'язного списку
template <typename T>
struct Node {
    T data;
    std::unique_ptr<Node<T>> next;

    Node(T value) : data(value), next(nullptr) {}
};

// Структура вузла для двозв'язного списку
template <typename T>
struct DNode {
    T data;
    std::shared_ptr<DNode<T>> next;
    std::weak_ptr<DNode<T>> prev; // weak_ptr запобігає циклічним посиланням

    DNode(T value) : data(value), next(nullptr) {}
};

#endif