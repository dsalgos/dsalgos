/**
 * @file test_list.cpp
 * @brief Unit tests for the List ADT
 *
 * This file contains comprehensive tests for the List Abstract Data Type
 * using Google Test framework. Tests cover all ADT operations including
 * insert, remove, search, and utility functions.
 */

// Header to be tested
#include <dsalgos/list/list.hpp>

// External dependencies
#include <gtest/gtest.h>
#include <sstream>

using namespace dsalgos;

/**
 * @brief Test fixture for List ADT tests
 *
 * Provides a clean List instance for each test
 */
class ListTest : public ::testing::Test {
  protected:
    List* list;

    void SetUp() override { list = new List(); }

    void TearDown() override { delete list; }
};

/* -------------------------------------------------------------------------- */
/*                          Constructor Tests                                 */
/* -------------------------------------------------------------------------- */

TEST_F(ListTest, ConstructorCreatesEmptyList) {
    EXPECT_TRUE(list->isEmpty());
    EXPECT_EQ(list->size(), 0);
}

/* -------------------------------------------------------------------------- */
/*                          Insert Operation Tests                            */
/* -------------------------------------------------------------------------- */

TEST_F(ListTest, InsertSingleElement) {
    list->insert(10);
    EXPECT_FALSE(list->isEmpty());
    EXPECT_EQ(list->size(), 1);
    EXPECT_TRUE(list->contains(10));
}

TEST_F(ListTest, InsertMultipleElements) {
    list->insert(10);
    list->insert(20);
    list->insert(30);

    EXPECT_EQ(list->size(), 3);
    EXPECT_TRUE(list->contains(10));
    EXPECT_TRUE(list->contains(20));
    EXPECT_TRUE(list->contains(30));
}

TEST_F(ListTest, InsertDuplicateElements) {
    list->insert(10);
    list->insert(10);
    list->insert(10);

    EXPECT_EQ(list->size(), 3);
    EXPECT_TRUE(list->contains(10));
}

TEST_F(ListTest, InsertNegativeNumbers) {
    list->insert(-5);
    list->insert(-10);
    list->insert(-15);

    EXPECT_EQ(list->size(), 3);
    EXPECT_TRUE(list->contains(-5));
    EXPECT_TRUE(list->contains(-10));
    EXPECT_TRUE(list->contains(-15));
}

TEST_F(ListTest, InsertZero) {
    list->insert(0);
    EXPECT_EQ(list->size(), 1);
    EXPECT_TRUE(list->contains(0));
}

TEST_F(ListTest, InsertLargeNumbers) {
    list->insert(1000000);
    list->insert(2000000);

    EXPECT_EQ(list->size(), 2);
    EXPECT_TRUE(list->contains(1000000));
    EXPECT_TRUE(list->contains(2000000));
}

/* -------------------------------------------------------------------------- */
/*                          Remove Operation Tests                            */
/* -------------------------------------------------------------------------- */

TEST_F(ListTest, RemoveFromEmptyList) {
    EXPECT_FALSE(list->remove(10));
    EXPECT_EQ(list->size(), 0);
}

TEST_F(ListTest, RemoveSingleElement) {
    list->insert(10);
    EXPECT_TRUE(list->remove(10));
    EXPECT_TRUE(list->isEmpty());
    EXPECT_EQ(list->size(), 0);
}

TEST_F(ListTest, RemoveFirstElement) {
    list->insert(10);
    list->insert(20);
    list->insert(30);

    EXPECT_TRUE(list->remove(10));
    EXPECT_EQ(list->size(), 2);
    EXPECT_FALSE(list->contains(10));
    EXPECT_TRUE(list->contains(20));
    EXPECT_TRUE(list->contains(30));
}

TEST_F(ListTest, RemoveMiddleElement) {
    list->insert(10);
    list->insert(20);
    list->insert(30);

    EXPECT_TRUE(list->remove(20));
    EXPECT_EQ(list->size(), 2);
    EXPECT_TRUE(list->contains(10));
    EXPECT_FALSE(list->contains(20));
    EXPECT_TRUE(list->contains(30));
}

TEST_F(ListTest, RemoveLastElement) {
    list->insert(10);
    list->insert(20);
    list->insert(30);

    EXPECT_TRUE(list->remove(30));
    EXPECT_EQ(list->size(), 2);
    EXPECT_TRUE(list->contains(10));
    EXPECT_TRUE(list->contains(20));
    EXPECT_FALSE(list->contains(30));
}

