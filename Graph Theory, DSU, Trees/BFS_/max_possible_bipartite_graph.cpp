#include <bits/stdc++.h>
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

map<ll, vector<ll>> g;
map<ll,bool> visited;
map<ll,ll> color;
map<ll,ll> cnt;
void bfs(ll sx=1)
{
	queue<ll> q;
	q.push(sx);
	color[sx]=1; 
	// cnt[color[sx]]++;
	// par[sx]=sx;

	while(!q.empty())
	{
		ll p = q.front();
		cnt[color[p]]++;
		q.pop();
		for(auto i:g[p])
		{
			if(!(color[i]))
			{
				color[i]=(color[p]==1)?2:1;//(color[p])?1:0;	
				// cnt[color[i]]++;
				// par[i]=p;
				q.push(i);
			}
		}
	}
}

void solve()
{
	ll n; cin >> n;
	forn(i,n-1)
	{
		ll u,v; cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	bfs();
	// dbg(color);
	// dbg(par);
	// number of edges that can be added =    
	// (possibility of edges with both colors) - (current edge count+1) 
	// dbg(cnt);
	cout<<(cnt[2]*cnt[1])-(n-1) <<ln;
}
int main()
{
    fastio
    solve();
    return 0;
}