/**
 * @file insertion.cpp
 * @author Arjun Singh
 * @brief Implementation of insertion sort algorithm for List ADT
 *
 * This file contains the concrete implementation of the insertion sort algorithm.
 * The implementation works by building a sorted portion of the list one element
 * at a time, inserting each new element into its correct position.
 */

// Internal dependencies
#include <dsalgos/list/list.hpp>
#include <dsalgos/sorting/insertion.hpp>

namespace dsalgos {

namespace sorting {

/* -------------------------------------------------------------------------- */
/*                  Insertion Sort - Ascending Implementation                 */
/* -------------------------------------------------------------------------- */

/**
 * Implementation of insertion sort in ascending order
 *
 * Algorithm:
 * 1. Start with the second element (first is trivially sorted)
 * 2. For each element, save its value as the key
 * 3. Compare key with elements in the sorted portion (to its left)
 * 4. Shift larger elements one position to the right
 * 5. Insert key at the correct position
 */
void insertionSort(List& list) {
    int n = list.size();

    // Empty or single element lists are already sorted
    if (n <= 1) {
        return;
    }

    // Start from second element (index 1)
    for (int i = 1; i < n; i++) {
        int key = list.get(i);
        int j   = i - 1;

        // Move elements greater than key one position ahead
        while (j >= 0 && list.get(j) > key) {
            list.set(j + 1, list.get(j));
            j--;
        }

        // Insert key at correct position
        list.set(j + 1, key);
    }
}

/* -------------------------------------------------------------------------- */
/*                 Insertion Sort - Descending Implementation                 */
/* -------------------------------------------------------------------------- */

/**
 * Implementation of insertion sort in descending order
 *
 * Same algorithm as ascending but with reversed comparison
 */
void insertionSortDescending(List& list) {
    int n = list.size();

    if (n <= 1) {
        return;
    }

    for (int i = 1; i < n; i++) {
        int key = list.get(i);
        int j   = i - 1;

        // Reversed comparison for descending order
        while (j >= 0 && list.get(j) < key) {
            list.set(j + 1, list.get(j));
            j--;
        }

        list.set(j + 1, key);
    }
}

} // namespace sorting

} // namespace dsalgos
