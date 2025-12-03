/**
 * @file test_merge.cpp
 * @brief Unit tests for Merge Sort algorithm
 *
 * This file contains tests for the merge sort implementation
 * using Google Test framework. Tests cover both ascending and
 * descending sorting with various input cases.
 */

// Headers to be tested
#include <dsalgos/list/list.hpp>
#include <dsalgos/sorting/merge.hpp>

// External dependencies
#include <gtest/gtest.h>

using namespace dsalgos;
using namespace dsalgos::sorting;

/**
 * @brief Test fixture for Merge Sort tests
 *
 * Provides a clean List instance for each test
 */
class MergeSortTest : public ::testing::Test {
  protected:
    List* list;

    void SetUp() override { list = new List(); }

    void TearDown() override { delete list; }

    /**
     * @brief Helper to verify list is sorted in ascending order
     */
    bool isSortedAscending() {
        int n = list->size();
        for (int i = 0; i < n - 1; i++) {
            if (list->get(i) > list->get(i + 1)) {
                return false;
            }
        }
        return true;
    }

    /**
     * @brief Helper to verify list is sorted in descending order
     */
    bool isSortedDescending() {
        int n = list->size();
        for (int i = 0; i < n - 1; i++) {
            if (list->get(i) < list->get(i + 1)) {
                return false;
            }
        }
        return true;
    }
};

/* -------------------------------------------------------------------------- */
/*                      Ascending Sort Tests                                  */
/* -------------------------------------------------------------------------- */

TEST_F(MergeSortTest, SortEmptyList) {
    mergeSort(*list);
    EXPECT_TRUE(list->isEmpty());
    EXPECT_EQ(list->size(), 0);
}

TEST_F(MergeSortTest, SortSingleElement) {
    list->insert(42);
    mergeSort(*list);

    EXPECT_EQ(list->size(), 1);
    EXPECT_EQ(list->get(0), 42);
}

TEST_F(MergeSortTest, SortAlreadySorted) {
    list->insert(10);
    list->insert(20);
    list->insert(30);
    list->insert(40);

    mergeSort(*list);

    EXPECT_EQ(list->size(), 4);
    EXPECT_TRUE(isSortedAscending());
    EXPECT_EQ(list->get(0), 10);
    EXPECT_EQ(list->get(3), 40);
}

TEST_F(MergeSortTest, SortReverseSorted) {
    list->insert(40);
    list->insert(30);
    list->insert(20);
    list->insert(10);

    mergeSort(*list);

    EXPECT_EQ(list->size(), 4);
    EXPECT_TRUE(isSortedAscending());
    EXPECT_EQ(list->get(0), 10);
    EXPECT_EQ(list->get(1), 20);
    EXPECT_EQ(list->get(2), 30);
    EXPECT_EQ(list->get(3), 40);
}

TEST_F(MergeSortTest, SortRandomOrder) {
    list->insert(64);
    list->insert(34);
    list->insert(25);
    list->insert(12);
    list->insert(22);
    list->insert(11);
    list->insert(90);

    mergeSort(*list);

    EXPECT_EQ(list->size(), 7);
    EXPECT_TRUE(isSortedAscending());
    EXPECT_EQ(list->get(0), 11);
    EXPECT_EQ(list->get(6), 90);
}

TEST_F(MergeSortTest, SortWithDuplicates) {
    list->insert(20);
    list->insert(10);
    list->insert(20);
    list->insert(30);
    list->insert(10);

    mergeSort(*list);

    EXPECT_EQ(list->size(), 5);
    EXPECT_TRUE(isSortedAscending());
    EXPECT_EQ(list->get(0), 10);
    EXPECT_EQ(list->get(1), 10);
    EXPECT_EQ(list->get(4), 30);
}

