/**
 * @file merge.hpp
 * @author Arjun Singh
 * @brief Header file for merge sort implementation
 */

#ifndef MERGE_SORT_H
#define MERGE_SORT_H

// Internal dependencies
#include <dsalgos/list/list.hpp>

namespace dsalgos {

namespace sorting {

/**
 * @brief Sort a list using the merge sort algorithm
 * @param list Reference to the List object to be sorted
 *
 * Sorts the list in ascending order using the merge sort algorithm.
 * Merge sort is a divide-and-conquer algorithm that divides the list
 * into two halves, recursively sorts them, and then merges the sorted
 * halves back together.
 *
 * Algorithm details:
 * - Divides the list into two roughly equal halves
 * - Recursively sorts each half
 * - Merges the two sorted halves into a single sorted list
 * - Base case: lists of size 0 or 1 are already sorted
 *
 * @note Side Effect(s): The input list is modified and sorted in ascending order
 * @note Time complexity: O(n log n) for all cases (best, average, and worst)
 * @note Space complexity: O(n) - requires additional space for merging
 * @note Stability: Stable sort (maintains relative order of equal elements)
 */
void mergeSort(List& list);

/**
 * @brief Sort a list in descending order using the merge sort algorithm
 * @param list Reference to the List object to be sorted
 *
 * Sorts the list in descending order using the merge sort algorithm.
 * Similar to mergeSort() but arranges elements from largest to smallest.
 *
 * @note Side Effect(s): The input list is modified and sorted in descending order
 * @note Time complexity: O(n log n) for all cases
 * @note Space complexity: O(n) - requires additional space for merging
 * @note Stability: Stable sort (maintains relative order of equal elements)
 */
void mergeSortDescending(List& list);

} // namespace sorting

} // namespace dsalgos

#endif // MERGE_SORT_H
