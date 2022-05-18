#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList() : head(nullptr), tail(nullptr) {}

LinkedList::LinkedList(string name) : head(nullptr), tail(nullptr), name(name) {}
LinkedList::~LinkedList()
{
    this->clear();
}

LinkedList& LinkedList::operator=(const LinkedList& rhs){
	if(this!= &rhs){
		this->clear();
		if (rhs.is_empty()){
			return *this;
		}
		if((rhs.tail)->value == (rhs.head)->value){
			//assign head a new Node initialized with (rhs.head)->value
			head = new Node((rhs.head)->value);
			//assign tail the address value stored in head (tail = head)
			tail = head;
			return *this;
		}
		//create a new Node* curr_rhs and initialize to rhs.head
		Node* curr_rhs = rhs.head;
		//assign head a new Node(curr_rhs->value)
		head = new Node(curr_rhs->value);
		//assign curr_rhs with curr_rhs->next
		curr_rhs = curr_rhs->next;
		//create a new Node* curr_lhs and initialize to head
		Node* curr_lhs = head;
		while (curr_rhs != nullptr){
			//assign curr_lhs->next a new Node(curr_rhs->value)
			curr_lhs->next = new Node(curr_rhs->value);
			//assign tail = curr_lhs->next;
			tail = curr_lhs->next;
			//assign curr_rhs = curr_rhs->next;
			curr_rhs = curr_rhs->next;
			//assign curr_lhs = curr_lhs->next;
			curr_lhs = curr_lhs->next;
		}
	}
	return *this;
}

void LinkedList::set_name(string name)
{
    this->name = name;
}

string LinkedList::get_name() const
{
    return name;
}

Node* LinkedList::get_head() const
{
    return head;
}

bool LinkedList::is_empty() const
{
    if (head == nullptr && tail == nullptr)
        return true;
    else
        return false;
}

void LinkedList::insert_front(int value)
{
    Node* newNode = new Node(value);
    newNode->next = head; // attach to list
    head = newNode;
    if (tail == nullptr) { // empty list
        tail = newNode; // only node is both head and tail
    }
}

void LinkedList::insert_back(int value)
{
    Node* newNode = new Node(value);
    if (tail != nullptr)
        tail->next = newNode; // attach to list
    tail = newNode;
    if (head == nullptr) { // empty list
        head = newNode; // only node is both head and tail
    }
}

bool LinkedList::insert_after (int after_val, int insert_val)
{
    if (is_empty())
        return false;
    Node * curr = head;
    while (curr != nullptr) {
        if (curr->value == after_val) {
            Node* new_node = new Node(insert_val);
            new_node->next = curr->next;
            curr->next = new_node;
            if (curr == tail)
                tail = new_node;
            return true;
        }
        curr = curr->next;
    }
    return false;
}

void LinkedList::clear()
{
    Node* current = head;
    while (current != nullptr) {
        Node* deleteNode = current;
        current = current->next;
        delete deleteNode;
    }
    head = nullptr;
    tail = nullptr;
}

void LinkedList::print(char c, ostream& os) {
    Node* cur = head;
    if (head != nullptr) {
        while (cur != nullptr) {
            os << *cur;
            if (cur != tail)
                os << c;
            if (cur == tail)
                os << endl;
            cur = cur->next;
        }
    }
    else {
        os << "<Empty List>" << c;
    }
}

void LinkedList::print_head(char c, ostream& os) const
{
    if (head != nullptr) {
        os << head->value << c;
    } else {
        os << "<Empty List>" << c;
    }
}

void LinkedList::print_tail(char c, ostream& os) const
{
    if (head != nullptr) {
        os << tail->value << c;
    } else {
        os << "<Empty List>" << c;
    }
}

ostream& operator<<(ostream& os, const LinkedList& ll)
{
    os << ll.get_name() << " {";
    Node* current = ll.get_head();
    if (current == nullptr) {
        os << " <Empty List>";
    }
    while (current != nullptr) {
        if (current != ll.get_head())
            cout << ",";
        cout << " " << current->value;
        current = current->next;
    }
    cout << " }";
    return os;
}

void LinkedList::makeTestList()
{
    // not the real way to create a list, but it will give us something to
    //  use for testing parts until we learn how.
    Node* newNode = new Node(7);
    head = newNode;
    newNode = new Node(3);
    head->next = newNode;
    newNode = new Node(12);
    head->next->next = newNode;
    tail = newNode;
}

void LinkedList::log(const string& what) const
{
    std::cout << "[" << this << "] " << what << std::endl;
}

