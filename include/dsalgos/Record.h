#ifndef RECORD_H
#define RECORD_H

#include <iostream>

namespace dsalgo {
/**
 * @brief A Record object representing the actual data to be stored
 *
 * @tparam T The datatype of the record
 */
template <typename T> class Record {
  private:
    int id;
    T   data;

  public:
    /* Constructor */
    Record();
    Record(T data);
    Record(int id, T data);

    /* Getters */
    int getID() const;
    T   getData() const;

    friend std::ostream& operator<<(std::ostream& os, const Record<T>& record);
};
} // namespace dsalgo

#endif