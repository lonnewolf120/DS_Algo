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
#define forsn(i,s,e) for(ll i = s; i < e; i++)
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

/*DFS on tree
const int N = 1e3+10;
vector<int> tree[N];
void dfs1(int vertex, int parent)
{
   for(auto child:tree[vertex]) //go to each child subtree and run dfs again
   {
      if(child!=parent) dfs1(child,vertex);
   }
}
*/
const int N=1e3+10;
int visited[N]={0};
int color[N]={0};
int level[N];
vector<int> g[N];
map<int, vector<int>> graph;
map<int,int> vis;
map<int, int> lvl;
map<int, int> parent;

/*
void bfs1(int src)
{
	queue<int> q;
	q.push(src);
	lvl[src]=1;	//for tree
	//vis[src]=1; 
	//color[src]=1;//make the node grey
	while(!q.empty())
	{
		int t = q.front(); q.pop();
		vis[src]=1; color[src]=1;
		for(auto child: graph[t])
		{
			if(!vis[child])
			{
				q.push(child);
				vis[src]=1; color[src]=1;
				lvl[child]=lvl[t]+1;
			}
		}
		color[src]=2; //make the node black
	}
	
}
*/

void bfs(int source)
{
	queue<int> q;
	q.push(source);
	visited[source] = true;
	level[source]=0;
	parent[source]=0;

	while(!q.empty())
	{
		int cur_v = q.front();
		q.pop();
		for(auto child:graph[cur_v])
		{
			if(!visited[child])
			{
				q.push(child);
				visited[child]=true;
				//lvl[c]
				level[child]= level[cur_v]+1;
				parent[child]=cur_v;
			}
		}
	}
}

void solve()
{
	ll n,e; cin >>n>>e;
    forn(i,e)
    {
    	int x,y;cin >> x >> y;
    	graph[x].pb(y);
    	graph[y].pb(x);
    }
    bfs(1);
    for (int i = 1; i <= n; ++i)
    {
    	cout << i << " " << level[i]<< " " << parent[i] << ln;
    }

}
int main()
{
    fastio
    solve();
    return 0;
}