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
#define inf 1<<30
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define yes cout << "YES\n"
#define no cout << "NO\n"

const int N=10e5;
ll n,m,c=0;
map<ll, vector<ll>> g;
vector<ll> dist(N,inf);
map<pair<ll,ll>, ll> wt;
map<ll,bool> visited;

void bfs_0_1(ll sx)
{
	deque<ll> q;
	q.push_front(sx);
	dist[sx]=0;

	while(!q.empty())
	{
		ll p = q.front();
		q.pop_front();
		for(auto i:g[p])
		{
			if(dist[i]>dist[p]+wt[{p,i}])
			{
				dist[i]=dist[p]+wt[{p,i}];
				(!wt[{p,i}])? q.push_front(i) : q.push_back(i); //if wt is 0 then it is fwd dir, so we'll judge it first & when 1 it's rev, so we'll judge it later
			}
		}
	}

 
void solve()
{
	cin >> n >> m;
	forn(i,m)
	{
		ll u,v; cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
		
		wt[{u,v}]=0;
		wt[{v,u}]=1;
	}
	bfs_0_1(1);
	//cout<<dist[0]<<ln;
	//for(auto i:dist)cout<<i<<ln;
	(dist[n]==inf)? cout<<-1<<ln: cout<<dist[n]<<ln;
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