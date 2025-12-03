/**
 * @file test_linkedlist.cpp
 * @brief Unit tests for the LinkedList data structure
 *
 * This file contains comprehensive tests for the LinkedList implementation
 * using Google Test framework. Tests cover all operations including
 * insertion, deletion, search, access, and utility functions.
 */

// Header to be tested
#include <dsalgos/list/linkedlist.hpp>

// External dependencies
#include <gtest/gtest.h>
#include <sstream>
#include <stdexcept>

using namespace dsalgos;

/**
 * @brief Test fixture for LinkedList tests
 *
 * Provides a clean LinkedList instance for each test
 */
class LinkedListTest : public ::testing::Test {
  protected:
    LinkedList* linkedList;

    void SetUp() override { linkedList = new LinkedList(); }

    void TearDown() override { delete linkedList; }
};

/* -------------------------------------------------------------------------- */
/*                          Constructor Tests                                 */
/* -------------------------------------------------------------------------- */

TEST_F(LinkedListTest, ConstructorCreatesEmptyList) {
    EXPECT_TRUE(linkedList->isEmpty());
    EXPECT_EQ(linkedList->getSize(), 0);
}

/* -------------------------------------------------------------------------- */
/*                          Insert Front Tests                                */
/* -------------------------------------------------------------------------- */

TEST_F(LinkedListTest, InsertFrontSingleElement) {
    linkedList->insertFront(10);
    EXPECT_FALSE(linkedList->isEmpty());
    EXPECT_EQ(linkedList->getSize(), 1);
    EXPECT_EQ(linkedList->front(), 10);
    EXPECT_EQ(linkedList->back(), 10);
}

TEST_F(LinkedListTest, InsertFrontMultipleElements) {
    linkedList->insertFront(10);
    linkedList->insertFront(20);
    linkedList->insertFront(30);

    EXPECT_EQ(linkedList->getSize(), 3);
    EXPECT_EQ(linkedList->front(), 30); // Last inserted at front
    EXPECT_EQ(linkedList->back(), 10);  // First inserted
}

TEST_F(LinkedListTest, InsertFrontOrder) {
    linkedList->insertFront(10);
    linkedList->insertFront(20);
    linkedList->insertFront(30);

    // Order should be: 30, 20, 10
    EXPECT_EQ(linkedList->get(0), 30);
    EXPECT_EQ(linkedList->get(1), 20);
    EXPECT_EQ(linkedList->get(2), 10);
}

/* -------------------------------------------------------------------------- */
/*                          Insert Back Tests                                 */
/* -------------------------------------------------------------------------- */

TEST_F(LinkedListTest, InsertBackSingleElement) {
    linkedList->insertBack(10);
    EXPECT_FALSE(linkedList->isEmpty());
    EXPECT_EQ(linkedList->getSize(), 1);
    EXPECT_EQ(linkedList->front(), 10);
    EXPECT_EQ(linkedList->back(), 10);
}

TEST_F(LinkedListTest, InsertBackMultipleElements) {
    linkedList->insertBack(10);
    linkedList->insertBack(20);
    linkedList->insertBack(30);

    EXPECT_EQ(linkedList->getSize(), 3);
    EXPECT_EQ(linkedList->front(), 10);
    EXPECT_EQ(linkedList->back(), 30);
}

TEST_F(LinkedListTest, InsertBackOrder) {
    linkedList->insertBack(10);
    linkedList->insertBack(20);
    linkedList->insertBack(30);

    // Order should be: 10, 20, 30
    EXPECT_EQ(linkedList->get(0), 10);
    EXPECT_EQ(linkedList->get(1), 20);
    EXPECT_EQ(linkedList->get(2), 30);
}

TEST_F(LinkedListTest, MixedInsertFrontAndBack) {
    linkedList->insertBack(20);
    linkedList->insertFront(10);
    linkedList->insertBack(30);
    linkedList->insertFront(5);

    // Order should be: 5, 10, 20, 30
    EXPECT_EQ(linkedList->getSize(), 4);
    EXPECT_EQ(linkedList->get(0), 5);
    EXPECT_EQ(linkedList->get(1), 10);
    EXPECT_EQ(linkedList->get(2), 20);
    EXPECT_EQ(linkedList->get(3), 30);
}

