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
#define inf 1e18
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define yes cout << "YES\n"
#define no cout << "NO\n"

const ll N=510;
ll cst[N][N];
vector<pair<int,int>> graph[N];
// Function to perform Dijkstra's algorithm
void Dijkstra(int n, int source, vector<int>& distances) {
    // Initialize distances with infinity
    distances.assign(n, numeric_limits<int>::max());
    forn(i,n)
        cst[source][i]=inf;
    cst[source][source]=0;
    // Create a priority queue of pairs (distance, vertex)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Enqueue the source vertex with distance 0
    pq.emplace(0, source);
    distances[source] = 0;

    while (!pq.empty()) {
        int dist = pq.top().first;
        int u = pq.top().second;

        dist*=-1;
        pq.pop();

        // Skip if the distance to u is already greater than the current distance
        if (cst[source][u]!=dist) {
            continue;
        }

        // Explore all neighboring vertices of u
        for (auto child : graph[u]) {
            int x=child.first, y=child.second;
            int newDist = dist + y;

            // Update the distance if a shorter path is found
            if (newDist < cst[source][x]) {
                cst[source][x]=newDist;
                pq.emplace(-cst[source][x], x);
            }
        }
    }
}

int main() {
    int n = 6; // Number of vertices

    // Example graph represented as an adjacency matrix
    vector<vector<int>> graph = {
        {0, 4, 0, 0, 0, 0},
        {4, 0, 8, 0, 0, 0},
        {0, 8, 0, 7, 0, 4},
        {0, 0, 7, 0, 9, 14},
        {0, 0, 0, 9, 0, 10},
        {0, 0, 4, 14, 10, 0}
    };

    int source = 0; // Source vertex

    vector<int> distances;
    Dijkstra(graph, source, distances);

    // Print the distances from the source vertex
    for (int i = 0; i < n; i++) {
        cout << "Distance from vertex " << source << " to vertex " << i << ": " << distances[i] << endl;
    }

    return 0;
}
