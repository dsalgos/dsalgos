/**
 * @file LinkedList.cpp
 * @author Arjun Singh
 * @brief Implementation of a singly linked list (dsalgos::LinkedList).
 *
 * This file provides the concrete implementation of the LinkedList class declared
 * in dsalgos/list/linkedlist.hpp. It implements construction, destruction,
 * copy semantics (copy constructor and copy assignment), memory-managed node
 * operations, and typical list operations:
 *
 * - insertFront, insertBack, insertAt
 * - deleteFront, deleteBack, deleteAt, deleteValue
 * - clear, reverse, display
 * - search, get, front, back, getMiddle, hasCycle
 * - isEmpty, getSize
 *
 * The list is implemented as a singly linked list using raw pointers; the class
 * owns its nodes and is responsible for allocating and freeing them. All
 * methods operate within the dsalgos namespace.
 */

// Header file to be implemented
#include <dsalgos/list/linkedlist.hpp>

namespace dsalgos {

// Constructor
LinkedList::LinkedList() : head(nullptr), tail(nullptr), size(0) {}

// Destructor
LinkedList::~LinkedList() {
    clear();
}

// Copy constructor
LinkedList::LinkedList(const LinkedList& other) : head(nullptr), tail(nullptr), size(0) {
    Node* current = other.head;
    while (current != nullptr) {
        insertBack(current->data);
        current = current->next;
    }
}

// Copy assignment operator
LinkedList& LinkedList::operator=(const LinkedList& other) {
    if (this != &other) {
        clear();
        Node* current = other.head;
        while (current != nullptr) {
            insertBack(current->data);
            current = current->next;
        }
    }
    return *this;
}

// Insert at front
void LinkedList::insertFront(int value) {
    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head          = newNode;
    }
    size++;
}

// Insert at back
void LinkedList::insertBack(int value) {
    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail       = newNode;
    }
    size++;
}

// Insert at specific position
void LinkedList::insertAt(int value, int position) {
    if (position < 0 || position > size) {
        throw std::out_of_range("Position out of range");
    }

    if (position == 0) {
        insertFront(value);
        return;
    }

    if (position == size) {
        insertBack(value);
        return;
    }

    Node* newNode = new Node(value);
    Node* current = head;

    for (int i = 0; i < position - 1; i++) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
    size++;
}

// Delete front element
void LinkedList::deleteFront() {
    if (head == nullptr) {
        throw std::runtime_error("Cannot delete from empty list");
    }

    Node* temp = head;
    head       = head->next;
    delete temp;
    size--;

    if (head == nullptr) {
        tail = nullptr;
    }
}

// Delete back element
void LinkedList::deleteBack() {
    if (head == nullptr) {
        throw std::runtime_error("Cannot delete from empty list");
    }

    if (head == tail) {
        delete head;
        head = tail = nullptr;
        size--;
        return;
    }

    Node* current = head;
    while (current->next != tail) {
        current = current->next;
    }

    delete tail;
    tail       = current;
    tail->next = nullptr;
    size--;
}

// Delete at specific position
void LinkedList::deleteAt(int position) {
    if (position < 0 || position >= size) {
        throw std::out_of_range("Position out of range");
    }

    if (position == 0) {
        deleteFront();
        return;
    }

    Node* current = head;
    for (int i = 0; i < position - 1; i++) {
        current = current->next;
    }

    Node* temp    = current->next;
    current->next = temp->next;

    if (temp == tail) {
        tail = current;
    }

    delete temp;
    size--;
}

// Delete first occurrence of a value
bool LinkedList::deleteValue(int value) {
    if (head == nullptr) {
        return false;
    }

    if (head->data == value) {
        deleteFront();
        return true;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->data != value) {
        current = current->next;
    }

    if (current->next == nullptr) {
        return false;
    }

    Node* temp    = current->next;
    current->next = temp->next;

    if (temp == tail) {
        tail = current;
    }

    delete temp;
    size--;
    return true;
}

// Clear all elements
void LinkedList::clear() {
    while (head != nullptr) {
        Node* temp = head;
        head       = head->next;
        delete temp;
    }
    tail = nullptr;
    size = 0;
}

// Search for a value
int LinkedList::search(int value) const {
    Node* current  = head;
    int   position = 0;

    while (current != nullptr) {
        if (current->data == value) {
            return position;
        }
        current = current->next;
        position++;
    }

    return -1;
}

// Get element at position
int LinkedList::get(int position) const {
    if (position < 0 || position >= size) {
        throw std::out_of_range("Position out of range");
    }

    Node* current = head;
    for (int i = 0; i < position; i++) {
        current = current->next;
    }

    return current->data;
}

// Get first element
int LinkedList::front() const {
    if (head == nullptr) {
        throw std::runtime_error("List is empty");
    }
    return head->data;
}

// Get last element
int LinkedList::back() const {
    if (tail == nullptr) {
        throw std::runtime_error("List is empty");
    }
    return tail->data;
}

// Check if empty
bool LinkedList::isEmpty() const {
    return head == nullptr;
}

// Get size
int LinkedList::getSize() const {
    return size;
}

// Reverse the list
void LinkedList::reverse() {
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    Node* prev    = nullptr;
    Node* current = head;
    Node* next    = nullptr;
    tail          = head;

    while (current != nullptr) {
        next          = current->next;
        current->next = prev;
        prev          = current;
        current       = next;
    }

    head = prev;
}

// Display all elements
void LinkedList::display() const {
    Node* current = head;

    if (current == nullptr) {
        std::cout << "List is empty" << std::endl;
        return;
    }

    while (current != nullptr) {
        std::cout << current->data;
        if (current->next != nullptr) {
            std::cout << " -> ";
        }
        current = current->next;
    }
    std::cout << " -> nullptr" << std::endl;
}

// Get middle element using slow-fast pointer
int LinkedList::getMiddle() const {
    if (head == nullptr) {
        throw std::runtime_error("List is empty");
    }

    Node* slow = head;
    Node* fast = head;

    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;
}

// Check for cycle using Floyd's algorithm
bool LinkedList::hasCycle() const {
    if (head == nullptr || head->next == nullptr) {
        return false;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }

    return false;
}

} // namespace dsalgos