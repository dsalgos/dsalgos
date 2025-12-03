/**
 * @file linkedlist.hpp
 * @author Arjun Singh
 * @brief Header file for a singly linked list implementation
 */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// External dependencies
#include <iostream>
#include <stdexcept>

namespace dsalgos {

/**
 * @brief Node structure for the linked list
 *
 * Each node contains an integer value and a pointer to the next node
 */
struct Node {
    int   data; ///< The integer data stored in this node
    Node* next; ///< Pointer to the next node in the list

    /**
     * @brief Constructor for Node
     * @param value The integer value to store in the node
     */
    Node(int value) : data(value), next(nullptr) {}
};

/**
 * @brief A singly linked list implementation for integers
 *
 * This class implements a standard singly linked list with all
 * essential ADT operations including insertion, deletion, traversal,
 * and various utility functions.
 */
class LinkedList {
  private:
    Node* head; ///< Pointer to the first node in the list
    Node* tail; ///< Pointer to the last node in the list
    int   size; ///< Current number of elements in the list

  public:
    /**
     * @brief Default constructor
     *
     * Initializes an empty linked list with head and tail set to nullptr
     * and size set to 0
     */
    LinkedList();

    /**
     * @brief Destructor
     *
     * Frees all memory allocated for the nodes in the list
     */
    ~LinkedList();

    /**
     * @brief Copy constructor
     * @param other The list to copy from
     *
     * Creates a deep copy of another list
     */
    LinkedList(const LinkedList& other);

    /**
     * @brief Copy assignment operator
     * @param other The list to copy from
     * @return Reference to this list
     *
     * Performs deep copy assignment with proper cleanup of existing data
     */
    LinkedList& operator=(const LinkedList& other);

    /* -------------------------------------------------------------------------- */
    /*                            Insertion operations                            */
    /* -------------------------------------------------------------------------- */

    /**
     * @brief Insert an element at the front of the list
     * @param value The integer value to insert
     *
     * Time complexity: O(1)
     */
    void insertFront(int value);

    /**
     * @brief Insert an element at the back of the list
     * @param value The integer value to insert
     *
     * Time complexity: O(1)
     */
    void insertBack(int value);

    /**
     * @brief Insert an element at a specific position
     * @param value The integer value to insert
     * @param position The position at which to insert (0-indexed)
     * @throws std::out_of_range if position is invalid
     *
     * Time complexity: O(n)
     */
    void insertAt(int value, int position);

    /* -------------------------------------------------------------------------- */
    /*                             Deletion operations                            */
    /* -------------------------------------------------------------------------- */

    /**
     * @brief Delete the first element of the list
     * @throws std::runtime_error if the list is empty
     *
     * Time complexity: O(1)
     */
    void deleteFront();

    /**
     * @brief Delete the last element of the list
     * @throws std::runtime_error if the list is empty
     *
     * Time complexity: O(n)
     */
    void deleteBack();

    /**
     * @brief Delete element at a specific position
     * @param position The position of element to delete (0-indexed)
     * @throws std::out_of_range if position is invalid
     *
     * Time complexity: O(n)
     */
    void deleteAt(int position);

    /**
     * @brief Delete first occurrence of a value
     * @param value The value to delete
     * @return true if value was found and deleted, false otherwise
     *
     * Time complexity: O(n)
     */
    bool deleteValue(int value);

    /**
     * @brief Delete all elements from the list
     *
     * Frees all memory and resets the list to empty state
     * Time complexity: O(n)
     */
    void clear();

    /* -------------------------------------------------------------------------- */
    /*                        Search and access operations                        */
    /* -------------------------------------------------------------------------- */

    /**
     * @brief Search for a value in the list
     * @param value The value to search for
     * @return The position of the first occurrence, or -1 if not found
     *
     * Time complexity: O(n)
     */
    int search(int value) const;

    /**
     * @brief Get element at a specific position
     * @param position The position of the element (0-indexed)
     * @return The value at the specified position
     * @throws std::out_of_range if position is invalid
     *
     * Time complexity: O(n)
     */
    int get(int position) const;

    /**
     * @brief Get the first element
     * @return The value of the first element
     * @throws std::runtime_error if the list is empty
     *
     * Time complexity: O(1)
     */
    int front() const;

    /**
     * @brief Get the last element
     * @return The value of the last element
     * @throws std::runtime_error if the list is empty
     *
     * Time complexity: O(1)
     */
    int back() const;

    // Utility operations

    /**
     * @brief Check if the list is empty
     * @return true if the list has no elements, false otherwise
     *
     * Time complexity: O(1)
     */
    bool isEmpty() const;

    /**
     * @brief Get the number of elements in the list
     * @return The size of the list
     *
     * Time complexity: O(1)
     */
    int getSize() const;

    /**
     * @brief Reverse the list in-place
     *
     * Time complexity: O(n)
     */
    void reverse();

    /**
     * @brief Display all elements in the list
     *
     * Prints all elements to stdout in the format: element1 -> element2 -> ... -> nullptr
     * Time complexity: O(n)
     */
    void display() const;

    /**
     * @brief Get the middle element of the list
     * @return The value of the middle element
     * @throws std::runtime_error if the list is empty
     *
     * Uses the slow-fast pointer technique
     * Time complexity: O(n)
     */
    int getMiddle() const;

    /**
     * @brief Check if the list contains a cycle
     * @return true if a cycle exists, false otherwise
     *
     * Uses Floyd's cycle detection algorithm
     * Time complexity: O(n)
     */
    bool hasCycle() const;
};

} // namespace dsalgos

#endif // LINKED_LIST_H