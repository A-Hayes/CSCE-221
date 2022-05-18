#ifndef NODE_H
#define NODE_H
#include <iostream>

struct Node {
    int value;
    Node* next;
    Node(int value) : value(value), next(nullptr) {}
    Node() : value(0), next(nullptr) {}
};

inline std::ostream& operator<<(std::ostream& os, const Node& n)
{
    os << n.value;
    return os;
}

#endif