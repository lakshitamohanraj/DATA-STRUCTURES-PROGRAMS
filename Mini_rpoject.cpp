#include <iostream>
#include <vector>
#include <queue>
#include <limits>

const int INF = std::numeric_limits<int>::max();

// Edge structure representing an edge between two nodes with a weight
struct Edge {
    int destination;
    int weight;
};

// Graph class representing the non-linear ADT graph
class Graph {
public:
    explicit Graph(int numNodes) : adjacencyList(numNodes) {}

    // Add an edge between two nodes with a weight
    void addEdge(int source, int destination, int weight) {
        adjacencyList[source].push_back({destination, weight});
        adjacencyList[destination].push_back({source, weight});
    }

    // Find the shortest path from the source node to all other nodes
    std::vector<int> findShortestPath(int source) {
        std::vector<int> distance(adjacencyList.size(), INF);
        distance[source] = 0;

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
        pq.push({0, source});

        while (!pq.empty()) {
            int currNode = pq.top().second;
            int currDist = pq.top().first;
            pq.pop();

            if (currDist > distance[currNode]) {
                continue;
            }

            for (const auto& edge : adjacencyList[currNode]) {
                int newDist = currDist + edge.weight;
                if (newDist < distance[edge.destination]) {
                    distance[edge.destination] = newDist;
                    pq.push({newDist, edge.destination});
                }
            }
        }

        return distance;
    }

private:
    std::vector<std::vector<Edge>> adjacencyList;
};

int main() {
    int numNodes = 5;
    Graph graph(numNodes);

    // Add edges between nodes with weights representing the traffic situation
    graph.addEdge(0, 1, 3);
    graph.addEdge(0, 2, 5);
    graph.addEdge(1, 2, 2);
    graph.addEdge(1, 3, 6);
    graph.addEdge(2, 3, 4);
    graph.addEdge(2, 4, 7);
    graph.addEdge(3, 4, 1);

    int sourceNode = 0;
    std::vector<int> shortestPath = graph.findShortestPath(sourceNode);

    // Display the shortest path distances from the source node to all other nodes
    for (int i = 0; i < numNodes; ++i) {
        std::cout << "Shortest path distance from node " << sourceNode << " to node " << i << ": ";
        if (shortestPath[i] == INF) {
            std::cout << "Not reachable" << std::endl;
        } else {
            std::cout << shortestPath[i] << std::endl;
        }
    }

    return 0;
}
