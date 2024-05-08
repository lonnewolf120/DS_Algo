#include <bits/stdc++.h>
// #include "debug.h"
using namespace std;

#define int long long
#define float long double
#define pb push_back
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
int inf = 1e18;

typedef pair<int, pair<int, int>> pairUV;

int find(int node, vector<int>& parent) {
    if (parent[node] == node)
        return node;
    return parent[node] = find(parent[node], parent);
}

void unionNodes(int u, int v, vector<int>& parent) {
    u = find(u, parent);
    v = find(v, parent);
    if (u != v)
        parent[u] = parent[v];
}

void solve()
{
    int n, e, u, v;
    cin >> n >> e;
    //vector<vector<pair<int, int>>> adj(n + 1);
    vector<vector<bool>> mark(n + 1, vector<bool>(n + 1, false));
    vector<pairUV> edges;
    for (int i = 0; i < e; i++)
    {
        int wt;
        cin >> u >> v >> wt;
        //adj[u].push_back({v, wt});
        //adj[v].push_back({u, wt});
        mark[u][v] = mark[v][u] = true;
        edges.push_back({wt, {u, v}});
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (!mark[i][j])
            {
                //adj[i].push_back({j, (abs(j - i))}); 
                mark[i][j] = true;
                edges.push_back({(abs(j - i)), {i,j}});
            }
            if (!mark[j][i])
            {
                //adj[j].push_back({i, (abs(j - i))}); 
                mark[j][i] = true;
                edges.push_back({(abs(j - i)), {j,i}});

            }
        }
    }
    int sum = 0, c = 0;
    vector<pairUV> ans;
    sort(vf(edges));
    vector<int> parent(n + 1);
    for (int i = 0; i < n; i++)
        parent[i] = i;
    for (auto edge : edges) {
        int wt = edge.first;
        u = edge.second.first;
        v = edge.second.second;
        int uRep=find(u, parent);
        int vRep=find(v, parent);
        if (uRep != vRep) {
            sum += wt;
            ans.push_back({wt, {u, v}});
            unionNodes(u, v, parent);
        }
    }
   for(auto i:ans)
        cout<<i.first<<" "<<i.second.first << " " << i.second.second<<endl;
    cout << sum << endl;
}

int32_t main()
{
    fastio;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