/* -------------------------------------------------------------------------- */
/*                          Insert At Tests                                   */
/* -------------------------------------------------------------------------- */

TEST_F(LinkedListTest, InsertAtBeginning) {
    linkedList->insertBack(20);
    linkedList->insertBack(30);
    linkedList->insertAt(10, 0);

    EXPECT_EQ(linkedList->getSize(), 3);
    EXPECT_EQ(linkedList->get(0), 10);
    EXPECT_EQ(linkedList->get(1), 20);
    EXPECT_EQ(linkedList->get(2), 30);
}

TEST_F(LinkedListTest, InsertAtMiddle) {
    linkedList->insertBack(10);
    linkedList->insertBack(30);
    linkedList->insertAt(20, 1);

    EXPECT_EQ(linkedList->getSize(), 3);
    EXPECT_EQ(linkedList->get(0), 10);
    EXPECT_EQ(linkedList->get(1), 20);
    EXPECT_EQ(linkedList->get(2), 30);
}

TEST_F(LinkedListTest, InsertAtEnd) {
    linkedList->insertBack(10);
    linkedList->insertBack(20);
    linkedList->insertAt(30, 2);

    EXPECT_EQ(linkedList->getSize(), 3);
    EXPECT_EQ(linkedList->get(2), 30);
}

TEST_F(LinkedListTest, InsertAtEmptyList) {
    linkedList->insertAt(10, 0);
    EXPECT_EQ(linkedList->getSize(), 1);
    EXPECT_EQ(linkedList->get(0), 10);
}

TEST_F(LinkedListTest, InsertAtInvalidPosition) {
    linkedList->insertBack(10);
    EXPECT_THROW(linkedList->insertAt(20, 5), std::out_of_range);
    EXPECT_THROW(linkedList->insertAt(20, -1), std::out_of_range);
}

/* -------------------------------------------------------------------------- */
/*                          Delete Front Tests                                */
/* -------------------------------------------------------------------------- */

TEST_F(LinkedListTest, DeleteFrontSingleElement) {
    linkedList->insertBack(10);
    linkedList->deleteFront();

    EXPECT_TRUE(linkedList->isEmpty());
    EXPECT_EQ(linkedList->getSize(), 0);
}

TEST_F(LinkedListTest, DeleteFrontMultipleElements) {
    linkedList->insertBack(10);
    linkedList->insertBack(20);
    linkedList->insertBack(30);

    linkedList->deleteFront();

    EXPECT_EQ(linkedList->getSize(), 2);
    EXPECT_EQ(linkedList->front(), 20);
}

TEST_F(LinkedListTest, DeleteFrontEmptyList) {
    EXPECT_THROW(linkedList->deleteFront(), std::runtime_error);
}

TEST_F(LinkedListTest, DeleteFrontMultipleTimes) {
    linkedList->insertBack(10);
    linkedList->insertBack(20);
    linkedList->insertBack(30);

    linkedList->deleteFront();
    linkedList->deleteFront();

    EXPECT_EQ(linkedList->getSize(), 1);
    EXPECT_EQ(linkedList->front(), 30);
}

/* -------------------------------------------------------------------------- */
/*                          Delete Back Tests                                 */
/* -------------------------------------------------------------------------- */

TEST_F(LinkedListTest, DeleteBackSingleElement) {
    linkedList->insertBack(10);
    linkedList->deleteBack();

    EXPECT_TRUE(linkedList->isEmpty());
    EXPECT_EQ(linkedList->getSize(), 0);
}

TEST_F(LinkedListTest, DeleteBackMultipleElements) {
    linkedList->insertBack(10);
    linkedList->insertBack(20);
    linkedList->insertBack(30);

    linkedList->deleteBack();

    EXPECT_EQ(linkedList->getSize(), 2);
    EXPECT_EQ(linkedList->back(), 20);
}

