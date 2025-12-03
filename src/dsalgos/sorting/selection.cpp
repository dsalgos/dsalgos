/**
 * @file selection.cpp
 * @author Arjun Singh
 * @brief Implementation of selection sort algorithm for List ADT
 *
 * This file contains the concrete implementation of the selection sort algorithm.
 * The implementation works by repeatedly finding the minimum element from the
 * unsorted portion and placing it at the beginning of the unsorted portion.
 */

// Internal dependencies
#include <dsalgos/list/list.hpp>
#include <dsalgos/sorting/selection.hpp>

namespace dsalgos {

namespace sorting {

/* -------------------------------------------------------------------------- */
/*                  Selection Sort - Ascending Implementation                 */
/* -------------------------------------------------------------------------- */

/**
 * Implementation of selection sort in ascending order
 *
 * Algorithm:
 * 1. Divide list into sorted (left) and unsorted (right) portions
 * 2. Find the minimum element in the unsorted portion
 * 3. Swap it with the first element of unsorted portion
 * 4. Move the boundary between sorted and unsorted one position right
 * 5. Repeat until entire list is sorted
 */
void selectionSort(List& list) {
    int n = list.size();

    // Empty or single element lists are already sorted
    if (n <= 1) {
        return;
    }

    // Iterate through each position
    for (int i = 0; i < n - 1; i++) {
        // Find minimum element in unsorted portion
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (list.get(j) < list.get(minIndex)) {
                minIndex = j;
            }
        }

        // Swap minimum element with first unsorted element
        if (minIndex != i) {
            list.swap(i, minIndex);
        }
    }
}

/* -------------------------------------------------------------------------- */
/*                 Selection Sort - Descending Implementation                 */
/* -------------------------------------------------------------------------- */

/**
 * Implementation of selection sort in descending order
 *
 * Same algorithm as ascending but finds maximum instead of minimum
 */
void selectionSortDescending(List& list) {
    int n = list.size();

    if (n <= 1) {
        return;
    }

    for (int i = 0; i < n - 1; i++) {
        // Find maximum element in unsorted portion
        int maxIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (list.get(j) > list.get(maxIndex)) {
                maxIndex = j;
            }
        }

        // Swap maximum element with first unsorted element
        if (maxIndex != i) {
            list.swap(i, maxIndex);
        }
    }
}

} // namespace sorting

} // namespace dsalgos
