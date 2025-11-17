// Header file to be implemented
#include <dsalgos/Record.h>

// External dependencies
#include <iostream>

namespace dsalgo {

/* Constructors */

/**
 * @brief Construct a new Record< T>:: Record object
 *
 * @tparam T The data type of the Record object
 */
template <typename T> Record<T>::Record() = default;

/**
 * @brief Construct a new Record< T>:: Record object
 *
 * @tparam T The data type of the Record object
 * @param data The data to be stored
 */
template <typename T> Record<T>::Record(T data) {
    this->id   = 0;
    this->data = data;
}

/**
 * @brief Construct a new Record< T>:: Record object
 *
 * @tparam T The data type of the Record object
 * @param id ID of the Record
 * @param data Data to be stored
 */
template <typename T> Record<T>::Record(int id, T data) {
    this->id   = id;
    this->data = data;
}

/* Getters */

/**
 * @brief Get the ID of the record
 *
 * @tparam T The data type of the Record object
 * @return int ID of the record object
 */
template <typename T> int Record<T>::getID() const {
    return this->id;
}

/**
 * @brief Get the data of the record
 *
 * @tparam T The data type of the Record object
 * @return T The data stored in the record
 */
template <typename T> T Record<T>::getData() const {
    return this->data;
}

/**
 * @brief Print the contents of the record
 *
 * @tparam T The data type of the Record object
 * @param os Output stream
 * @param record Record to be printed
 * @return std::ostream& Reference to the output stream
 */
template <typename T> std::ostream& operator<<(std::ostream& os, const Record<T>& record) {
    std::cout << "Data stored in record " << record.getID() << " is " << record.getData();
    return os;
}

/* Explicit template instantiation */
template class Record<int>;
template class Record<float>;
template class Record<double>;

template std::ostream& operator<< <int>(std::ostream&, const Record<int>&);
} // namespace dsalgo
