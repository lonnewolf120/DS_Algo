
// Kruskal's algorithm in C++

#include <bits/stdc++.h>
using namespace std;

#define edge pair<int, int>

class Graph {
   private:
  vector<pair<int, edge> > G;  // graph
  vector<pair<int, edge> > T;  // mst
  //set<pair<int,int>> mstSet;
  int *parent;
  int V;  // number of vertices/nodes in graph
   public:
  Graph(int V);
  void AddWeightedEdge(int u, int v, int w);
  int find_set(int i);
  void union_set(int u, int v);
  void kruskal();
  void prims();
  void print();
};
Graph::Graph(int V) {
  parent = new int[V];

  //i 0 1 2 3 4 5
  //parent[i] 0 1 2 3 4 5
  for (int i = 0; i < V; i++)
    parent[i] = i;

  G.clear();
  T.clear();
}
void Graph::AddWeightedEdge(int u, int v, int w) {
  G.push_back({w,{u,v}});
}
int Graph::find_set(int i) {
// If i is the parent of itself
  if (i == parent[i]) return i;
// Else if i is not the parent of itself Then i is not the representative of his set, so we recursively call Find on its parent
  return find_set(parent[i]);
}



void Graph::union_set(int u, int v) {
  parent[u] = parent[v];
}
/* 
declare vector<int> size(N,0);
void Graph::union_set_bySize(int u, int v) {
  if(u!=v)
  {
      if(size[v]>size[u]) swap(v,u);
      parent[v] = u; //parent of small will be the bigger one
      size[u]+=size[u=v]; //now that we merged them
  }
}
*/
int totalcst=0;
void Graph::kruskal() {
  int i, uRep, vRep;
  sort(G.begin(), G.end());  // increasing weight

  for (auto &i:G) {
    int u=i.second.first;
    int v=i.second.second;
    int wt=i.first;
  
    uRep = find_set(u);
    vRep = find_set(v);
    if (uRep != vRep) { //if their parents arent the same so they're not forming a cycle
      T.push_back(i);  // add to tree
      union_set(uRep, vRep); //join the graph
      totalcst+=wt;
    }
  }
} 
void Graph::print() {
  cout << "Edge :"
     << " Weight" << endl;
  for (int i = 0; i < T.size(); i++) {
    cout << T[i].second.first << " - " << T[i].second.second << " : "
       << T[i].first << endl;
    
  }
  cout << endl << totalcst << endl;
}
int main() {
  Graph g(5);
  /*g.AddWeightedEdge(0, 1, 2);
  g.AddWeightedEdge(0, 2, 1);
  g.AddWeightedEdge(0, 3, 4);
  g.AddWeightedEdge(1, 2, 2);
  g.AddWeightedEdge(2, 3, 3);
  g.AddWeightedEdge(2, 4, 4);
  g.AddWeightedEdge(3, 1, 3);
  g.AddWeightedEdge(1, 4, 1);*/
  g.AddWeightedEdge(0, 1, 4);
  g.AddWeightedEdge(0, 2, 4);
  g.AddWeightedEdge(1, 2, 2);
  g.AddWeightedEdge(1, 0, 4);
  g.AddWeightedEdge(2, 0, 4);
  g.AddWeightedEdge(2, 1, 2);
  g.AddWeightedEdge(2, 3, 3);
  g.AddWeightedEdge(2, 5, 2);
  g.AddWeightedEdge(2, 4, 4);
  g.AddWeightedEdge(3, 2, 3);
  g.AddWeightedEdge(3, 4, 3);
  g.AddWeightedEdge(4, 2, 4);
  g.AddWeightedEdge(4, 3, 3);
  g.AddWeightedEdge(5, 2, 2);
  g.AddWeightedEdge(5, 4, 3);
  g.kruskal();
  g.print();
  return 0;
}

/*  g.AddWeightedEdge(0, 1, 4);
  g.AddWeightedEdge(0, 2, 4);
  g.AddWeightedEdge(1, 2, 2);
  g.AddWeightedEdge(1, 0, 4);
  g.AddWeightedEdge(2, 0, 4);
  g.AddWeightedEdge(2, 1, 2);
  g.AddWeightedEdge(2, 3, 3);
  g.AddWeightedEdge(2, 5, 2);
  g.AddWeightedEdge(2, 4, 4);
  g.AddWeightedEdge(3, 2, 3);
  g.AddWeightedEdge(3, 4, 3);
  g.AddWeightedEdge(4, 2, 4);
  g.AddWeightedEdge(4, 3, 3);
  g.AddWeightedEdge(5, 2, 2);
  g.AddWeightedEdge(5, 4, 3);*/
