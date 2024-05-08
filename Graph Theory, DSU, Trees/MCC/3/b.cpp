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

void dfs(int sx, map<int,vector<int>>&g, vector<bool> &visited)
{
	visited[sx]=true;
	stack<ll> q;
	q.push(sx);
	//level[sx]=0;

	while(!q.empty())
	{
		ll p = q.top();
		q.pop();
		//visited[p]=1;
		for(auto i:g[p])
		{
			if(!visited[i])
			{
				//++c;
				visited[i]=true;
				//level[i]=level[p]+1;
				q.push(i);
			}
		}
	}
}
void solve()
{
	ll n,m,l; cin >> n >> m>> l;
	map<int,vector<int>> g;
	//vector<int> level(n,0);
	vector<bool> visited(n+1,false);
	//int par[n];
	ll c=0;
	forn(i,m)
	{
		ll u, v; cin >> u >> v;
		g[u].pb(v);
		//g[v].pb(u); //these are dominoes so they're directed
	}
	forn(i,l)
	{
		ll x; cin >> x;
		if(!visited[x])
		{
			dfs(x,g,visited);
		}
	}
	ll cnt=0;
	forsn(i,1,n)
	{
		if(visited[i]) ++cnt;
	}
	cout<<cnt<<ln;
}

int main()
{
    fastio
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
     //cout << "Case " << it << ": ";
        solve();
    }
    return 0;
}