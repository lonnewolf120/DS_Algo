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

const int N = 10e5;


bool bfs(ll sx, ll n,map<ll,vector<ll>> &g,vector<bool>& visited,	ll level[], ll par[])
{
	visited[sx]=true;
	queue<ll> q;
	q.push(sx);
	par[sx]=1;

	while(!q.empty())
	{
		ll p = q.front();
		q.pop();
		
		if(p==n) return true;
		for(auto i:g[p])
		{
			if(!visited[i])
			{
				visited[i]=true;
				par[i]=p;
				q.push(i);
			}
		}
	}
	return false;
}


void solve()
{
	ll n; cin >> n;
	map<ll,vector<ll>> g;
	vector<bool> visited(n+1);
	ll level[n+1];
	ll par[n+1];

	forsn(i,1,n-1)
	{
		ll x; cin >> x;
		forsn(j,1,x)
		{
			ll y; cin >> y;
			g[i].pb(y);
		}
		sort(all(g[i]));
	}
	bool f=bfs(1,n,g,visited,level,par);
	if(!f)cout<<-1<<ln;
	else
	{
		vector<int> path;
		ll v = par[n];
		path.pb(v);
		while(v!=1)
		{
			path.pb(par[v]);
			v=par[v];
		}
		cout<<path.size()<<ln;
		rforn(i,path.size()-1)
		{
			cout<<path[i]<<" ";
		}cout<<ln;
	}
	cout<<ln;

}

int main()
{
    fastio
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
     //cout << "Case " << it << ": ";
        solve();
    }
    return 0;
}