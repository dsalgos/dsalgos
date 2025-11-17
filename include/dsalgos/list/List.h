#ifndef LIST_H
#define LIST_H

#include <vector>

/**
 * @brief For now, this class is just a wrapper around the built-in vector class
 * Although this should ideally be created using a list
 */

template <typename T>
class List
{
public:
    List();
    std::vector<T> elements; // to store the elements in the list

    /* Getter functions */
};

#endif LIST_H