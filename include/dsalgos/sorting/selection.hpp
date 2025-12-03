/**
 * @file selection.hpp
 * @author Arjun Singh
 * @brief Header file for selection sort implementation
 */

#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

// Internal dependencies
#include <dsalgos/list/list.hpp>

namespace dsalgos {

namespace sorting {

/**
 * @brief Sort a list using the selection sort algorithm
 * @param list Reference to the List object to be sorted
 *
 * Sorts the list in ascending order using the selection sort algorithm.
 * Selection sort divides the list into sorted and unsorted regions, and
 * repeatedly selects the smallest element from the unsorted region and
 * moves it to the end of the sorted region.
 *
 * Algorithm details:
 * - Finds the minimum element in the unsorted portion
 * - Swaps it with the first element of the unsorted portion
 * - Moves the boundary between sorted and unsorted regions one position right
 * - Repeats until the entire list is sorted
 *
 * @note Side Effect(s): The input list is modified and sorted in ascending order
 * @note Time complexity: O(n²) for all cases (best, average, and worst)
 * @note Space complexity: O(1) - sorts in place
 * @note Stability: Unstable sort (may change relative order of equal elements)
 */
void selectionSort(List& list);

/**
 * @brief Sort a list in descending order using the selection sort algorithm
 * @param list Reference to the List object to be sorted
 *
 * Sorts the list in descending order using the selection sort algorithm.
 * Similar to selectionSort() but arranges elements from largest to smallest.
 *
 * @note Side Effect(s): The input list is modified and sorted in descending order
 * @note Time complexity: O(n²) for all cases
 * @note Space complexity: O(1) - sorts in place
 * @note Stability: Unstable sort (may change relative order of equal elements)
 */
void selectionSortDescending(List& list);

} // namespace sorting

} // namespace dsalgos

#endif // SELECTION_SORT_H