TEST_F(LinkedListTest, DeleteBackEmptyList) {
    EXPECT_THROW(linkedList->deleteBack(), std::runtime_error);
}

TEST_F(LinkedListTest, DeleteBackMultipleTimes) {
    linkedList->insertBack(10);
    linkedList->insertBack(20);
    linkedList->insertBack(30);

    linkedList->deleteBack();
    linkedList->deleteBack();

    EXPECT_EQ(linkedList->getSize(), 1);
    EXPECT_EQ(linkedList->back(), 10);
}

/* -------------------------------------------------------------------------- */
/*                          Delete At Tests                                   */
/* -------------------------------------------------------------------------- */

TEST_F(LinkedListTest, DeleteAtBeginning) {
    linkedList->insertBack(10);
    linkedList->insertBack(20);
    linkedList->insertBack(30);

    linkedList->deleteAt(0);

    EXPECT_EQ(linkedList->getSize(), 2);
    EXPECT_EQ(linkedList->get(0), 20);
}

TEST_F(LinkedListTest, DeleteAtMiddle) {
    linkedList->insertBack(10);
    linkedList->insertBack(20);
    linkedList->insertBack(30);

    linkedList->deleteAt(1);

    EXPECT_EQ(linkedList->getSize(), 2);
    EXPECT_EQ(linkedList->get(0), 10);
    EXPECT_EQ(linkedList->get(1), 30);
}

TEST_F(LinkedListTest, DeleteAtEnd) {
    linkedList->insertBack(10);
    linkedList->insertBack(20);
    linkedList->insertBack(30);

    linkedList->deleteAt(2);

    EXPECT_EQ(linkedList->getSize(), 2);
    EXPECT_EQ(linkedList->back(), 20);
}

TEST_F(LinkedListTest, DeleteAtInvalidPosition) {
    linkedList->insertBack(10);
    EXPECT_THROW(linkedList->deleteAt(5), std::out_of_range);
    EXPECT_THROW(linkedList->deleteAt(-1), std::out_of_range);
}

/* -------------------------------------------------------------------------- */
/*                          Delete Value Tests                                */
/* -------------------------------------------------------------------------- */

TEST_F(LinkedListTest, DeleteValueFirst) {
    linkedList->insertBack(10);
    linkedList->insertBack(20);
    linkedList->insertBack(30);

    EXPECT_TRUE(linkedList->deleteValue(10));
    EXPECT_EQ(linkedList->getSize(), 2);
    EXPECT_EQ(linkedList->search(10), -1);
}

TEST_F(LinkedListTest, DeleteValueMiddle) {
    linkedList->insertBack(10);
    linkedList->insertBack(20);
    linkedList->insertBack(30);

    EXPECT_TRUE(linkedList->deleteValue(20));
    EXPECT_EQ(linkedList->getSize(), 2);
    EXPECT_EQ(linkedList->search(20), -1);
}

TEST_F(LinkedListTest, DeleteValueLast) {
    linkedList->insertBack(10);
    linkedList->insertBack(20);
    linkedList->insertBack(30);

    EXPECT_TRUE(linkedList->deleteValue(30));
    EXPECT_EQ(linkedList->getSize(), 2);
    EXPECT_EQ(linkedList->search(30), -1);
}

TEST_F(LinkedListTest, DeleteValueNotFound) {
    linkedList->insertBack(10);
    linkedList->insertBack(20);

    EXPECT_FALSE(linkedList->deleteValue(30));
    EXPECT_EQ(linkedList->getSize(), 2);
}

TEST_F(LinkedListTest, DeleteValueFromEmpty) {
    EXPECT_FALSE(linkedList->deleteValue(10));
}

