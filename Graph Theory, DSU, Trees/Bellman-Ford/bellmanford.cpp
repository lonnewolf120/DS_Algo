#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <C:\D Drive\Projects\debug2.h>
using namespace std;
   
typedef long long ll;
typedef long double ld;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i <= e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define yes cout << "YES\n"
#define no cout << "NO\n"

vector<tuple<int,int,int>> graph;
map<int, pair<int,int>> g; //another way
map<int, int> parent;
map<int, int> dist;

bool bellman(int vsize, int source) {
    // Initialize distances
    for (int i = 1; i <= vsize; i++) {
        dist[i] = (i == source) ? 0 : INT_MAX;
    }

    for (int i = 0; i < vsize - 1; ++i) {
        for (auto t : graph) {
            int u = get<0>(t), v = get<1>(t), wt = get<2>(t);

            if (dist[v] > dist[u] + wt) {
                dist[v] = dist[u] + wt;
                parent[v] = u;
            }
        }
    }

    for (auto t : graph) {
        int u = get<0>(t), v = get<1>(t), wt = get<2>(t);

        if (dist[v] > dist[u] + wt) {
            return false; // Negative weight cycle detected
        }
    }

    return true;
}

int main()
{
    fastio
    ll v,e;
    cin >> v >> e;
    graph.clear();
    parent.clear();
    dist.clear();
    for(int it=1;it<=e;it++) {
	     int u,v,w; cin>>u>>v>>w;
         graph.push_back(make_tuple(u,v,w));
         // graph.push_back(make_tuple(v,u,w));
    }
    bool b = bellman(v,1);
    cout<< "Negative Edge Cycle: " << (b?"YES\n":"NO\n");
    if(b)
    {
        cout<<"U\t"<<"V\t"<<"DIST\n";
    	for(auto t:graph)
    	{
        int u = get<0>(t), v = get<1>(t), wt = get<2>(t);
        cout<<u<<"\t"<<v<<"\t"<<dist[v]<<ln;
    	}
    }
    return 0;
}