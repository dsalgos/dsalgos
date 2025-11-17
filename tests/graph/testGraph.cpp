// Internal dependencies
#include <dsalgos/graph/Graph.h>

// External dependencies
#include <iostream>

int main() {
    dsalgo::Graph* g = new dsalgo::Graph(7);
    g->addEdge(0, 1);
    g->addEdge(0, 4);
    g->addEdge(4, 3);
    g->addEdge(3, 5);
    g->addEdge(1, 3);
    g->addEdge(1, 2);
    g->addEdge(2, 6);

    // Print the adjacency list
    g->printAdjacencyList();

    // Peform bfs on the graph
    std::cout << "\n";
    std::cout << "BFS traversal of the graph from node 1: " << "\n";
    g->bfs(1);

    return 0;
}