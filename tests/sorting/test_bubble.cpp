/**
 * @file test_bubble.cpp
 * @brief Unit tests for Bubble Sort algorithm
 *
 * This file contains tests for the bubble sort implementation
 * using Google Test framework. Tests cover both ascending and
 * descending sorting with various input cases.
 */

// Headers to be tested
#include <dsalgos/list/list.hpp>
#include <dsalgos/sorting/bubble.hpp>

// External dependencies
#include <gtest/gtest.h>

using namespace dsalgos;
using namespace dsalgos::sorting;

/**
 * @brief Test fixture for Bubble Sort tests
 *
 * Provides a clean List instance for each test
 */
class BubbleSortTest : public ::testing::Test {
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

TEST_F(BubbleSortTest, SortEmptyList) {
    bubbleSort(*list);
    EXPECT_TRUE(list->isEmpty());
    EXPECT_EQ(list->size(), 0);
}

TEST_F(BubbleSortTest, SortSingleElement) {
    list->insert(42);
    bubbleSort(*list);

    EXPECT_EQ(list->size(), 1);
    EXPECT_EQ(list->get(0), 42);
}

TEST_F(BubbleSortTest, SortAlreadySorted) {
    list->insert(10);
    list->insert(20);
    list->insert(30);
    list->insert(40);

    bubbleSort(*list);

    EXPECT_EQ(list->size(), 4);
    EXPECT_TRUE(isSortedAscending());
    EXPECT_EQ(list->get(0), 10);
    EXPECT_EQ(list->get(3), 40);
}

TEST_F(BubbleSortTest, SortReverseSorted) {
    list->insert(40);
    list->insert(30);
    list->insert(20);
    list->insert(10);

    bubbleSort(*list);

    EXPECT_EQ(list->size(), 4);
    EXPECT_TRUE(isSortedAscending());
    EXPECT_EQ(list->get(0), 10);
    EXPECT_EQ(list->get(1), 20);
    EXPECT_EQ(list->get(2), 30);
    EXPECT_EQ(list->get(3), 40);
}

TEST_F(BubbleSortTest, SortRandomOrder) {
    list->insert(64);
    list->insert(34);
    list->insert(25);
    list->insert(12);
    list->insert(22);
    list->insert(11);
    list->insert(90);

    bubbleSort(*list);

    EXPECT_EQ(list->size(), 7);
    EXPECT_TRUE(isSortedAscending());
    EXPECT_EQ(list->get(0), 11);
    EXPECT_EQ(list->get(6), 90);
}

TEST_F(BubbleSortTest, SortWithDuplicates) {
    list->insert(20);
    list->insert(10);
    list->insert(20);
    list->insert(30);
    list->insert(10);

    bubbleSort(*list);

    EXPECT_EQ(list->size(), 5);
    EXPECT_TRUE(isSortedAscending());
    EXPECT_EQ(list->get(0), 10);
    EXPECT_EQ(list->get(1), 10);
    EXPECT_EQ(list->get(4), 30);
}

TEST_F(BubbleSortTest, SortNegativeNumbers) {
    list->insert(-5);
    list->insert(-1);
    list->insert(-10);
    list->insert(-3);

    bubbleSort(*list);

    EXPECT_EQ(list->size(), 4);
    EXPECT_TRUE(isSortedAscending());
    EXPECT_EQ(list->get(0), -10);
    EXPECT_EQ(list->get(3), -1);
}

TEST_F(BubbleSortTest, SortMixedPositiveNegative) {
    list->insert(5);
    list->insert(-2);
    list->insert(10);
    list->insert(-8);
    list->insert(0);

    bubbleSort(*list);

    EXPECT_EQ(list->size(), 5);
    EXPECT_TRUE(isSortedAscending());
    EXPECT_EQ(list->get(0), -8);
    EXPECT_EQ(list->get(2), 0);
    EXPECT_EQ(list->get(4), 10);
}

TEST_F(BubbleSortTest, SortAllSameElements) {
    list->insert(5);
    list->insert(5);
    list->insert(5);
    list->insert(5);

    bubbleSort(*list);

    EXPECT_EQ(list->size(), 4);
    EXPECT_TRUE(isSortedAscending());
    for (int i = 0; i < 4; i++) {
        EXPECT_EQ(list->get(i), 5);
    }
}

/* -------------------------------------------------------------------------- */
/*                      Descending Sort Tests                                 */
/* -------------------------------------------------------------------------- */

TEST_F(BubbleSortTest, SortDescendingEmptyList) {
    bubbleSortDescending(*list);
    EXPECT_TRUE(list->isEmpty());
}

TEST_F(BubbleSortTest, SortDescendingSingleElement) {
    list->insert(42);
    bubbleSortDescending(*list);

    EXPECT_EQ(list->size(), 1);
    EXPECT_EQ(list->get(0), 42);
}

TEST_F(BubbleSortTest, SortDescendingAlreadySorted) {
    list->insert(40);
    list->insert(30);
    list->insert(20);
    list->insert(10);

    bubbleSortDescending(*list);

    EXPECT_EQ(list->size(), 4);
    EXPECT_TRUE(isSortedDescending());
    EXPECT_EQ(list->get(0), 40);
    EXPECT_EQ(list->get(3), 10);
}

TEST_F(BubbleSortTest, SortDescendingReverseSorted) {
    list->insert(10);
    list->insert(20);
    list->insert(30);
    list->insert(40);

    bubbleSortDescending(*list);

    EXPECT_EQ(list->size(), 4);
    EXPECT_TRUE(isSortedDescending());
    EXPECT_EQ(list->get(0), 40);
    EXPECT_EQ(list->get(3), 10);
}

TEST_F(BubbleSortTest, SortDescendingRandomOrder) {
    list->insert(64);
    list->insert(34);
    list->insert(25);
    list->insert(12);
    list->insert(90);

    bubbleSortDescending(*list);

    EXPECT_EQ(list->size(), 5);
    EXPECT_TRUE(isSortedDescending());
    EXPECT_EQ(list->get(0), 90);
    EXPECT_EQ(list->get(4), 12);
}

TEST_F(BubbleSortTest, SortDescendingWithDuplicates) {
    list->insert(20);
    list->insert(10);
    list->insert(20);
    list->insert(30);

    bubbleSortDescending(*list);

    EXPECT_EQ(list->size(), 4);
    EXPECT_TRUE(isSortedDescending());
    EXPECT_EQ(list->get(0), 30);
    EXPECT_EQ(list->get(3), 10);
}

TEST_F(BubbleSortTest, SortDescendingMixedPositiveNegative) {
    list->insert(5);
    list->insert(-2);
    list->insert(10);
    list->insert(0);

    bubbleSortDescending(*list);

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
