/**
 * @file quick.cpp
 * @author Arjun Singh
 * @brief Implementation of quick sort algorithm for List ADT
 *
 * This file contains the concrete implementation of the quick sort algorithm.
 * The implementation uses a divide-and-conquer approach with partitioning
 * around a pivot element.
 */

// Internal dependencies
#include <dsalgos/list/list.hpp>
#include <dsalgos/sorting/quick.hpp>

namespace dsalgos {

namespace sorting {

/* -------------------------------------------------------------------------- */
/*                           Helper Functions                                 */
/* -------------------------------------------------------------------------- */

/**
 * Partition helper for ascending quick sort
 *
 * Chooses the last element as pivot and rearranges elements so that:
 * - Elements smaller than pivot are on the left
 * - Elements greater than pivot are on the right
 *
 * @param list The list to partition
 * @param low Starting index of partition range
 * @param high Ending index of partition range
 * @return The final position of the pivot element
 */
int partition(List& list, int low, int high) {
    int pivot = list.get(high); // Choose last element as pivot
    int i     = low - 1;        // Index of smaller element

    for (int j = low; j < high; j++) {
        // If current element is smaller than or equal to pivot
        if (list.get(j) <= pivot) {
            i++;
            list.swap(i, j);
        }
    }

    // Place pivot in correct position
    list.swap(i + 1, high);
    return i + 1;
}

/**
 * Partition helper for descending quick sort
 */
int partitionDescending(List& list, int low, int high) {
    int pivot = list.get(high);
    int i     = low - 1;

    for (int j = low; j < high; j++) {
        // Reversed comparison for descending order
        if (list.get(j) >= pivot) {
            i++;
            list.swap(i, j);
        }
    }

    list.swap(i + 1, high);
    return i + 1;
}

/**
 * Recursive quick sort helper for ascending order
 */
void quickSortHelper(List& list, int low, int high) {
    if (low < high) {
        // Partition the list and get pivot position
        int pivotIndex = partition(list, low, high);

        // Recursively sort elements before and after partition
        quickSortHelper(list, low, pivotIndex - 1);
        quickSortHelper(list, pivotIndex + 1, high);
    }
}

/**
 * Recursive quick sort helper for descending order
 */
void quickSortHelperDescending(List& list, int low, int high) {
    if (low < high) {
        int pivotIndex = partitionDescending(list, low, high);
        quickSortHelperDescending(list, low, pivotIndex - 1);
        quickSortHelperDescending(list, pivotIndex + 1, high);
    }
}

/* -------------------------------------------------------------------------- */
/*                    Quick Sort - Ascending Implementation                   */
/* -------------------------------------------------------------------------- */

/**
 * Implementation of quick sort in ascending order
 *
 * Algorithm:
 * 1. Choose a pivot element (last element)
 * 2. Partition array around pivot
 * 3. Recursively sort left and right partitions
 * 4. Base case: arrays of size 0 or 1 are already sorted
 */
void quickSort(List& list) {
    int n = list.size();

    // Empty or single element lists are already sorted
    if (n <= 1) {
        return;
    }

    // Call recursive helper
    quickSortHelper(list, 0, n - 1);
}

/* -------------------------------------------------------------------------- */
/*                   Quick Sort - Descending Implementation                   */
/* -------------------------------------------------------------------------- */

/**
 * Implementation of quick sort in descending order
 *
 * Same algorithm as ascending but with reversed comparisons in partition
 */
void quickSortDescending(List& list) {
    int n = list.size();

    if (n <= 1) {
        return;
    }

    quickSortHelperDescending(list, 0, n - 1);
}

} // namespace sorting

} // namespace dsalgos
