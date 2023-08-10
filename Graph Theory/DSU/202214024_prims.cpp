
// Kruskal's algorithm in C++

#include <bits/stdc++.h>
using namespace std;

#define edge pair<int, int>

class Graph {
   private:
  vector<pair<int, edge> > G;  // graph
  map<int,vector<edge>> g;
  vector<pair<int, edge> > T;  // mst
  map<int,vector<edge>> t;
  //set<pair<int,int>> mstSet;
  int *parent;
  int V;  // number of vertices/nodes in graph
   public:
  Graph(int V);
  void AddWeightedEdge(int u, int v, int w);
  int find_set(int i);
  void union_set(int u, int v);
  void kruskal();
  void primsInit(Graph* g);
  vector<int> prims(int src, int sWt);
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
  g[u].push_back({w,v});
  g[v].push_back({w,u});
}
int Graph::find_set(int i) {
// If i is the parent of itself
  if (i == parent[i]) return i;
// Else if i is not the parent of itself Then i is not the representative of his set, so we recursively call Find on its parent
  return find_set(parent[i]);
}

/*
prim(graph):
    # Initialize an empty set to hold the vertices in the minimum spanning tree
    mst = empty set

    # Select the first vertex to start the tree
    startVertex = first vertex in graph
    mst.add(startVertex)

    # Initialize the set of edges to consider
    edges = edges connected to startVertex

    # Iterate until all vertices are in the minimum spanning tree
    while mst has fewer vertices than graph:
        # Find the minimum edge in the set of edges
        minEdge, minWeight = findMinEdge(edges)

        # Add the vertex to the minimum spanning tree
        mst.add(minEdge)

        # Add the edges connected to the vertex to the set of edges to consider
        for edge in edges connected to minEdge:
            if edge is not in mst:
                edges.add(edge)

        # Remove the minimum edge from the set of edges to consider
        edges.remove(minEdge)

    # Return the minimum spanning tree as an array
    return mst as an array
*/


vector<int> Graph::prims(int src, int sWt)
{

    vector<int> visited(V,0);
    vector<int> par(V,0);
    vector<int> ans;
    int sum=0;
    priority_queue<pair<int,int>> pq;
    pq.push({sWt,src});
    visited[src]=1;

    while(!pq.empty())
    {
        pair<int,int> top = pq.top();
        pq.pop();

        int node=top.second,wt=top.first;

        if(visited[node]) continue;
        visited[node]=1;
        sum+=wt;

        //t.push_back({node,wt}); //alt approach
        ans.push_back(node);

        for(auto i:g[node])
        {
            int v=i.second,wt=i.first;
            if(!visited[v])
            {
                visited[v]=1;
                //t.push_back(i);
                pq.push({wt,v});

            }
        }
    }
    return ans;
}

void Graph::primsInit(Graph* g)
{
    int edges; cin >> edges;
    int src,mn=INT_MAX;

    for (int i = 0; i < edges; ++i)
    {
        int u,v,w; cin >> u >> v >> w;
        g->AddWeightedEdge(u,v,w);

        if(w<mn) //finding the minimum weight
        {
            mn=w;
            src=u;
        }

    }
    vector<int> ans= g->prims(src, mn);
    for(auto i:ans) cout << i;
    cout<<endl;
} 


void Graph::union_set(int u, int v) {
  parent[u] = parent[v];
}


/* 
class Prims
{
    map<int, vector<pair<int, int>>> graph;
    map<int, int> visited;

public:
    void addEdge(int u, int v, int w)
    {
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    vector<int> path(pair<int, int> start)
    {
        vector<int> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // cost vs node
        pq.push({start.second, start.first});
        while (!pq.empty())
        {
            pair<int, int> curr = pq.top();
            pq.pop();
            if (visited[curr.second])
                continue;
            visited[curr.second] = 1;
            ans.push_back(curr.second);
            for (auto i : graph[curr.second])
            {
                if (visited[i.first])
                    continue;
                pq.push({i.second, i.first});
            }
        }
        return ans;
    }
};
int main()
{
    Prims p;
    int edges;
    cin >> edges;
    int srcU, mn = INT_MAX;
    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        if (w < mn)
        {
            mn = w;
            srcU = u;
        }
        p.addEdge(u, v, w);
    }

    vector<int> ans = p.path({srcU, 0}); // (node, cost)
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
}

*/

/*
const int MAX = 1e4 + 5;
typedef pair<long long, int> PII;
bool marked[MAX];
vector <PII> adj[MAX];

long long prim(int x)
{
    priority_queue<PII, vector<PII>, greater<PII> > Q;
    int y;
    long long minimumCost = 0;
    PII p;
    Q.push(make_pair(0, x));
    while(!Q.empty())
    {
        // Select the edge with minimum weight
        p = Q.top();
        Q.pop();
        x = p.second;
        // Checking for cycle
        if(marked[x] == true)
            continue;
        minimumCost += p.first;
        marked[x] = true;
        for(int i = 0;i < adj[x].size();++i)
        {
            y = adj[x][i].second;
            if(marked[y] == false)
                Q.push(adj[x][i]);
        }
    }
    return minimumCost;
}

int main()
{
    int nodes, edges, x, y;
    long long weight, minimumCost;
    cin >> nodes >> edges;
    for(int i = 0;i < edges;++i)
    {
        cin >> x >> y >> weight;
        adj[x].push_back(make_pair(weight, y));
        adj[y].push_back(make_pair(weight, x));
    }
    // Selecting 1 as the starting node
    minimumCost = prim(1);
    cout << minimumCost << endl;
    return 0;
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
  /*Graph g(5);
  g.AddWeightedEdge(0, 1, 2);
  g.AddWeightedEdge(0, 2, 1);
  g.AddWeightedEdge(0, 3, 4);
  g.AddWeightedEdge(1, 2, 2);
  g.AddWeightedEdge(2, 3, 3);
  g.AddWeightedEdge(2, 4, 4);
  g.AddWeightedEdge(3, 1, 3);
  g.AddWeightedEdge(1, 4, 1);
  g.kruskal();
  g.print();*/

  Graph p(8);
  int edges; cin >> edges;
    int src,mn=INT_MAX;

    for (int i = 0; i < edges; ++i)
    {
        int u,v,w; cin >> u >> v >> w;
        p.AddWeightedEdge(u,v,w);

        if(w<mn) //finding the minimum weight
        {
            mn=w;
            src=u;
        }

    }
    vector<int> ans= p.prims(src, mn);
    for(auto i:ans) cout << i;
    cout<<endl;

  return 0;
}