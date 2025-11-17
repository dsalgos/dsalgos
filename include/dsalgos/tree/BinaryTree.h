#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <tree/Tree.h>
#include <tree/BinaryTreeNode.h>

namespace dsalgo
{
    /**
     * @brief A Binary Tree
     *
     * @tparam T The datatype of the keys of the binary tree
     */
    template <typename T>
    class BinaryTree : public Tree<T>
    {
    private:
        BinaryTreeNode<T> *root;
        static void print(const BinaryTreeNode<T> &node);

        // Tree traversals
        void preorder(const BinaryTreeNode<T> &root) const;
        void inorder(const BinaryTreeNode<T> &root) const;
        void postorder(const BinaryTreeNode<T> &root) const;

    public:
        BinaryTree(const BinaryTreeNode<T> &tn);
        void preorder() const override;
        void inorder() const override;
        void postorder() const override;
    };

    // Template deduction guide for automatic type inference
    template <typename T>
    BinaryTree(const BinaryTreeNode<T> &) -> BinaryTree<T>;
}

#endif