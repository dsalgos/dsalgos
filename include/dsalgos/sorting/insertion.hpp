/**
 * @file insertion.hpp
 * @author Arjun Singh
 * @brief Header file for insertion sort implementation
 */

#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

// Internal dependencies
#include <dsalgos/list/list.hpp>

namespace dsalgos {

namespace sorting {

/**
 * @brief Sort a list using the insertion sort algorithm
 * @param list Reference to the List object to be sorted
 *
 * Sorts the list in ascending order using the insertion sort algorithm.
 * Insertion sort builds the final sorted list one item at a time by
 * repeatedly taking an element and inserting it into its correct position
 * in the already sorted portion of the list.
 *
 * Algorithm details:
 * - Iterates through the list starting from the second element
 * - For each element, compares it with elements in the sorted portion
 * - Shifts larger elements to the right to make space
 * - Inserts the element at its correct position
 *
 * @note Side Effect(s): The input list is modified and sorted in ascending order
 * @note Time complexity: O(n²) worst and average case, O(n) best case (already sorted)
 * @note Space complexity: O(1) - sorts in place
 * @note Stability: Stable sort (maintains relative order of equal elements)
 */
void insertionSort(List& list);

/**
 * @brief Sort a list in descending order using the insertion sort algorithm
 * @param list Reference to the List object to be sorted
 *
 * Sorts the list in descending order using the insertion sort algorithm.
 * Similar to insertionSort() but arranges elements from largest to smallest.
 *
 * @note Side Effect(s): The input list is modified and sorted in descending order
 * @note Time complexity: O(n²) worst and average case, O(n) best case
 * @note Space complexity: O(1) - sorts in place
 * @note Stability: Stable sort (maintains relative order of equal elements)
 */
void insertionSortDescending(List& list);

} // namespace sorting

} // namespace dsalgos

#endif // INSERTION_SORT_H
