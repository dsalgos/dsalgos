// Header to be implemented
#include <dsalgos/graph/Node.h>

// External dependencies
#include <string>

namespace dsalgo {
Node::Node() = default;

std::string Node::getLabel() const {
    return this->label;
}

void Node::setLabel(const std::string& newLabel) {
    this->label = newLabel;
}

/**
 * @brief Print the Node's label
 *
 * @param os Output stream
 * @param node Node to be printed
 * @return std::ostream& Reference to the output stream
 */
std::ostream& operator<<(std::ostream& os, const Node& node) {
    os << node.getLabel();
    return os;
}
} // namespace dsalgo