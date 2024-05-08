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
int depth[N], depth1[N];
void dfs1(int vertex, int parent=0)
{
	for(auto child:tree[vertex]) //go to each child subtree and run dfs again
	{
        if(child!=parent)
        {
		depth[child] = depth[vertex]+1;
		dfs1(child,vertex);
        }
	}
}

int treeDiameter(int n)
{
	int mx_depth=-1, mx_node;
	dfs1(1);	//dfs from root node
 	for(int i=1; i<=n; ++i)
 	{
 		if(depth[i]>mx_depth)
 		{
 			mx_depth=depth[i];
 			mx_node=i;
 		}
 		depth[i] = 0; //reset for further op
 	}
 	dfs1(mx_node);	  //run dfs considering mx_depth as root
    for(int i=1; i<=n+1;++i)
 	{
 		if(depth[i]>mx_depth)
 		{
 			mx_depth=depth[i];
 		}
 	}
 	return mx_depth;
} 
int main()
{
    fastio
    ll t; cin >>t;
    forn(i,t)
    {
    	int x,y;cin >> x >> y;
    	tree[x].pb(y);
    	tree[y].pb(x);
    }
    cout<< treeDiameter(t);
    return 0;
}