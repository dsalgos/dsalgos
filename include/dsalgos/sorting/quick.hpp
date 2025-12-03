/**
 * @file quick.hpp
 * @author Arjun Singh
 * @brief Header file for quick sort implementation
 */

#ifndef QUICK_SORT_H
#define QUICK_SORT_H

// Internal dependencies
#include <dsalgos/list/list.hpp>

namespace dsalgos {

namespace sorting {

/**
 * @brief Sort a list using the quick sort algorithm
 * @param list Reference to the List object to be sorted
 *
 * Sorts the list in ascending order using the quick sort algorithm.
 * Quick sort is a divide-and-conquer algorithm that works by selecting
 * a 'pivot' element and partitioning the other elements into two sub-lists
 * according to whether they are less than or greater than the pivot.
 *
 * Algorithm details:
 * - Selects a pivot element from the list
 * - Partitions the list around the pivot
 * - Recursively applies the same process to sub-lists
 * - Combines the results to produce a sorted list
 *
 * @note Side Effect(s): The input list is modified and sorted in ascending order
 * @note Time complexity: O(n log n) average case, O(n²) worst case (rare with good pivot selection)
 * @note Space complexity: O(log n) due to recursion stack
 * @note Stability: Unstable sort (may change relative order of equal elements)
 */
void quickSort(List& list);

/**
 * @brief Sort a list in descending order using the quick sort algorithm
 * @param list Reference to the List object to be sorted
 *
 * Sorts the list in descending order using the quick sort algorithm.
 * Similar to quickSort() but arranges elements from largest to smallest.
 *
 * @note Side Effect(s): The input list is modified and sorted in descending order
 * @note Time complexity: O(n log n) average case, O(n²) worst case
 * @note Space complexity: O(log n) due to recursion stack
 * @note Stability: Unstable sort (may change relative order of equal elements)
 */
void quickSortDescending(List& list);

} // namespace sorting

} // namespace dsalgos

#endif // QUICK_SORT_H