TEST_F(ListTest, RemoveNonExistentElement) {
    list->insert(10);
    list->insert(20);

    EXPECT_FALSE(list->remove(30));
    EXPECT_EQ(list->size(), 2);
}

TEST_F(ListTest, RemoveFirstOccurrenceOfDuplicate) {
    list->insert(10);
    list->insert(20);
    list->insert(10);
    list->insert(30);

    EXPECT_TRUE(list->remove(10));
    EXPECT_EQ(list->size(), 3);
    EXPECT_TRUE(list->contains(10)); // Second occurrence still exists
}

TEST_F(ListTest, RemoveAllElements) {
    list->insert(10);
    list->insert(20);
    list->insert(30);

    EXPECT_TRUE(list->remove(10));
    EXPECT_TRUE(list->remove(20));
    EXPECT_TRUE(list->remove(30));

    EXPECT_TRUE(list->isEmpty());
    EXPECT_EQ(list->size(), 0);
}

/* -------------------------------------------------------------------------- */
/*                          Contains Operation Tests                          */
/* -------------------------------------------------------------------------- */

TEST_F(ListTest, ContainsInEmptyList) {
    EXPECT_FALSE(list->contains(10));
}

TEST_F(ListTest, ContainsExistingElement) {
    list->insert(10);
    list->insert(20);
    list->insert(30);

    EXPECT_TRUE(list->contains(10));
    EXPECT_TRUE(list->contains(20));
    EXPECT_TRUE(list->contains(30));
}

TEST_F(ListTest, ContainsNonExistingElement) {
    list->insert(10);
    list->insert(20);

    EXPECT_FALSE(list->contains(30));
    EXPECT_FALSE(list->contains(40));
}

TEST_F(ListTest, ContainsAfterRemove) {
    list->insert(10);
    list->insert(20);

    list->remove(10);

    EXPECT_FALSE(list->contains(10));
    EXPECT_TRUE(list->contains(20));
}

TEST_F(ListTest, ContainsZero) {
    list->insert(0);
    EXPECT_TRUE(list->contains(0));
}

TEST_F(ListTest, ContainsNegativeNumber) {
    list->insert(-10);
    EXPECT_TRUE(list->contains(-10));
}

/* -------------------------------------------------------------------------- */
/*                          Size Operation Tests                              */
/* -------------------------------------------------------------------------- */

TEST_F(ListTest, SizeOfEmptyList) {
    EXPECT_EQ(list->size(), 0);
}

TEST_F(ListTest, SizeAfterInserts) {
    EXPECT_EQ(list->size(), 0);

    list->insert(10);
    EXPECT_EQ(list->size(), 1);

    list->insert(20);
    EXPECT_EQ(list->size(), 2);

    list->insert(30);
    EXPECT_EQ(list->size(), 3);
}

TEST_F(ListTest, SizeAfterRemoves) {
    list->insert(10);
    list->insert(20);
    list->insert(30);
    EXPECT_EQ(list->size(), 3);

    list->remove(20);
    EXPECT_EQ(list->size(), 2);

    list->remove(10);
    EXPECT_EQ(list->size(), 1);

    list->remove(30);
    EXPECT_EQ(list->size(), 0);
}

TEST_F(ListTest, SizeAfterFailedRemove) {
    list->insert(10);
    EXPECT_EQ(list->size(), 1);

    list->remove(20); // Non-existent
    EXPECT_EQ(list->size(), 1);
}

/* -------------------------------------------------------------------------- */
/*                          IsEmpty Operation Tests                           */
/* -------------------------------------------------------------------------- */

TEST_F(ListTest, IsEmptyOnNewList) {
    EXPECT_TRUE(list->isEmpty());
}

TEST_F(ListTest, IsEmptyAfterInsert) {
    list->insert(10);
    EXPECT_FALSE(list->isEmpty());
}

TEST_F(ListTest, IsEmptyAfterInsertAndRemove) {
    list->insert(10);
    list->remove(10);
    EXPECT_TRUE(list->isEmpty());
}

TEST_F(ListTest, IsEmptyAfterClear) {
    list->insert(10);
    list->insert(20);
    list->clear();
    EXPECT_TRUE(list->isEmpty());
}

/* -------------------------------------------------------------------------- */
/*                          Clear Operation Tests                             */
/* -------------------------------------------------------------------------- */

TEST_F(ListTest, ClearEmptyList) {
    list->clear();
    EXPECT_TRUE(list->isEmpty());
    EXPECT_EQ(list->size(), 0);
}

