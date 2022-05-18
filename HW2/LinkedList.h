#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <string>
#include <iostream>
#include "Node.h"

class LinkedList {
public:
    LinkedList();
    LinkedList(std::string);
    ~LinkedList();
	
	LinkedList& operator=(const LinkedList& rhs);

    void set_name(std::string);
    std::string get_name() const;
    Node* get_head() const;

    bool is_empty() const;
    void insert_front(int);
    void insert_back(int);
    bool insert_after (int, int);
    void clear();

    void print(char = ' ', std::ostream& os = std::cout);
    void print_head(char = '\n', std::ostream& os = std::cout) const;
    void print_tail(char = '\n', std::ostream& os = std::cout) const;

    void makeTestList();
    void log(const std::string& what) const;

private:
    Node* head;
    Node* tail;
    std::string name;
};

std::ostream& operator<<(std::ostream&, const LinkedList&);

#endif