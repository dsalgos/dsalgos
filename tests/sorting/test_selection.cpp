/**
 * @file test_selection.cpp
 * @brief Unit tests for Selection Sort algorithm
 *
 * This file contains tests for the selection sort implementation
 * using Google Test framework. Tests cover both ascending and
 * descending sorting with various input cases.
 */

// Headers to be tested
#include <dsalgos/list/list.hpp>
#include <dsalgos/sorting/selection.hpp>

// External dependencies
#include <gtest/gtest.h>

using namespace dsalgos;
using namespace dsalgos::sorting;

/**
 * @brief Test fixture for Selection Sort tests
 *
 * Provides a clean List instance for each test
 */
class SelectionSortTest : public ::testing::Test {
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

TEST_F(SelectionSortTest, SortEmptyList) {
    selectionSort(*list);
    EXPECT_TRUE(list->isEmpty());
    EXPECT_EQ(list->size(), 0);
}

TEST_F(SelectionSortTest, SortSingleElement) {
    list->insert(42);
    selectionSort(*list);

    EXPECT_EQ(list->size(), 1);
    EXPECT_EQ(list->get(0), 42);
}

TEST_F(SelectionSortTest, SortAlreadySorted) {
    list->insert(10);
    list->insert(20);
    list->insert(30);
    list->insert(40);

    selectionSort(*list);

    EXPECT_EQ(list->size(), 4);
    EXPECT_TRUE(isSortedAscending());
    EXPECT_EQ(list->get(0), 10);
    EXPECT_EQ(list->get(3), 40);
}

TEST_F(SelectionSortTest, SortReverseSorted) {
    list->insert(40);
    list->insert(30);
    list->insert(20);
    list->insert(10);

    selectionSort(*list);

    EXPECT_EQ(list->size(), 4);
    EXPECT_TRUE(isSortedAscending());
    EXPECT_EQ(list->get(0), 10);
    EXPECT_EQ(list->get(1), 20);
    EXPECT_EQ(list->get(2), 30);
    EXPECT_EQ(list->get(3), 40);
}

TEST_F(SelectionSortTest, SortRandomOrder) {
    list->insert(64);
    list->insert(34);
    list->insert(25);
    list->insert(12);
    list->insert(22);
    list->insert(11);
    list->insert(90);

    selectionSort(*list);

    EXPECT_EQ(list->size(), 7);
    EXPECT_TRUE(isSortedAscending());
    EXPECT_EQ(list->get(0), 11);
    EXPECT_EQ(list->get(6), 90);
}

TEST_F(SelectionSortTest, SortWithDuplicates) {
    list->insert(20);
    list->insert(10);
    list->insert(20);
    list->insert(30);
    list->insert(10);

    selectionSort(*list);

    EXPECT_EQ(list->size(), 5);
    EXPECT_TRUE(isSortedAscending());
    EXPECT_EQ(list->get(0), 10);
    EXPECT_EQ(list->get(1), 10);
    EXPECT_EQ(list->get(4), 30);
}

TEST_F(SelectionSortTest, SortNegativeNumbers) {
    list->insert(-5);
    list->insert(-1);
    list->insert(-10);
    list->insert(-3);

    selectionSort(*list);

    EXPECT_EQ(list->size(), 4);
    EXPECT_TRUE(isSortedAscending());
    EXPECT_EQ(list->get(0), -10);
    EXPECT_EQ(list->get(3), -1);
}

TEST_F(SelectionSortTest, SortMixedPositiveNegative) {
    list->insert(5);
    list->insert(-2);
    list->insert(10);
    list->insert(-8);
    list->insert(0);

    selectionSort(*list);

    EXPECT_EQ(list->size(), 5);
    EXPECT_TRUE(isSortedAscending());
    EXPECT_EQ(list->get(0), -8);
    EXPECT_EQ(list->get(2), 0);
    EXPECT_EQ(list->get(4), 10);
}

TEST_F(SelectionSortTest, SortAllSameElements) {
    list->insert(5);
    list->insert(5);
    list->insert(5);
    list->insert(5);

    selectionSort(*list);

    EXPECT_EQ(list->size(), 4);
    EXPECT_TRUE(isSortedAscending());
    for (int i = 0; i < 4; i++) {
        EXPECT_EQ(list->get(i), 5);
    }
}

/* -------------------------------------------------------------------------- */
/*                      Descending Sort Tests                                 */
/* -------------------------------------------------------------------------- */

TEST_F(SelectionSortTest, SortDescendingEmptyList) {
    selectionSortDescending(*list);
    EXPECT_TRUE(list->isEmpty());
}

TEST_F(SelectionSortTest, SortDescendingSingleElement) {
    list->insert(42);
    selectionSortDescending(*list);

    EXPECT_EQ(list->size(), 1);
    EXPECT_EQ(list->get(0), 42);
}

TEST_F(SelectionSortTest, SortDescendingAlreadySorted) {
    list->insert(40);
    list->insert(30);
    list->insert(20);
    list->insert(10);

    selectionSortDescending(*list);

    EXPECT_EQ(list->size(), 4);
    EXPECT_TRUE(isSortedDescending());
    EXPECT_EQ(list->get(0), 40);
    EXPECT_EQ(list->get(3), 10);
}

TEST_F(SelectionSortTest, SortDescendingReverseSorted) {
    list->insert(10);
    list->insert(20);
    list->insert(30);
    list->insert(40);

    selectionSortDescending(*list);

    EXPECT_EQ(list->size(), 4);
    EXPECT_TRUE(isSortedDescending());
    EXPECT_EQ(list->get(0), 40);
    EXPECT_EQ(list->get(3), 10);
}

TEST_F(SelectionSortTest, SortDescendingRandomOrder) {
    list->insert(64);
    list->insert(34);
    list->insert(25);
    list->insert(12);
    list->insert(90);

    selectionSortDescending(*list);

    EXPECT_EQ(list->size(), 5);
    EXPECT_TRUE(isSortedDescending());
    EXPECT_EQ(list->get(0), 90);
    EXPECT_EQ(list->get(4), 12);
}

TEST_F(SelectionSortTest, SortDescendingWithDuplicates) {
    list->insert(20);
    list->insert(10);
    list->insert(20);
    list->insert(30);

    selectionSortDescending(*list);

    EXPECT_EQ(list->size(), 4);
    EXPECT_TRUE(isSortedDescending());
    EXPECT_EQ(list->get(0), 30);
    EXPECT_EQ(list->get(3), 10);
}

TEST_F(SelectionSortTest, SortDescendingMixedPositiveNegative) {
    list->insert(5);
    list->insert(-2);
    list->insert(10);
    list->insert(0);

    selectionSortDescending(*list);

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
