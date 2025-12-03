/**
 * @file bubble.hpp
 * @author Arjun Singh
 * @brief Header file for bubble sort implementation
 */

#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

// Internal dependencies
#include <dsalgos/list/list.hpp>

namespace dsalgos {

/**
 * @brief Bubble Sort Algorithm
 *
 * This namespace provides sorting functionality using the bubble sort algorithm.
 * Bubble sort is a simple comparison-based sorting algorithm that repeatedly
 * steps through the list, compares adjacent elements, and swaps them if they
 * are in the wrong order.
 *
 * The algorithm gets its name because smaller elements "bubble" to the top
 * of the list (beginning) with each iteration.
 */
namespace sorting {

/**
 * @brief Sort a list using the bubble sort algorithm
 * @param list Reference to the List object to be sorted
 *
 * Sorts the list in ascending order using the bubble sort algorithm.
 * The sort is performed in-place by repeatedly comparing and swapping
 * adjacent elements.
 *
 * Algorithm details:
 * - Compares each pair of adjacent items
 * - Swaps them if they are in the wrong order
 * - Repeats until no more swaps are needed
 *
 * @note Side Effect(s): The input list is modified and sorted in ascending order
 * @note Time complexity: O(n^2) worst and average case, O(n) best case (already sorted)
 * @note Space complexity: O(1) - sorts in place
 * @note Stability: Stable sort (maintains relative order of equal elements)
 */
void bubbleSort(List& list);

/**
 * @brief Sort a list in descending order using the bubble sort algorithm
 * @param list Reference to the List object to be sorted
 *
 * Sorts the list in descending order using the bubble sort algorithm.
 * Similar to bubbleSort() but arranges elements from largest to smallest.
 *
 * @note Side Effect(s): The input list is modified and sorted in descending order
 * @note Time complexity: O(n^2) worst and average case, O(n) best case
 * @note Space complexity: O(1) - sorts in place
 * @note Stability: Stable sort (maintains relative order of equal elements)
 */
void bubbleSortDescending(List& list);

} // namespace sorting

} // namespace dsalgos

#endif // BUBBLE_SORT_H
