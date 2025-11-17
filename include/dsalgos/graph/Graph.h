#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

namespace dsalgo
{
    /**
     * @brief An implementation of the Graph data type using an adjancency list
     *
     */
    class Graph
    {
    private:
        std::vector<std::vector<int>> *adjacency; // Adjacency list
        int size;                                 // Number of nodes in the graph

    public:
        /**
         * @brief Construct a new Graph object
         *
         */
        Graph();

        /**
         * @brief Construct a new Graph object
         *
         * @param n Number of nodes to added into the graph
         */
        Graph(int n);

        /**
         * @brief Add edge to the graph
         *
         * @param src Source node
         * @param dest Destination node
         */
        void addEdge(int src, int dest);

        /**
         * @brief Print the adjacency list of the graph
         *
         * @note Side-Effect(s): Prints to the stdout stream
         */
        void printAdjacencyList() const;

        /* Traversal algorithms */

        /**
         * @brief Print BFS traversal of the graph
         *
         * @param src Source node for the traversal
         * @note Side-Effect: Prints to the stdout stream
         */
        void bfs(int src) const;

        /**
         * @brief Print the DFS traversal of the graph
         *
         * @param src Source node for the traversal
         * @note Side-Effect(s): Prints to the stdout stream
         */
        void dfs(int src) const;

        /* Other algorithms */

        /**
         * @brief Find the shortest path from a given node to all other nodes using the Dijkstra's algorithm
         *
         */
        void dijkstra(int src) const
        {
            constexpr int maxDistance = 10000;

            // Maintain a vector of distances
            std::vector<int> distances = std::vector<int>(this->size, maxDistance);
            distances[src] = 0; // distance from the source to the source itself is 0

            // Maintain a vector for which nodes have been visited
            std::vector<bool> visited = std::vector<bool>(this->size, false);
            visited[src] = true;

            // Assign distances to each of the

            int closestNode = -1;
            int minDistance = -1;
            for (int i = 0; i < distances.size(); i++)
            {
                int distance = distances[i];
                if (distance < minDistance && !visited[i])
                {
                    minDistance = distance;
                    closestNode = i;
                }
            }
        }
    };
}

#endif