#include <bits/stdc++.h>
using namespace std;
#define inf 2e9
const int N = 1e3 + 5;
//the graph
vector<pair<int, int>> adj[N];

int weight[N];

//parents where we store the mst
pair<int, int> parent[N];

bool visited[N];

void add_edge(int u, int v, int w) {
  adj[u].push_back({v, w});
  adj[v].push_back({u, w});
}

int prims(int n) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min_heap

  for (int i = 1; i <= n; i++) {
      visited[i] = false;
      weight[i] = inf;
  }

  int src = 1,wt=0;
  weight[src] = 0;
  pq.push({0, src});
  parent[src] = {src, 0};

  while (!pq.empty()) {
      src = pq.top().second;
      pq.pop();

      if (visited[src]) {
          // if node is already visited
          continue;
      }

      visited[src] = true;

      for (auto it : adj[src]) {
          int node = it.first;
          int edge_weight = it.second;

          if (!visited[node] && edge_weight < weight[node]) {
              weight[node] = edge_weight;
              parent[node] = {src, edge_weight};
              pq.push({edge_weight, node});
          }
      }
  }

  int mst_weight = 0;
  for (int i = 1; i <= n; i++) {
      mst_weight += weight[i];
  }
  return mst_weight;
}

int main() {

  int n = 5; // number of nodes

    add_edge(0, 1, 4);
  add_edge(0, 2, 4);
  add_edge(1, 2, 2);
  add_edge(1, 0, 4);
  add_edge(2, 0, 4);
  add_edge(2, 1, 2);
  add_edge(2, 3, 3);
  add_edge(2, 5, 2);
  add_edge(2, 4, 4);
  add_edge(3, 2, 3);
  add_edge(3, 4, 3);
  add_edge(4, 2, 4);
  add_edge(4, 3, 3);
  add_edge(5, 2, 2);
  add_edge(5, 4, 3);
  int mst_weight = prims(n);
  cout << "Minimum Spanning Tree cost will be " << mst_weight << endl;
  cout << "Edges included in the MST are" << endl;
  for (int i = 1; i <= n; i++) {
      if (parent[i].first != i) {
          cout << i << " " << parent[i].first << " " << parent[i].second << endl;
      }
  }

  return 0;
}