TEST_F(ListTest, ClearListWithElements) {
    list->insert(10);
    list->insert(20);
    list->insert(30);

    list->clear();

    EXPECT_TRUE(list->isEmpty());
    EXPECT_EQ(list->size(), 0);
    EXPECT_FALSE(list->contains(10));
    EXPECT_FALSE(list->contains(20));
    EXPECT_FALSE(list->contains(30));
}

TEST_F(ListTest, ClearAndReuse) {
    list->insert(10);
    list->insert(20);
    list->clear();

    list->insert(30);
    list->insert(40);

    EXPECT_EQ(list->size(), 2);
    EXPECT_TRUE(list->contains(30));
    EXPECT_TRUE(list->contains(40));
    EXPECT_FALSE(list->contains(10));
    EXPECT_FALSE(list->contains(20));
}

TEST_F(ListTest, MultipleClearCalls) {
    list->insert(10);
    list->clear();
    list->clear();
    list->clear();

    EXPECT_TRUE(list->isEmpty());
    EXPECT_EQ(list->size(), 0);
}

/* -------------------------------------------------------------------------- */
/*                          Print Operation Tests                             */
/* -------------------------------------------------------------------------- */

TEST_F(ListTest, PrintEmptyList) {
    // Redirect stdout to capture output
    testing::internal::CaptureStdout();
    list->print();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "[]\n");
}

TEST_F(ListTest, PrintSingleElement) {
    list->insert(10);

    testing::internal::CaptureStdout();
    list->print();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "[10]\n");
}

TEST_F(ListTest, PrintMultipleElements) {
    list->insert(10);
    list->insert(20);
    list->insert(30);

    testing::internal::CaptureStdout();
    list->print();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "[10, 20, 30]\n");
}

/* -------------------------------------------------------------------------- */
/*                          Integration Tests                                 */
/* -------------------------------------------------------------------------- */

TEST_F(ListTest, ComplexOperationSequence) {
    // Insert elements
    list->insert(10);
    list->insert(20);
    list->insert(30);
    list->insert(40);
    EXPECT_EQ(list->size(), 4);

    // Remove some elements
    list->remove(20);
    EXPECT_EQ(list->size(), 3);
    EXPECT_FALSE(list->contains(20));

    // Add more elements
    list->insert(50);
    list->insert(60);
    EXPECT_EQ(list->size(), 5);

    // Remove more
    list->remove(10);
    list->remove(40);
    EXPECT_EQ(list->size(), 3);

    // Verify remaining elements
    EXPECT_TRUE(list->contains(30));
    EXPECT_TRUE(list->contains(50));
    EXPECT_TRUE(list->contains(60));
}

TEST_F(ListTest, StressTest) {
    // Insert many elements
    for (int i = 0; i < 1000; i++) {
        list->insert(i);
    }
    EXPECT_EQ(list->size(), 1000);

    // Verify some elements
    EXPECT_TRUE(list->contains(0));
    EXPECT_TRUE(list->contains(500));
    EXPECT_TRUE(list->contains(999));

    // Remove some elements
    for (int i = 0; i < 500; i++) {
        list->remove(i);
    }
    EXPECT_EQ(list->size(), 500);

    // Clear all
    list->clear();
    EXPECT_TRUE(list->isEmpty());
}

/* -------------------------------------------------------------------------- */
/*                          Edge Case Tests                                   */
/* -------------------------------------------------------------------------- */

TEST_F(ListTest, AlternatingInsertRemove) {
    list->insert(10);
    list->remove(10);
    list->insert(20);
    list->remove(20);
    list->insert(30);

    EXPECT_EQ(list->size(), 1);
    EXPECT_TRUE(list->contains(30));
}

TEST_F(ListTest, InsertAfterClear) {
    list->insert(10);
    list->clear();
    list->insert(20);

    EXPECT_EQ(list->size(), 1);
    EXPECT_TRUE(list->contains(20));
    EXPECT_FALSE(list->contains(10));
}

TEST_F(ListTest, RemoveSameElementMultipleTimes) {
    list->insert(10);
    EXPECT_TRUE(list->remove(10));
    EXPECT_FALSE(list->remove(10)); // Already removed
    EXPECT_FALSE(list->remove(10)); // Still not there
}

/* -------------------------------------------------------------------------- */
/*                          Main Function                                     */
/* -------------------------------------------------------------------------- */

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
