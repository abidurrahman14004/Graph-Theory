

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Graph {
private:
    unordered_map<int, vector<int>> adjacency_list;

public:
    void addVertex(int vertex) {
        // Add vertex if not already present
        if (adjacency_list.find(vertex) == adjacency_list.end()) {
            adjacency_list[vertex] = vector<int>();
        }
    }

    void addEdge(int vertex1, int vertex2) {
        // Assuming an undirected graph
        adjacency_list[vertex1].push_back(vertex2);
        adjacency_list[vertex2].push_back(vertex1);
    }

    void printGraph() {
        for (const auto& pair : adjacency_list) {
            cout << pair.first << " -> ";
            for (int neighbor : pair.second) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph graph;
    graph.addVertex(1);
    graph.addVertex(2);
    graph.addVertex(3);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);

    graph.printGraph();

    return 0;
}
