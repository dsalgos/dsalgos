#ifndef TREE_H
#define TREE_H

namespace dsalgo
{
    /**
     * @brief A Tree class should be able to represent a hierarchical ordering of records, with each node being essentially a box with a key and a pointer to an appropriate record
     *
     * @tparam T The datatype of the keys of the tree
     */
    template <typename T>
    class Tree
    {

    public:
        virtual ~Tree() = default;

        // virtual void insert(const Node<T> &node) = 0;
        // virtual void remove(const T &val) = 0;
        // virtual void remove(const Node<T> &node) = 0;

        virtual void postorder() const = 0;
        virtual void preorder() const = 0;
        virtual void inorder() const = 0;
    };
}

#endif