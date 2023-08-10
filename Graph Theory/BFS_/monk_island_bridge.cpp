#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
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

const int N=10e4;

void bfs(vector<int>& level,
vector<bool>& visited,
vector<int> tree[])
{
	queue<int> q; q.push(1); visited[1]=true;level[1]=0;
	while(!q.empty())
	{
		int t = q.front(); q.pop();
		for(auto i:tree[t])
		{
			if(!visited[i])
			{
				visited[i]=true;
				level[i]=level[t]+1;
				q.push(i);
			}
		}
	}
}
  
void solve()
{
	ll n,m; cin >> n >> m;
	vector<int> level(n+1);
	vector<bool> visited(n+1,false);
	vector<int> tree[n+1];
	forn(i,m)
	{
		ll x,y; cin >> x >> y;
		tree[x].pb(y);
		tree[y].pb(x);
	}
	bfs(level,visited,tree);
	
	cout<< level[n] << ln;
	
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