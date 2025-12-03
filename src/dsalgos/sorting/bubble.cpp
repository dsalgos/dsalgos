/**
 * @file bubble.cpp
 * @author Arjun Singh
 * @brief Implementation of bubble sort algorithm for List ADT
 *
 * This file contains the concrete implementation of the bubble sort algorithm.
 * The implementation works by repeatedly comparing adjacent elements and
 * swapping them if they are in the wrong order, until the entire list is sorted.
 */

// Internal dependencies
#include <dsalgos/list/list.hpp>
#include <dsalgos/sorting/bubble.hpp>

namespace dsalgos {

namespace sorting {

/* -------------------------------------------------------------------------- */
/*                    Bubble Sort - Ascending Implementation                  */
/* -------------------------------------------------------------------------- */

/**
 * Implementation of bubble sort in ascending order
 *
 * Algorithm:
 * 1. For each pass through the list
 * 2. Compare each pair of adjacent elements
 * 3. Swap them if they are in wrong order (current > next)
 * 4. Optimize by reducing range after each pass (largest element bubbles to end)
 * 5. Stop early if no swaps occur (list is sorted)
 */
void bubbleSort(List& list) {
    int n = list.size();

    // Empty or single element lists are already sorted
    if (n <= 1) {
        return;
    }

    // Perform bubble sort
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;

        // Last i elements are already in place
        for (int j = 0; j < n - i - 1; j++) {
            // Compare adjacent elements
            if (list.get(j) > list.get(j + 1)) {
                // Swap if they are in wrong order
                list.swap(j, j + 1);
                swapped = true;
            }
        }

        // If no swaps occurred, list is sorted
        if (!swapped) {
            break;
        }
    }
}

/* -------------------------------------------------------------------------- */
/*                   Bubble Sort - Descending Implementation                  */
/* -------------------------------------------------------------------------- */

/**
 * Implementation of bubble sort in descending order
 *
 * Same algorithm as ascending sort but with reversed comparison
 */
void bubbleSortDescending(List& list) {
    int n = list.size();

    if (n <= 1) {
        return;
    }

    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            // Reversed comparison for descending order
            if (list.get(j) < list.get(j + 1)) {
                list.swap(j, j + 1);
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
    }
}

} // namespace sorting

} // namespace dsalgos
