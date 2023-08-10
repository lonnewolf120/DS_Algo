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

void bfs(ll sx,
map<ll, vector<ll>> &g,
map<ll,bool> visited,
map<ll,ll> &cnt
)
{
	visited[sx]=true;
	cnt[sx]++;
	queue<ll> q;
	q.push(sx);
	//level[sx]=0;

	while(!q.empty())
	{
		ll p = q.front();
		q.pop();
		//visited[p]=1;
		for(auto i:g[p])
		{
			if(!visited[i])
			{
				visited[i]=true;
				cnt[i]++;
				//level[i]=level[p]+1;
				q.push(i);
			}
		}
	}
}


void dfs(ll src,
map<ll,vector<ll>> &g,
map<ll,bool> visited,
map<ll,ll> &cnt)
{
	visited[src]=true;
	cnt[src]++;
	for(auto i:g[src])
	{
		if(!visited[i])
		{
			dfs(i,g,visited,cnt);
			cnt[i]++;
		}
	}
}


void solve()
{
	ll k,n,m; cin >> k >> n >> m;
	vector<ll> src(k);
	map<ll,vector<ll>> g;
	map<ll,bool> visited;
	map<ll,ll> cnt;
	for(auto &i:src)cin>>i;
	forn(i,m)
	{
		ll u,v; cin >> u >> v;
		g[u].pb(v);
	}
	for(auto i:src)
	{
		dfs(i,g,visited,cnt);
	}
	ll ans=0;
	//cout<<ln<<k<<ln;
	for(auto i:cnt)if(i.se==k)++ans;
		cout<<ans<<ln;
}
int main()
{
    fastio
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
     cout << "Case " << it << ": ";
        solve();
    }
    return 0;
}