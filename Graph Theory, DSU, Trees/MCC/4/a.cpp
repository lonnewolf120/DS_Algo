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
#define inf 1e10
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define yes cout << "YES\n"
#define no cout << "NO\n"

// void djikstra(ll sx, map<ll, vector<ll>> &g, map<ll, vector<ll>> &weight,vector<ll> &dis)
// {
// 	queue<ll> q; //wt,node
// 	q.push(sx);
// 	dis[sx]=0;

// 	while(!q.empty())
// 	{
// 		ll p = q.front();
// 		q.pop();

// 		for(auto i:g[p])
// 		{
// 			if(dis[i]>dis[p]+weight[])
// 			{
// 				dis[i]=dis[p]+weight;
// 				q.push({dis[p]+weight,i});
// 			}
// 		}
// 	}
// }
ll mxwt;


void bfs(ll src,
map<ll,vector<ll>> &g,
vector<bool> &visited,
vector<ll> &dis,
map<pair<ll,ll>,ll> &wt)
{
	visited[src]=true;
	queue<ll> q;
	q.push(src);

	while(!q.empty())
	{
		ll p = q.front();
		q.pop();
		for(auto i:g[p])
		{
			if(!visited[i])
			{
				visited[i]=true;
				dis[i] = dis[p]+ wt[{p,i}];	//distance of any node from the source
				q.push(i);
			}
		}
	}
}

void solve()
{
	ll n; cin >> n;
	mxwt=-1;
	map<ll,vector<ll>> g;
	map<pair<ll,ll>,ll> wt;
	vector<ll> dis(n,0);	//this will store the distance from source
	vector<ll> level(n,0); 
	vector<bool> visited(n,false);

	ll mx=-1,nd=0;
	forn(i,n-1)
	{
		ll u,v,w; cin >> u >> v >> w;
		g[u].pb(v);
		g[v].pb(u);
		
		wt[{u,v}] = w;
		wt[{v,u}] = w;
		//wt[v].pb(w);
	}
	//at first we'll calc the furthest node from source
	//then we need to run bfs again from the furthest node to find the maximum distance
	bfs(0,g,visited,dis,wt);
	forn(i,n)
	{
		if(dis[i]>mxwt)
		{
			mxwt=dis[i];
			nd=i;
		}
	}
	//cout<<mxwt<<ln;
	mxwt=-1;
	forn(i,n)
	{
		visited[i]=false;
		dis[i]=0;
	}
	bfs(nd,g,visited,dis,wt);
	for(auto i:dis)
		mxwt=max(mxwt,i);
	cout<<mxwt<<ln;
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