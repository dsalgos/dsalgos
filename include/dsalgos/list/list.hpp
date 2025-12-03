/**
 * @file list.hpp
 * @author Arjun Singh
 * @brief Header file for a list implementation
 */

#ifndef LIST_H
#define LIST_H

// Internal dependencies
#include <dsalgos/list/linkedlist.hpp>

namespace dsalgos {

/**
 * @brief List Abstract Data Type (ADT)
 *
 * This ADT defines the interface for a list of integers.
 * The underlying implementation uses a linked list data structure,
 * but this detail is completely hidden from the user.
 *
 * A List is an ordered collection of elements where:
 * - Elements can be inserted and removed
 * - Elements can be searched
 * - The list maintains the order of insertion
 */
class List {
  private:
    LinkedList* linkedList; ///< Pointer to underlying linked list implementation

  public:
    /**
     * @brief Default constructor
     *
     * Creates an empty list
     *
     * Postconditions: List is empty with size 0
     */
    List();

    /**
     * @brief Destructor
     *
     * Frees all allocated memory and destroys the list
     *
     * Postconditions: All elements are removed and memory is freed
     */
    ~List();

    /* -------------------------------------------------------------------------- */
    /*                            Core ADT Operations                             */
    /* -------------------------------------------------------------------------- */

    /**
     * @brief Insert a value into the list
     * @param value The integer value to insert
     *
     * Inserts the value at the end of the list
     *
     * @note Side Effect(s): List size increases by 1, value is added at the end
     * @note Time complexity: O(n)
     */
    void insert(int value);

    /**
     * @brief Remove the first occurrence of a value from the list
     * @param value The value to remove
     * @return true if the value was found and removed, false otherwise
     *
     * @note Side Effect(s): If found, list size decreases by 1 and first occurrence is removed
     * @note Time complexity: O(n)
     */
    bool remove(int value);

    /**
     * @brief Search for a value in the list
     * @param value The value to search for
     * @return true if the value exists in the list, false otherwise
     *
     * @note Side Effect(s): List remains unchanged
     * @note Time complexity: O(n)
     */
    bool contains(int value) const;

    /* -------------------------------------------------------------------------- */
    /*                           Query ADT Operations                             */
    /* -------------------------------------------------------------------------- */

    /**
     * @brief Get the number of elements in the list
     * @return The size of the list
     *
     * @note Side Effect(s): List remains unchanged
     * @note Time complexity: O(1)
     */
    int size() const;

    /**
     * @brief Check if the list is empty
     * @return true if the list has no elements, false otherwise
     *
     * @note Side Effect(s): List remains unchanged
     * @note Time complexity: O(1)
     */
    bool isEmpty() const;

    /**
     * @brief Display all elements in the list
     *
     * Prints all elements to standard output in the format: [element1, element2, ...]
     * This is a utility operation for debugging and visualization
     *
     * @note Side Effect(s): List remains unchanged, elements are printed to stdout
     * @note Time complexity: O(n)
     */
    void print() const;

    /**
     * @brief Remove all elements from the list
     *
     * Clears the entire list, removing all elements and freeing memory
     *
     * @note Side Effect(s): List is empty with size 0, all memory is freed
     * @note Time complexity: O(n)
     */
    void clear();

    /* -------------------------------------------------------------------------- */
    /*                      Helper Methods for Sorting                            */
    /* -------------------------------------------------------------------------- */

    /**
     * @brief Get element at a specific position (for internal/friend use)
     * @param index The position of the element (0-indexed)
     * @return The value at the specified position
     *
     * @note Side Effect(s): List remains unchanged
     * @note Time complexity: O(n)
     */
    int get(int index) const;

    /**
     * @brief Set element at a specific position (for internal/friend use)
     * @param index The position of the element (0-indexed)
     * @param value The new value to set
     *
     * @note Side Effect(s): Element at index is updated
     * @note Time complexity: O(n)
     */
    void set(int index, int value);

    /**
     * @brief Swap two elements at given positions
     * @param i First position
     * @param j Second position
     *
     * @note Side Effect(s): Elements at positions i and j are swapped
     * @note Time complexity: O(n)
     */
    void swap(int i, int j);
};

} // namespace dsalgos

#endif // LIST_H
