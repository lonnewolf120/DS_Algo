#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 998244353; // Added 'const' before the MOD variable
const double eps = 1e-12; // Added 'const' before the eps variable
#define forn(i,e) for(int i = 0; i < e; i++) // Changed 'll' to 'int'
#define forsn(i,s,e) for(int i = s; i <= e; i++) // Changed 'll' to 'int'
#define rforn(i,s) for(int i = s; i >= 0; i--) // Changed 'll' to 'int'
#define rforsn(i,s,e) for(int i = s; i >= e; i--) // Changed 'll' to 'int'
#define ln '\n' // Removed the double quotes around '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int N = 10000; // Corrected the format and value of N
map<int, vector<int>> graph;
int discovery[N];
int indegree[N];
int finished[N];
map<int, int> visited;
queue<int> topo_s;
vector<int> tops;

void dfs(int src, int t = 1)
{
    visited[src] = 1;
    for (auto i : graph[src])
    {
        if (!visited[i])
        {
            discovery[i] = t;
            dfs(i, t + 1);
        }
    }
    finished[src] = t;
    topo_s.push(src); //use queue instead for dfs
}

void bfs(int V)
{
    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int node = q.front(); q.pop();
        tops.push_back(node);
        for(auto i:graph[node])
        {
            indegree[i]--;
            if(indegree[i]==0) q.push(i);
        }
    }
}
int cnt=0;
vector<vector<int>> ans;
void all_possible_way(int V, vector<int> cur={})
{
    if(cur.size()==V)
    {
        ans.push_back(cur);
        cnt++;
    }
    for (int i = 0; i < V; ++i) //to generate all possible solutions
    {
        if(indegree[i]==0)
        {
            indegree[i]--;  //to prevent multiple times getting into i
            cur.push_back(i);
            for(auto j:graph[i]) indegree[j]--;
            all_possible_way(V,cur); //to generate all solutions with cur 
        //backtracking
            indegree[i]=0;
            cur.pop_back();
            for(auto j:graph[i]) indegree[j]++;
            // all_possible_way(V,cur); <-- NO NEED as we do recursion un
        }
    }
}
int main()
{
    fastio
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; ++i)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    memset(indegree, 0, sizeof(indegree));
    for (int i = 0; i < n; i++) {
        for (auto it : graph[i]) {
            indegree[it]++;
        }
    }
    all_possible_way(n-1);
    for(auto i:ans)
    {
        for(auto j:i)
            cout<<j<<" ";
        cout<<ln;
    }
    if(cnt==0)
    {
        cout<<"Cycle exists\n";
    }
    // cout<<tops.size()<<ln;
    // for(auto i:tops)
    //     cout<<(char)(i+65)<<" ";
    // cout<<ln;
    return 0;
}
