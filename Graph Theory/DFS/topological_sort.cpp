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

const int N=10e3;
map<int,vector<int>> graph;
int discovery[N];
int finished[N];
map<int,int> visited;
stack<int> topo_s;

void dfs(int src,int t=1)
{
	visited[src]=1;
	for(auto i:graph[src])
	{
		if(!visited[i])
		{
			discovery[i]=t;
			dfs(i,++t);
		}
	}
	finished[src]=t;
	topo_s.push(src);
}
stack<int> st;
void topo(int src)
{
	st.push(src);
	int t=1;
	visited[src]=1;
	discovery[src]=t++;

	while(!st.empty())
	{
		int top = st.top();
		st.pop();
		for(auto i:graph[top])
		{
			if(!visited[i])
			{
				st.push(i);
				discovery[i]=t++;	
			}
			else finished[i]=(t+1);
		}
	}
}
int main()
{
    fastio
    int n,e; cin >> n >> e;
    forn(i,e)
    {
    	ll u,v; cin >> u >> v;
    	graph[u].pb(v);
    }
    for (int i = 0; i < n; ++i)
    {
    	if(!visited[i])dfs(i);
    }
    while(!topo_s.empty())
    {
    	cout<<topo_s.top()<<" ";
    	st.pop();
    }

    return 0;
}