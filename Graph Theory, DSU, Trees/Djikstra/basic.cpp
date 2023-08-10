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

   
void djikstra(ll sx,map<ll, vector<pair<ll,ll>>> &g,vector<bool> &visited,vector<ll> &dis)
{
	visited[sx]=true;
	priority_queue<pair<ll,ll>> q; //wt,node
	q.push({0,sx});
	dis[sx]=0;

	while(!q.empty())
	{
		ll p = q.top().second;
		q.pop();
		//visited[p]=1;
		for(auto i:g[p.second])
		{
			ll node=i.first, weight=i.second;
			if(dis[node]>dis[p]+weight)
			{
				dis[node]=dis[p]+weight;
				q.push(i);
			}
		}
	}
}
int main()
{
    fastio
    return 0;
}