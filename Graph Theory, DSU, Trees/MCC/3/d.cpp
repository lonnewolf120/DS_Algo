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

const int N=10e5;

void bfs(ll sx, map<ll, vector<ll>> &g, map<ll,ll> &level,map<ll,bool> &visited)
{
	visited[sx]=true;
	queue<ll> q;
	q.push(sx);
	level[sx]=0;

	while(!q.empty())
	{
		ll p = q.front();
		q.pop();
		//visited[p]=1;
		for(auto i:g[p])
		{
			//++cnt;
			if(visited[i]==false)
			{
				visited[i]=true;
				level[i]=level[p]+1;
				q.push(i);
			}
		}
		
	}
}
void solve()
{
	ll t=1;
	while(true)
	{
		ll n;  scanf("%lld",&n);
		if(n==0) break;

		set<ll> nodescnt;
		map<ll, vector<ll>> g;	
		while(n--)
		{
			ll u,v; scanf("%lld%lld",&u,&v);
			nodescnt.insert(u);
			nodescnt.insert(v);
			g[u].pb(v);
			g[v].pb(u);
		}
		ll size=nodescnt.size();
		while(true)
		{
			map<ll,bool> visited;
			map<ll,ll> level;
			ll cnt=0;
			ll x,y; scanf("%lld%lld",&x,&y);
			if(x==0 && y==0) break;
			bfs(x,g,level,visited);
			for(auto i:level)
			{
				if(i.se>0 && i.se<=y)cnt++;
			}
			printf("Case %lld: %lld nodes not reachable from node %lld with TTL = %lld.\n",t++,size-cnt-1,x,y);
		}
	}
}
int main()
{
//    fastio
    solve();
    return 0;
}