TEST_F(LinkedListTest, DeleteValueDuplicate) {
    linkedList->insertBack(10);
    linkedList->insertBack(20);
    linkedList->insertBack(10);

    EXPECT_TRUE(linkedList->deleteValue(10));
    EXPECT_EQ(linkedList->getSize(), 2);
    EXPECT_NE(linkedList->search(10), -1); // Second occurrence still exists
}

/* -------------------------------------------------------------------------- */
/*                          Search Tests                                      */
/* -------------------------------------------------------------------------- */

TEST_F(LinkedListTest, SearchInEmptyList) {
    EXPECT_EQ(linkedList->search(10), -1);
}

TEST_F(LinkedListTest, SearchExistingElement) {
    linkedList->insertBack(10);
    linkedList->insertBack(20);
    linkedList->insertBack(30);

    EXPECT_EQ(linkedList->search(10), 0);
    EXPECT_EQ(linkedList->search(20), 1);
    EXPECT_EQ(linkedList->search(30), 2);
}

TEST_F(LinkedListTest, SearchNonExistingElement) {
    linkedList->insertBack(10);
    linkedList->insertBack(20);

    EXPECT_EQ(linkedList->search(30), -1);
}

TEST_F(LinkedListTest, SearchDuplicate) {
    linkedList->insertBack(10);
    linkedList->insertBack(20);
    linkedList->insertBack(10);

    EXPECT_EQ(linkedList->search(10), 0); // Returns first occurrence
}

/* -------------------------------------------------------------------------- */
/*                          Get Tests                                         */
/* -------------------------------------------------------------------------- */

TEST_F(LinkedListTest, GetValidPositions) {
    linkedList->insertBack(10);
    linkedList->insertBack(20);
    linkedList->insertBack(30);

    EXPECT_EQ(linkedList->get(0), 10);
    EXPECT_EQ(linkedList->get(1), 20);
    EXPECT_EQ(linkedList->get(2), 30);
}

TEST_F(LinkedListTest, GetInvalidPosition) {
    linkedList->insertBack(10);

    EXPECT_THROW(linkedList->get(5), std::out_of_range);
    EXPECT_THROW(linkedList->get(-1), std::out_of_range);
}

TEST_F(LinkedListTest, GetFromEmptyList) {
    EXPECT_THROW(linkedList->get(0), std::out_of_range);
}

/* -------------------------------------------------------------------------- */
/*                          Front and Back Tests                              */
/* -------------------------------------------------------------------------- */

TEST_F(LinkedListTest, FrontSingleElement) {
    linkedList->insertBack(10);
    EXPECT_EQ(linkedList->front(), 10);
}

TEST_F(LinkedListTest, FrontMultipleElements) {
    linkedList->insertBack(10);
    linkedList->insertBack(20);
    linkedList->insertBack(30);

    EXPECT_EQ(linkedList->front(), 10);
}

TEST_F(LinkedListTest, FrontEmptyList) {
    EXPECT_THROW(linkedList->front(), std::runtime_error);
}

TEST_F(LinkedListTest, BackSingleElement) {
    linkedList->insertBack(10);
    EXPECT_EQ(linkedList->back(), 10);
}

TEST_F(LinkedListTest, BackMultipleElements) {
    linkedList->insertBack(10);
    linkedList->insertBack(20);
    linkedList->insertBack(30);

    EXPECT_EQ(linkedList->back(), 30);
}

TEST_F(LinkedListTest, BackEmptyList) {
    EXPECT_THROW(linkedList->back(), std::runtime_error);
}

/* -------------------------------------------------------------------------- */
/*                          Clear Tests                                       */
/* -------------------------------------------------------------------------- */

TEST_F(LinkedListTest, ClearEmptyList) {
    linkedList->clear();
    EXPECT_TRUE(linkedList->isEmpty());
    EXPECT_EQ(linkedList->getSize(), 0);
}

TEST_F(LinkedListTest, ClearNonEmptyList) {
    linkedList->insertBack(10);
    linkedList->insertBack(20);
    linkedList->insertBack(30);

    linkedList->clear();

    EXPECT_TRUE(linkedList->isEmpty());
    EXPECT_EQ(linkedList->getSize(), 0);
}

