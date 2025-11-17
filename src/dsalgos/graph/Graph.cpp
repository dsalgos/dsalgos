// Header to be implemented
#include <dsalgos/graph/Graph.h>

// External dependencies
#include <iostream>
#include <queue>
#include <vector>

namespace dsalgo {
/* Constructors */

/**
 * @brief Construct a new Graph object
 *
 * @param n Number of nodes to added into the graph
 */
Graph::Graph() {
    this->adjacency = new std::vector<std::vector<int>>(0);
    this->size      = 0;
}

/**
 * @brief Construct a new Graph object with the specified number of nodes labelled 1 to n
 *
 * @param n The number of nodes the Graph object should have
 */
Graph::Graph(int n) {
    this->adjacency = new std::vector<std::vector<int>>(n);
    this->size      = n;
}

/**
 * @brief Add edge to the graph
 *
 * @param src Source node
 * @param dest Destination node
 */
void Graph::addEdge(int src, int dest) {
    this->adjacency->at(src).push_back(dest);
    this->adjacency->at(dest).push_back(src);
}

/**
 * @brief Print the adjacency list of the graph
 *
 * @note Side-Effect(s): Prints to the stdout stream
 */
void Graph::printAdjacencyList() const {
    std::cout << "Adjacency List: " << "\n";

    for (int i = 0; i < this->size; i++) {
        std::cout << "Neighbours of node " << i << " : " << "\t";

        for (int neighbour : this->adjacency->at(i))
            std::cout << neighbour << " ";

        std::cout << std::endl;
    }
}

/**
 * @brief Print BFS traversal of the graph
 *
 * @param src Source node for the traversal
 * @note Side-Effect: Prints to the stdout stream
 */
void Graph::bfs(int src) const {
    // Maintain a visited vector
    std::vector<bool>* visited = new std::vector<bool>(this->size, false);

    /**
     * Approach:
     *
     * 0. Enqueue the src node
     * 1. Visit the src node
     * 2. Iterate over the neighbours of the src node
     * 3. For each node, check if it is already visited
     * 4. If it is not already visited, enqueue it
     * 5. Otherwise, just ignore it
     */

    std::queue<int> queue;

    queue.push(src);
    visited->at(src) = true;

    while (!queue.empty()) {
        int curr = queue.front();

        /* Visit the node now: */
        std::cout << curr << " ";

        queue.pop();

        for (int neighbour : this->adjacency->at(curr)) {
            if (!visited->at(neighbour)) {
                visited->at(neighbour) = true;
                queue.push(neighbour);
            }
        }
    }

    std::cout << std::endl;

    delete visited;
}
} // namespace dsalgo