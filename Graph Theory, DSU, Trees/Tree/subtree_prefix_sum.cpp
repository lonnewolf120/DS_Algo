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
   
const int N = 1e3+10;
vector<int> tree[N];
int subtree[N];
int val[N];
bool visited[N];
void dfs1(int vertex)
{
	subtree[vertex]+= vertex; //here value of vertex = vertex, but when value of vertex is given take those values 
	
	visited[vertex] = true;	
	for(auto child:tree[vertex]) //so only keeping track of whether we're going towards child nodes or not is enough
	{
		if(!visited[child]) //can be replaced with if(child!=parent) works well
	    {
	    	dfs1(child);
	    	subtree[vertex]+=subtree[child];
	    }
	}
}
void dfs2(int vertex, int parent=0)
{
	subtree[vertex]+= vertex; 
	//we dont need to keep track of visited as this is a tree (but it can be done too, works well)
	for(auto child:tree[vertex]) //so only keeping track of whether we're going towards child nodes or not is enough
	{
		if(child!=parent)
	    {
	    	dfs2(child,vertex);
	    	subtree[vertex]+=subtree[child];
	    }
	}
}
void dfs3(int vertex, int parent=0)
{
	subtree[vertex]+= val[vertex]; //value of vertex can also be in map 
	for(auto child:tree[vertex]) 
	{
		if(child!=parent)
	    {
	    	dfs3(child,vertex);
	    	subtree[vertex]+=subtree[child];
	    }
	}
}
int main()
{
    fastio
    ll t; cin >>t;
    //l=0;
    forn(i,t)
    {
    	int x,y;cin >> x >> y;
    	tree[x].pb(y);
    	tree[y].pb(x);
    }
    dfs1(1);
    int q; cin >> q;
    while(q--)
    {
    	int x; cin >> x;
    	cout << subtree[x] <<ln;
    }
    return 0;
}