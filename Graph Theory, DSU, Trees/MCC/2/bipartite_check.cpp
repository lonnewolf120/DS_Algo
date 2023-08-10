/*
______                                 _____________   _______   _________________           
___  /____________________      __________  /__  __/   ____  /   ___(_)__  __/_  /__________ 
__  /_  __ \_  __ \  _ \_ | /| / /  __ \_  /__  /_     ___  /    __  /__  /_ _  __/  _ \  _ \
_  / / /_/ /  / / /  __/_ |/ |/ // /_/ /  / _  __/     __  /     _  / _  __/ / /_ /  __/  __/
/_/  \____//_/ /_/\___/____/|__/ \____//_/  /_/        _  /      /_/  /_/    \__/ \___/\___/ 
                                                       /_/                                        
*/

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

const int N=10e5;

bool notBipartite(int src, map<int,vector<int>>& g,int visited[],int color=0)
{
	visited[src]=color;
	for(auto i:g[src])
	{
		if(visited[i]==-1)
		{
			if(notBipartite(i,g,visited,!(color))) return true;
		}
			else if(visited[i]==color) return true;

	}

	return false;
}

void solve()
{
	ll n,e; cin >> n >> e;
	map<int,vector<int>> g;
	int visited[n]={-1};
	forn(i,e)
	{
		ll u,v; cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	ll c=0;
	forn(i,n)
	{
		if(visited[i]==-1)
		{
			if(notBipartite(i,g,visited)){cout<<"Not bipartite!\n";return;}
			//else {no;return;}
			
		}
	}
	cout<<"Bipartite!\n";
	//(n==(e-1))?yes:no;
}

int main()
{
	fastio
	//ll t; cin >> t;
	//while(t--)
	solve();
}