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



ll bfs(ll sx,
map<ll, vector<ll>> &g,
map<ll,bool> &visited,
map<ll,ll> &color)
{
	ll ly=0,vu=0;
	visited[sx]=true;
	queue<ll> q;
	q.push(sx);
	color[sx]=1; ly++;

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

				color[i]=1-color[p];	//color of i will be opposite of sx
				(color[i])? ly++ : vu++;
				q.push(i);
			}
		}
	}
	//return (ly>vu)? make_pair(1,ly) : make_pair(0,vu);
	return max(ly,vu);
}
  
void solve()
{
	ll n; cin >> n;
	map<ll,vector<ll>> g;
	map<ll,bool> visited;
	map<ll,ll> color;
	ll maxNode=-1;
	forn(i,n)
	{
		ll u,v; cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
		maxNode=max(maxNode,u);
		maxNode=max(maxNode,v);
	}
	ll s1=0,s2=0;

	forsn(i,1,maxNode-1)
	{
		if(g[i].empty()) continue;
		if(!visited[i])
		{
			// pair<ll,ll> p =bfs(i,g,visited,color);
			// (p.fi==1)? s1+=p.se : s2+=p.se;
			s1+=bfs(i,g,visited,color);
		}
	}

	// ll m1=0,m2=0;
	// for(auto i:color){
	// 	(i.se==1)? ++m1: ++m2;
	// }
	cout << s1 << ln;
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