#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <iostream>
#include <tree/Tree.h>

namespace dsalgo
{
    template <typename T>
    class Heap : public Tree<T>
    {
        std::vector<T> arr; // to store the elements
        size_t len;

    private:
        /**
         * @brief Convert the internal vector into a heap object (assuming max-heap)
         *
         */
        void heapify();

        /**
         * @brief Helper function to maintain heap property by sifting down
         *
         * @param i Index to start sifting down from
         */
        void siftDown(size_t i);

        /**
         * @brief Helper function to maintain heap property by sifting up
         *
         * @param i Index to start sifting up from
         */
        void siftUp(size_t i);

    public:
        /**
         * @brief Construct a new Heap object (empty)
         *
         */
        Heap();

        /**
         * @brief Construct a new Heap object from an std::vector
         *
         * @param arr The vector that needs to be converted into a heap
         */
        Heap(const std::vector<T> &input_arr);

        /**
         * @brief Insert a new element into the heap
         *
         * @param data The data to insert
         */
        void insert(T data);

        /**
         * @brief Remove and return the root element (max element for max-heap)
         *
         * @return T The root element
         */
        T extractMax();

        /**
         * @brief Get the size of the heap
         *
         * @return size_t The number of elements
         */
        size_t size() const;

        /**
         * @brief Check if the heap is empty
         *
         * @return true if empty, false otherwise
         */
        bool empty() const;

        /**
         * @brief Print heap elements in order (level-order traversal)
         */
        void preorder() const override;
        void inorder() const override;
        void postorder() const override;

        template <typename U>
        friend std::ostream &operator<<(std::ostream &os, const Heap<U> &heap);
    };
}

#endif