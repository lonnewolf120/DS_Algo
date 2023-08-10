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


ll dfs(ll sx,
map<ll, vector<ll>> &g,
map<pair<ll,ll>,ll> &wt,
map<ll,bool> &visited,
map<ll,ll> &dis)
{
	visited[sx]=true;
	queue<ll> q;
	ll val=0;
	q.push(sx);
	dis[sx]=0;
	//level[sx]=0;

	while(!q.empty())
	{
		ll p = q.front();
		q.pop();
		//visited[p]=1;
		for(auto i:g[p])
		{
			if(!visited[i] || p==sx)
			{
				//cout << wt[{p,i}] << " " << wt[{i,p}]<<ln;
				// if(wt[{p,i}]==0)
				// {
				// 	val+=dis[p];
				// }
				// else
				// {
				// 	val+=dis[p]+wt[{p,i}];
				// }
				//cout<<wt[{p,i}] <<" "<<wt[{i,p}]<<ln;
				val+=wt[{p,i}];
				visited[i]=true;
				q.push(i);
			}
			
		}
	}
	return val;
}

void dfs1(ll src,
map<ll, vector<ll>> &g,
map<pair<ll,ll>,ll> &wt,
map<ll,bool> &visited,
map<ll,ll> &dis)
{
	visited[src]=true;
	for(auto i:g[src])
	{
		if(!visited[i])
		{
			(wt[{src,i}]==0)? dis[i]= dis[src]+wt[{src,i}]: dis[i]=dis[src]+wt[{i,src}];
			dfs1(i,g,wt,visited,dis);
		}
	}
}

void solve()
{
	map<pair<ll,ll>,ll> wt;
	map<ll,bool> visited;
	map<ll,ll> dis;

	ll n,src=1,mx=-1; 
	cin >> n;
	vector<ll> g[n+5]; //2-way road 
	forn(i,n)
	{
		ll u,v,w; cin >> u >> v >> w;
		g[u].pb(v);
		g[v].pb(u);

		//wt[{u,v}]=0;  //direct connection
		wt[{v,u}]=w;  //cost of redirection
		if(w>=mx)
		{
			mx=w;
			src=v;
		}
	}
	
	ll c_c=1, n_c=g[c_c][0], ans1=0;
	forsn(i,1,n)
	{
		if(g[i].empty()) continue;
		//if there's 
		if(wt[{c_c,n_c}]==0) ans1+=wt[{n_c,c_c}];

		ll tmp=g[n_c][0];
		if(tmp==c_c) tmp=g[n_c][1];

		c_c=n_c;
		n_c=tmp;
	}
	//cout<<ans1<<ln;

	c_c=1, n_c=g[c_c][1]; ll ans2=0;
	forsn(i,1,n)
	{
		if(g[i].empty()) continue;
		//if there's 
		if(wt[{c_c,n_c}]==0) ans2+=wt[{n_c,c_c}];

		ll tmp=g[n_c][1];
		if(tmp==c_c) tmp=g[n_c][0];

		c_c=n_c;
		n_c=tmp;
	}
	//cout<<ans1<<ln;
	cout<<min(ans1,ans2)<<ln;
	// cout << dfs(1,g,wt,visited,dis) <<ln;
	// for(auto i:dis)
		// cout<<i.fi << " " <<i.se<<ln;

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