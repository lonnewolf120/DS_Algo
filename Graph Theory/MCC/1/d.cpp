#include <bits/stdc++.h>
// #include <C:\D Drive\Projects\Tutorials\Graph Theory\MCC\1\debug2.h>
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


map<ll,vector<ll>> g;
// map<ll,bool> visited;
// const int N=2e5;
map<ll,ll> v;
ll ans=0;
ll n,k;
void dfs(ll src, ll p, ll c)
{
	if(c>k)return;
	bool f=true;
	// visited[src]=true;
	// if(v[src])++c;
	for(auto i:g[src])
	{
		if(i!=p)
		{
			f=false;
			(v[i])?dfs(i,src,c+1): dfs(i,src,0);
		}
	}
	if(f)ans++;
	// return c;
}

void solve()
{
	ans=0;
	cin >> n>>k;
	forsn(i,1,n)
	{
		ll x; cin >> x; v[i]=x;
	}
	forn(i,n-1)
	{
		ll u,v; cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	
	dfs(1,-1,v[1]);

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