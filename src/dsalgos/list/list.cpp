/**
 * @file List.cpp
 * @author Arjun Singh
 * @brief Implementation of the List ADT using delegation to LinkedList
 *
 * This file contains the concrete implementation of the List ADT.
 * Instead of implementing linked list operations directly, this
 * implementation delegates all operations to an underlying LinkedList
 * data structure, demonstrating the separation between ADT and implementation.
 */

// External dependencies
#include <iostream>

// Internal dependencies
#include <dsalgos/list/linkedlist.hpp>
#include <dsalgos/list/list.hpp>

namespace dsalgos {

/* -------------------------------------------------------------------------- */
/*                    List ADT Implementation via Delegation                  */
/* -------------------------------------------------------------------------- */

// Constructor - creates underlying LinkedList
List::List() : linkedList(new LinkedList()) {}

// Destructor - frees underlying LinkedList
List::~List() {
    delete linkedList;
}

/* -------------------------------------------------------------------------- */
/*                       Core ADT Operations - Implementation                 */
/* -------------------------------------------------------------------------- */

// Insert delegates to LinkedList::insertBack
void List::insert(int value) {
    linkedList->insertBack(value);
}

// Remove delegates to LinkedList::deleteValue
bool List::remove(int value) {
    return linkedList->deleteValue(value);
}

/* -------------------------------------------------------------------------- */
/*                      Query ADT Operations - Implementation                 */
/* -------------------------------------------------------------------------- */

// Contains checks if value exists using LinkedList::search
bool List::contains(int value) const {
    return linkedList->search(value) != -1;
}

// Size delegates to LinkedList::getSize
int List::size() const {
    return linkedList->getSize();
}

// isEmpty delegates to LinkedList::isEmpty
bool List::isEmpty() const {
    return linkedList->isEmpty();
}

// Print formats output as [a, b, c] instead of a -> b -> c
void List::print() const {
    if (linkedList->isEmpty()) {
        std::cout << "[]" << std::endl;
        return;
    }

    std::cout << "[";
    int listSize = linkedList->getSize();
    for (int i = 0; i < listSize; i++) {
        std::cout << linkedList->get(i);
        if (i < listSize - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

// Clear delegates to LinkedList::clear
void List::clear() {
    linkedList->clear();
}

/* -------------------------------------------------------------------------- */
/*                   Helper Methods for Sorting - Implementation              */
/* -------------------------------------------------------------------------- */

// Get element at index delegates to LinkedList::get
int List::get(int index) const {
    return linkedList->get(index);
}

// Set element at index by deleting and inserting
void List::set(int index, int value) {
    linkedList->deleteAt(index);
    linkedList->insertAt(value, index);
}

// Swap two elements by getting their values and setting them reversed
void List::swap(int i, int j) {
    if (i == j)
        return;

    int temp_i = linkedList->get(i);
    int temp_j = linkedList->get(j);

    // Set in reverse order
    linkedList->deleteAt(i);
    linkedList->insertAt(temp_j, i);

    linkedList->deleteAt(j);
    linkedList->insertAt(temp_i, j);
}

} // namespace dsalgos