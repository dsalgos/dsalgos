/**
 * @file merge.cpp
 * @author Arjun Singh
 * @brief Implementation of merge sort algorithm for List ADT
 *
 * This file contains the concrete implementation of the merge sort algorithm.
 * The implementation uses a divide-and-conquer approach that recursively
 * divides the list into halves and merges them in sorted order.
 */

// External dependencies
#include <vector>

// Internal dependencies
#include <dsalgos/list/list.hpp>
#include <dsalgos/sorting/merge.hpp>

namespace dsalgos {

namespace sorting {

/* -------------------------------------------------------------------------- */
/*                           Helper Functions                                 */
/* -------------------------------------------------------------------------- */

/**
 * Merge helper for ascending merge sort
 *
 * Merges two sorted portions of the list into a single sorted portion
 *
 * @param list The list containing the portions to merge
 * @param left Start index of first portion
 * @param mid End index of first portion (mid+1 is start of second)
 * @param right End index of second portion
 */
void merge(List& list, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary vectors for left and right portions
    std::vector<int> leftArr(n1);
    std::vector<int> rightArr(n2);

    // Copy data to temporary vectors
    for (int i = 0; i < n1; i++) {
        leftArr[i] = list.get(left + i);
    }
    for (int j = 0; j < n2; j++) {
        rightArr[j] = list.get(mid + 1 + j);
    }

    // Merge the temporary vectors back into list
    int i = 0;    // Initial index of first subarray
    int j = 0;    // Initial index of second subarray
    int k = left; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            list.set(k, leftArr[i]);
            i++;
        } else {
            list.set(k, rightArr[j]);
            j++;
        }
        k++;
    }

    // Copy remaining elements of leftArr, if any
    while (i < n1) {
        list.set(k, leftArr[i]);
        i++;
        k++;
    }

    // Copy remaining elements of rightArr, if any
    while (j < n2) {
        list.set(k, rightArr[j]);
        j++;
        k++;
    }
}

/**
 * Merge helper for descending merge sort
 */
void mergeDescending(List& list, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> leftArr(n1);
    std::vector<int> rightArr(n2);

    for (int i = 0; i < n1; i++) {
        leftArr[i] = list.get(left + i);
    }
    for (int j = 0; j < n2; j++) {
        rightArr[j] = list.get(mid + 1 + j);
    }

    int i = 0, j = 0, k = left;

    // Reversed comparison for descending order
    while (i < n1 && j < n2) {
        if (leftArr[i] >= rightArr[j]) {
            list.set(k, leftArr[i]);
            i++;
        } else {
            list.set(k, rightArr[j]);
            j++;
        }
        k++;
    }

    while (i < n1) {
        list.set(k, leftArr[i]);
        i++;
        k++;
    }

    while (j < n2) {
        list.set(k, rightArr[j]);
        j++;
        k++;
    }
}

/**
 * Recursive merge sort helper for ascending order
 */
void mergeSortHelper(List& list, int left, int right) {
    if (left < right) {
        // Find middle point
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSortHelper(list, left, mid);
        mergeSortHelper(list, mid + 1, right);

        // Merge the sorted halves
        merge(list, left, mid, right);
    }
}

/**
 * Recursive merge sort helper for descending order
 */
void mergeSortHelperDescending(List& list, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortHelperDescending(list, left, mid);
        mergeSortHelperDescending(list, mid + 1, right);
        mergeDescending(list, left, mid, right);
    }
}

/* -------------------------------------------------------------------------- */
/*                    Merge Sort - Ascending Implementation                   */
/* -------------------------------------------------------------------------- */

/**
 * Implementation of merge sort in ascending order
 *
 * Algorithm:
 * 1. Divide the list into two halves
 * 2. Recursively sort both halves
 * 3. Merge the two sorted halves
 * 4. Base case: lists of size 0 or 1 are already sorted
 */
void mergeSort(List& list) {
    int n = list.size();

    // Empty or single element lists are already sorted
    if (n <= 1) {
        return;
    }

    // Call recursive helper
    mergeSortHelper(list, 0, n - 1);
}

/* -------------------------------------------------------------------------- */
/*                   Merge Sort - Descending Implementation                   */
/* -------------------------------------------------------------------------- */

/**
 * Implementation of merge sort in descending order
 *
 * Same algorithm as ascending but with reversed comparisons in merge
 */
void mergeSortDescending(List& list) {
    int n = list.size();

    if (n <= 1) {
        return;
    }

    mergeSortHelperDescending(list, 0, n - 1);
}

} // namespace sorting

} // namespace dsalgos
