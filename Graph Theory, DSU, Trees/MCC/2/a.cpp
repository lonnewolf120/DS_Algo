
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

   
map<int, vector<int>> graph;

map<ll,ll> par;

bool bfs(ll sx, vector<bool>&visited)
{
	visited[sx]=true;
	queue<ll> q;
	q.push(sx);
	//par[sx]=sx;

	//level[sx][sy]=0;
	while(!q.empty())
	{
		ll p = q.front();
		q.pop();
		//visited[x][y]=1;
		for(auto i:graph[p])
		{
			if(!visited[i])
			{
				visited[i]=true;
				par[i]=p;
				q.push(i);
			}
			else if(visited[i] && par[p]!=i)
				return true;
		}
	}
	return false;
}
bool isCyclicDisconnected(int V)
{
    // Mark all the vertices as not visited
    vector<bool> visited(V, false);
 
    for (int i = 0; i < V; i++)
        if (!visited[i] && bfs(i, visited))
            return true;
    return false;
}
void solve()
{
	ll n,m; cin >> n >> m;
	//if(m!=(n-1)){no;return;}
	forn(i,m)
	{
		int u,v; cin >> u >> v;
		graph[u].pb(v);
		graph[v].pb(u);
	}
	isCyclicDisconnected(n)?no:yes;
}
int main()
{
    fastio
    ll t=1;
    //cin >> t;
    for(int it=1;it<=t;it++) {
     //cout << "Case " << it << ": ";
        solve();
    }
    return 0;
}