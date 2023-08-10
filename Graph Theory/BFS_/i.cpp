#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
   
using namespace std;
   
typedef long long ll;
typedef long double ld;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i <= e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define yes cout << "YES\n"
#define no cout << "NO\n"


// Structure to represent a vertex and its corresponding distance
struct Vertex {
    int index;   // Index of the vertex
    int distance; // Distance from the source vertex

    Vertex(int i, int d) : index(i), distance(d) {}

    // Overload the less-than operator for the priority queue
    bool operator<(const Vertex& other) const {
        return distance > other.distance;
    }
};

// Function to perform Dijkstra's algorithm
int Dijkstra(const vector<vector<pair<int, int>>>& graph, int source, int maxDist, const vector<int>& rShops) {
    int n = graph.size();

    //cout << n << ln;
    // Initialize distances with infinity
    vector<vector<int>> distances(n, vector<int>(n + 1, numeric_limits<int>::max()));

    priority_queue<Vertex> pq;

    // Enqueue the source vertex with distance 0
    pq.emplace(source, 0);
    distances[source][0] = 0;

    while (!pq.empty()) {
        Vertex curr = pq.top();
        pq.pop();

        int u = curr.index;
        int dist = curr.distance;

        // Skip if the distance to u is already greater than the current distance
        if (dist > distances[u][rShops[u]]) {
            continue;
        }

        // Explore all neighboring vertices of u
        for (const auto& edge : graph[u]) {
            int v = edge.first;
            int roadDist = edge.second;

            // Skip if the road distance exceeds the maximum travelable distance
            if (roadDist > maxDist) {
                continue;
            }

            int newDist = dist + roadDist;
            int repairShop = rShops[v];

            // If the tire is flat, skip this path
            if (newDist > maxDist && repairShop == 0) {
                continue;
            }

            // Update the distance if a shorter path is found
            if (newDist < distances[v][repairShop]) {
                distances[v][repairShop] = newDist;
                pq.emplace(v, newDist);
            }
        }
    }

    // Find the shortest travelable distance from home to school
    int shortestDistance = numeric_limits<int>::max();
    for (int d = 0; d <= maxDist; d++) {
        if (distances[n - 1][d] < shortestDistance) {
            shortestDistance = distances[n - 1][d];
        }
    }

    return shortestDistance;
}

int main() {
    int n, m, t, d;
    cin >> n >> m >> t >> d;

    vector<int> rShops(t+1);
    for (int i = 0; i < t; i++) {
        int r; cin >> r;
        rShops[r] = 1;
    }
    rShops.pb(n);

    vector<vector<pair<int, int>>> graph(m+1);
    for (int i = 0; i < m; i++) {
        int u, v, dist;
        cin >> u >> v >> dist;
        //cout<< u << " " << v << " " << dist << ln;
        graph[u].push_back({v, dist});
        graph[v].push_back({u, dist});
    }

    int shortestDistance = Dijkstra(graph, 1, d, rShops);
    cout << "Shortest travelable distance: " << shortestDistance << endl;

    return 0;
}
