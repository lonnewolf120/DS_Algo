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

map<int,vector<int>> g;
map<ll,ll> color;

ll c=0;
void dfs(ll src,ll ca)
{
	if(color[src]!=ca) ++c;
	for(auto i:g[src])
		dfs(i,color[src]);
}
void solve()
{
	ll n; cin >> n;
	forsn(i,2,n)
	{
		ll x; cin >> x;
		g[x].pb(i);
		//g[x].pb(i);
	}
	forsn(i,1,n)
	{
		ll x; cin >> x;
		color[i]=x;
	}
	c=0;
	dfs(1,-1);
	cout<<c<<ln;
}
int main()
{
    fastio
    solve();
    return 0;
}