// Header to be implemented
#include <dsalgos/graph/Path.h>

// External dependencies
#include <iostream>
#include <vector>

namespace dsalgo {
/* Constructor */
Path::Path() = default;

/* Methods */
Path& Path::addNode(const Node& newNode) {
    this->path.push_back(newNode);
    return *this;
}

Path& Path::operator+=(const Node& newNode) {
    return this->addNode(newNode);
}

std::ostream& operator<<(std::ostream& os, const Path& path) {
    int totalNodes = path.path.size();
    for (int i = 0; i < totalNodes; i++) {
        std::cout << path.path[i];

        if (i != totalNodes - 1) {
            // If this is not the last node
            std::cout << " -> ";
        }
    }
    std::cout << std::endl;
    return os;
}
} // namespace dsalgo