TEST_F(LinkedListTest, ClearAndReuse) {
    linkedList->insertBack(10);
    linkedList->clear();
    linkedList->insertBack(20);

    EXPECT_EQ(linkedList->getSize(), 1);
    EXPECT_EQ(linkedList->front(), 20);
}

/* -------------------------------------------------------------------------- */
/*                          Reverse Tests                                     */
/* -------------------------------------------------------------------------- */

TEST_F(LinkedListTest, ReverseEmptyList) {
    linkedList->reverse();
    EXPECT_TRUE(linkedList->isEmpty());
}

TEST_F(LinkedListTest, ReverseSingleElement) {
    linkedList->insertBack(10);
    linkedList->reverse();

    EXPECT_EQ(linkedList->getSize(), 1);
    EXPECT_EQ(linkedList->front(), 10);
}

TEST_F(LinkedListTest, ReverseMultipleElements) {
    linkedList->insertBack(10);
    linkedList->insertBack(20);
    linkedList->insertBack(30);
    linkedList->insertBack(40);

    linkedList->reverse();

    EXPECT_EQ(linkedList->get(0), 40);
    EXPECT_EQ(linkedList->get(1), 30);
    EXPECT_EQ(linkedList->get(2), 20);
    EXPECT_EQ(linkedList->get(3), 10);
}

TEST_F(LinkedListTest, ReverseAndFrontBack) {
    linkedList->insertBack(10);
    linkedList->insertBack(20);
    linkedList->insertBack(30);

    linkedList->reverse();

    EXPECT_EQ(linkedList->front(), 30);
    EXPECT_EQ(linkedList->back(), 10);
}

TEST_F(LinkedListTest, ReverseDoubleReverse) {
    linkedList->insertBack(10);
    linkedList->insertBack(20);
    linkedList->insertBack(30);

    linkedList->reverse();
    linkedList->reverse();

    // Should be back to original order
    EXPECT_EQ(linkedList->get(0), 10);
    EXPECT_EQ(linkedList->get(1), 20);
    EXPECT_EQ(linkedList->get(2), 30);
}

/* -------------------------------------------------------------------------- */
/*                          Display Tests                                     */
/* -------------------------------------------------------------------------- */

TEST_F(LinkedListTest, DisplayEmptyList) {
    testing::internal::CaptureStdout();
    linkedList->display();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "List is empty\n");
}

TEST_F(LinkedListTest, DisplaySingleElement) {
    linkedList->insertBack(10);

    testing::internal::CaptureStdout();
    linkedList->display();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "10 -> nullptr\n");
}

TEST_F(LinkedListTest, DisplayMultipleElements) {
    linkedList->insertBack(10);
    linkedList->insertBack(20);
    linkedList->insertBack(30);

    testing::internal::CaptureStdout();
    linkedList->display();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "10 -> 20 -> 30 -> nullptr\n");
}

/* -------------------------------------------------------------------------- */
/*                          Get Middle Tests                                  */
/* -------------------------------------------------------------------------- */

TEST_F(LinkedListTest, GetMiddleEmptyList) {
    EXPECT_THROW(linkedList->getMiddle(), std::runtime_error);
}

TEST_F(LinkedListTest, GetMiddleSingleElement) {
    linkedList->insertBack(10);
    EXPECT_EQ(linkedList->getMiddle(), 10);
}

TEST_F(LinkedListTest, GetMiddleOddCount) {
    linkedList->insertBack(10);
    linkedList->insertBack(20);
    linkedList->insertBack(30);
    linkedList->insertBack(40);
    linkedList->insertBack(50);

    EXPECT_EQ(linkedList->getMiddle(), 30);
}

TEST_F(LinkedListTest, GetMiddleEvenCount) {
    linkedList->insertBack(10);
    linkedList->insertBack(20);
    linkedList->insertBack(30);
    linkedList->insertBack(40);

    EXPECT_EQ(linkedList->getMiddle(), 20);
}