TEST_F(MergeSortTest, SortNegativeNumbers) {
    list->insert(-5);
    list->insert(-1);
    list->insert(-10);
    list->insert(-3);

    mergeSort(*list);

    EXPECT_EQ(list->size(), 4);
    EXPECT_TRUE(isSortedAscending());
    EXPECT_EQ(list->get(0), -10);
    EXPECT_EQ(list->get(3), -1);
}

TEST_F(MergeSortTest, SortMixedPositiveNegative) {
    list->insert(5);
    list->insert(-2);
    list->insert(10);
    list->insert(-8);
    list->insert(0);

    mergeSort(*list);

    EXPECT_EQ(list->size(), 5);
    EXPECT_TRUE(isSortedAscending());
    EXPECT_EQ(list->get(0), -8);
    EXPECT_EQ(list->get(2), 0);
    EXPECT_EQ(list->get(4), 10);
}

TEST_F(MergeSortTest, SortAllSameElements) {
    list->insert(5);
    list->insert(5);
    list->insert(5);
    list->insert(5);

    mergeSort(*list);

    EXPECT_EQ(list->size(), 4);
    EXPECT_TRUE(isSortedAscending());
    for (int i = 0; i < 4; i++) {
        EXPECT_EQ(list->get(i), 5);
    }
}

/* -------------------------------------------------------------------------- */
/*                      Descending Sort Tests                                 */
/* -------------------------------------------------------------------------- */

TEST_F(MergeSortTest, SortDescendingEmptyList) {
    mergeSortDescending(*list);
    EXPECT_TRUE(list->isEmpty());
}

TEST_F(MergeSortTest, SortDescendingSingleElement) {
    list->insert(42);
    mergeSortDescending(*list);

    EXPECT_EQ(list->size(), 1);
    EXPECT_EQ(list->get(0), 42);
}

TEST_F(MergeSortTest, SortDescendingAlreadySorted) {
    list->insert(40);
    list->insert(30);
    list->insert(20);
    list->insert(10);

    mergeSortDescending(*list);

    EXPECT_EQ(list->size(), 4);
    EXPECT_TRUE(isSortedDescending());
    EXPECT_EQ(list->get(0), 40);
    EXPECT_EQ(list->get(3), 10);
}

TEST_F(MergeSortTest, SortDescendingReverseSorted) {
    list->insert(10);
    list->insert(20);
    list->insert(30);
    list->insert(40);

    mergeSortDescending(*list);

    EXPECT_EQ(list->size(), 4);
    EXPECT_TRUE(isSortedDescending());
    EXPECT_EQ(list->get(0), 40);
    EXPECT_EQ(list->get(3), 10);
}

TEST_F(MergeSortTest, SortDescendingRandomOrder) {
    list->insert(64);
    list->insert(34);
    list->insert(25);
    list->insert(12);
    list->insert(90);

    mergeSortDescending(*list);

    EXPECT_EQ(list->size(), 5);
    EXPECT_TRUE(isSortedDescending());
    EXPECT_EQ(list->get(0), 90);
    EXPECT_EQ(list->get(4), 12);
}

TEST_F(MergeSortTest, SortDescendingWithDuplicates) {
    list->insert(20);
    list->insert(10);
    list->insert(20);
    list->insert(30);

    mergeSortDescending(*list);

    EXPECT_EQ(list->size(), 4);
    EXPECT_TRUE(isSortedDescending());
    EXPECT_EQ(list->get(0), 30);
    EXPECT_EQ(list->get(3), 10);
}

TEST_F(MergeSortTest, SortDescendingMixedPositiveNegative) {
    list->insert(5);
    list->insert(-2);
    list->insert(10);
    list->insert(0);

    mergeSortDescending(*list);

    EXPECT_EQ(list->size(), 4);
    EXPECT_TRUE(isSortedDescending());
    EXPECT_EQ(list->get(0), 10);
    EXPECT_EQ(list->get(3), -2);
}

/* -------------------------------------------------------------------------- */
/*                          Main Function                                     */
/* -------------------------------------------------------------------------- */

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
