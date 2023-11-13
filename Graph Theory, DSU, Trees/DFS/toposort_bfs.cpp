#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

vector<int> topologicalSort(map<int, vector<int>>& graph) {
    int V = graph.size();
    vector<int> inDegree(V, 0);

    for (const auto& entry : graph) {
        int node = entry.first;
        const vector<int>& neighbors = entry.second;
        for (int neighbor : neighbors) {
            inDegree[neighbor]++;
        }
    }

    queue<int> q;
    for (const auto& entry : graph) {
        int node = entry.first;
        if (inDegree[node] == 0) {
            q.push(node);
        }
    }

    vector<int> result;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);

        for (int neighbor : graph[node]) {
            if (--inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    if (result.size() != V) {
        // Graph has a cycle
        cout<<"Graph is not a DAG\n";
    }

    return result;
}

int main() {
    map<int, vector<int>> graph;

    int n,e; cin>>n>>e;
    for (int i = 0; i < e; ++i)
    {
        int u,v; cin>>u>>v;
        graph[u].push_back(v);
    }
    // graph[5] = {2, 0};
    // graph[4] = {0, 1};
    // graph[2] = {3};
    // graph[3] = {1};

    vector<int> topologicalOrder = topologicalSort(graph);

    cout << "Topological Ordering: ";
    for (int node : topologicalOrder) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
