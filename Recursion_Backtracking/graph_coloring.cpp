#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

void addEdge(vector<vector<int>>& graph, int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void printSolution(const vector<int>& color) {
    cout << "Vertex\tColor" << endl;
    for (size_t vertex = 0; vertex < color.size(); ++vertex) {
        cout << vertex << "\t" << color[vertex] << endl;
    }
}

bool isSafe(int vertex, int c, const vector<vector<int>>& graph, const vector<int>& color) {
    for (int neighbor : graph[vertex]) {
        if (color[neighbor] == c) {
            return false;
        }
    }
    return true;
}

bool graphColoring(int m, vector<int>& color, int vertex, const vector<vector<int>>& graph) {
    if (vertex == color.size()) { //last vertex reached
        return true;
    }

    for (int c = 1; c <= m; ++c) {
        if (isSafe(vertex, c, graph, color)) {
            color[vertex] = c;
            if (graphColoring(m, color, vertex + 1, graph)) {
                return true;
            }
            color[vertex] = 0; // Backtrack
        }
    }

    return false;
}

int main() {
    int vertices = 5;
    vector<vector<int>> graph(vertices);
    vector<int> color(vertices, 0);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    int numColors = 3; // Change this to the desired number of colors
    if (graphColoring(numColors, color, 0, graph)) {
        cout << "Solution exists: " << endl;
        printSolution(color);
    } else {
        cout << "Solution does not exist." << endl;
    }

    return 0;
}
