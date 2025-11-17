#ifndef NODE_H
#define NODE_H

#include <string>

namespace dsalgo {
class Node {
  private:
    std::string label;

  public:
    Node();

    std::string getLabel() const;
    void        setLabel(const std::string& newLabel);
};

std::ostream& operator<<(std::ostream& os, const Node& node);
} // namespace dsalgo

#endif