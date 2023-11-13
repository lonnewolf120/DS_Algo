#include <bits/stdc++.h>
//#include <C:\D Drive\Projects\Tutorials\Graph Theory\MCC\1\debug2.h>
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

map<int,vector<int>> g;
map<ll,bool> visited;
ll mn=1<<20;
void dfs(int src,vector<ll> &v)
{
	visited[src]=true;
	mn=min(mn,v[src]);
	//dbg(mn);
	for(auto i:g[src])
	{
		if(!visited[i])
		{
			dfs(i,v);
		}
	}
}

void solve()
{
	ll n,m,ans=0; 
	cin >> n >> m;
	vector<ll> v(n+1);
	forsn(i,1,n)
	cin >>v[i];
	//	dbg(v);
	forn(i,m)
	{
		ll u,v; cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	forsn(i,1,n)
	{
		mn=1<<30;
		if(visited[i]) continue;
		dfs(i,v);
		ans+=mn;
	}
	cout<<ans<<ln;
}
int main()
{
    fastio
    ll t=1;
    // cin >> t;
    for(int it=1;it<=t;it++) {
     //cout << "Case " << it << ": ";
        solve();
    }
    return 0;
}