/* -------------------------------------------------------------------------- */
/*                          Has Cycle Tests                                   */
/* -------------------------------------------------------------------------- */

TEST_F(LinkedListTest, HasCycleEmptyList) {
    EXPECT_FALSE(linkedList->hasCycle());
}

TEST_F(LinkedListTest, HasCycleSingleElement) {
    linkedList->insertBack(10);
    EXPECT_FALSE(linkedList->hasCycle());
}

TEST_F(LinkedListTest, HasCycleNoCycle) {
    linkedList->insertBack(10);
    linkedList->insertBack(20);
    linkedList->insertBack(30);

    EXPECT_FALSE(linkedList->hasCycle());
}

/* -------------------------------------------------------------------------- */
/*                          Copy Constructor Tests                            */
/* -------------------------------------------------------------------------- */

TEST_F(LinkedListTest, CopyConstructorEmptyList) {
    LinkedList copy(*linkedList);

    EXPECT_TRUE(copy.isEmpty());
    EXPECT_EQ(copy.getSize(), 0);
}

TEST_F(LinkedListTest, CopyConstructorNonEmptyList) {
    linkedList->insertBack(10);
    linkedList->insertBack(20);
    linkedList->insertBack(30);

    LinkedList copy(*linkedList);

    EXPECT_EQ(copy.getSize(), 3);
    EXPECT_EQ(copy.get(0), 10);
    EXPECT_EQ(copy.get(1), 20);
    EXPECT_EQ(copy.get(2), 30);
}

TEST_F(LinkedListTest, CopyConstructorIndependence) {
    linkedList->insertBack(10);
    linkedList->insertBack(20);

    LinkedList copy(*linkedList);

    // Modify original
    linkedList->insertBack(30);

    // Copy should be unchanged
    EXPECT_EQ(linkedList->getSize(), 3);
    EXPECT_EQ(copy.getSize(), 2);
}

/* -------------------------------------------------------------------------- */
/*                          Copy Assignment Tests                             */
/* -------------------------------------------------------------------------- */

TEST_F(LinkedListTest, CopyAssignmentOperator) {
    linkedList->insertBack(10);
    linkedList->insertBack(20);
    linkedList->insertBack(30);

    LinkedList other;
    other = *linkedList;

    EXPECT_EQ(other.getSize(), 3);
    EXPECT_EQ(other.get(0), 10);
    EXPECT_EQ(other.get(1), 20);
    EXPECT_EQ(other.get(2), 30);
}

TEST_F(LinkedListTest, CopyAssignmentSelfAssignment) {
    linkedList->insertBack(10);
    linkedList->insertBack(20);

    *linkedList = *linkedList;

    EXPECT_EQ(linkedList->getSize(), 2);
    EXPECT_EQ(linkedList->get(0), 10);
    EXPECT_EQ(linkedList->get(1), 20);
}

/* -------------------------------------------------------------------------- */
/*                          Stress Tests                                      */
/* -------------------------------------------------------------------------- */

TEST_F(LinkedListTest, StressTestLargeInsertions) {
    for (int i = 0; i < 10000; i++) {
        linkedList->insertBack(i);
    }

    EXPECT_EQ(linkedList->getSize(), 10000);
    EXPECT_EQ(linkedList->front(), 0);
    EXPECT_EQ(linkedList->back(), 9999);
}

TEST_F(LinkedListTest, StressTestMixedOperations) {
    // Insert many elements
    for (int i = 0; i < 1000; i++) {
        linkedList->insertBack(i);
    }

    // Delete half from front
    for (int i = 0; i < 500; i++) {
        linkedList->deleteFront();
    }

    EXPECT_EQ(linkedList->getSize(), 500);
    EXPECT_EQ(linkedList->front(), 500);

    // Clear
    linkedList->clear();
    EXPECT_TRUE(linkedList->isEmpty());
}

/* -------------------------------------------------------------------------- */
/*                          Main Function                                     */
/* -------------------------------------------------------------------------- */

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
