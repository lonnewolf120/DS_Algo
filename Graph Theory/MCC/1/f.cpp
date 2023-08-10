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

queue<pair<ll,ll>> q;
map<ll,vector<pair<ll,ll>>> g;
map<ll,bool> visited;
// map<ll,ll> level;
set<ll> ans;

void bfs()
{
//already called in solve()
	// set<ll> ans;
	// q.push({sx,dis});
	// level[sx]=0;
	while(!q.empty())
	{
		ll node = q.front().fi;
		ll dist = q.front().se;
		q.pop();
		if(visited[node])continue;
		visited[node]=true;

		for(auto i:g[node])
		{
			if(i.fi!=dist)
			{
				//if this node is already visited, means there's a way to it, so we can remove one road
				if(visited[i.fi])ans.insert(i.se);
				else q.push({i.fi,node});
			}
		}
	}
}
void solve()
{
	ll n,k,d; cin>>n>>k>>d;
	// vector<ll> police(k+1);
	forsn(i,1,k)
	{
		ll x; cin>>x;
		q.push({x,-1});
	}
	forsn(i,1,n-1)
	{
		ll u,v;cin>>u>>v;
		g[u].pb({v,i});
		g[v].pb({u,i});
	}
	bfs();
	cout<<ans.size()<<ln;
	for(auto i:ans)cout<<i<<" ";
		cout<<ln;
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