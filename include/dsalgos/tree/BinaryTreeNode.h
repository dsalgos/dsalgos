#ifndef BINARY_TREE_NODE_H
#define BINARY_TREE_NODE_H

// Internal dependencies
#include <Node.h>
#include <Record.h>

namespace dsalgo
{
    /**
     * @brief A node belonging to a tree
     *
     * @tparam T The datatype of the key of node
     */
    template <typename T>
    class BinaryTreeNode : public Node<T>
    {
    private:
        T key;
        const Record<T> *record;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

    public:
        BinaryTreeNode(const Record<T> &record);
        T getKey() const override;
        BinaryTreeNode<T> *getLeft() const;
        BinaryTreeNode<T> *getRight() const;
        BinaryTreeNode<T> *setLeft(const BinaryTreeNode<T> &);
        BinaryTreeNode<T> *setRight(const BinaryTreeNode<T> &);
        const Record<T> *getRecord() const;

        template <typename U>
        friend std::ostream &operator<<(std::ostream &os, const BinaryTreeNode<U> &tn);
    };

    // Template deduction guide for automatic type inference
    template <typename T>
    BinaryTreeNode(const Record<T> &) -> BinaryTreeNode<T>;

}

#endif