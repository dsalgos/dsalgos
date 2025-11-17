#ifndef PATH_H
#define PATH_H

// External dependencies
#include <vector>

// Internal dependencies
#include "Node.h"

namespace dsalgo
{
    class Path
    {
    private:
        std::vector<Node> path;

    public:
        Path();

        Path &addNode(const Node &newNode);
        Path &operator+=(const Node &newNode);

        friend std::ostream &operator<<(std::ostream &os, const Path &path);
    };
}

#endif