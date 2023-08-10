#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
   
using namespace std;
   
typedef long long ll;
typedef long double ld;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(int i = 0; i < e; i++)
#define forsn(i,s,e) for(int i = s; i <= e; i++)
#define rforn(i,s) for(int i = s; i >= 0; i--)
#define rforsn(i,s,e) for(int i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define pb push_back
#define fi first
#define se second
#define inf 1e18
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define yes cout << "YES\n"
#define no cout << "NO\n"


const ll N=510;
ll n,m,t,d;
ll dist[N][N], r[N]; 
vector<ll> repair;
  
void floyd()
{
	forsn(i,1,n)
		forsn(j,1,n)
			forsn(k,1,n)
				//if(dist[j][i]<inf && dist[i][k]<inf)
				dist[j][k] = min(dist[j][k], dist[j][i]+dist[i][k]);
}


void djikstra(ll n)
{
	vector<ll> ans(n+1,inf);
	ans[1]=0;
	priority_queue<pair<ll,ll>> pq;
	pq.push({0,1});

	while(!pq.empty())
	{
		ll cst=-pq.top().first, v=pq.top().second;
		pq.pop();

		if(ans[v]!=cst)continue;

		for(auto i:repair)
		{
			if(dist[v][i]<=d && ans[i]>ans[v]+dist[v][i])
			{
				ans[i]=ans[v]+dist[v][i];
				pq.push({-ans[i],i});
			}
		}
	}
	(ans[n]==inf)? cout<<"stuck\n" : cout<<ans[n]<<ln;
}


int main()
{
    fastio
    cin >> n >> m >> t >> d;
	forsn(i,1,n)
	{
		forsn(j,1,n) {dist[i][j]=inf;}
		dist[i][i]=0;
	}

	forn(i,t)
	{
		ll x; cin >> x; repair.pb(x);
	}
	repair.pb(n);

	forn(i,m)
	{
		ll u,v,w; cin >> u >> v >> w;
		dist[u][v]=min(dist[u][v],w);
		dist[v][u]=dist[u][v];
	}
    floyd();
    djikstra(n);

   

    return 0;
}	