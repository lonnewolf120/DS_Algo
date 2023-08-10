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
#define inf 2e6
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define yes cout << "YES\n"
#define no cout << "NO\n"
const int N=10e3;

pair<int,int> parent[N];
map<int,vector<pair<int,int>>> adj;
int weight[N]={100000};
int visited[N]={0};
void addnode(int u,int v,int w)
{
	adj[u].push_back({v,w});
	adj[v].push_back({u,w});
}
void prims(int src)
{
	priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;

	pq.push({0,src});
	weight[src]=0;
	parent[src]={src,0};

	while(!pq.empty())
	{
		//int top = pq.top().first;
		int top = pq.top().second; 
		pq.pop();

		if(visited[top]) continue;
		visited[top]=1;

		for(auto it:adj[top])
		{
			int node = it.first;
          int edge_weight = it.second;

          if (!visited[node] && edge_weight < weight[node]) {
          		cout << node << " " << edge_weight << ln;
              weight[node] = edge_weight;
              parent[node] = {src, edge_weight};
              pq.push({edge_weight, node});
          }
		}
	}
}
int main()
{
 	  addnode(0, 1, 4);
  addnode(0, 2, 4);
  addnode(1, 2, 2);
  addnode(1, 0, 4);
  addnode(2, 0, 4);
  addnode(2, 1, 2);
  addnode(2, 3, 3);
  addnode(2, 5, 2);
  addnode(2, 4, 4);
  addnode(3, 2, 3);
  addnode(3, 4, 3);
  addnode(4, 2, 4);
  addnode(4, 3, 3);
  addnode(5, 2, 2);
  addnode(5, 4, 3);

  prims(0);
  //for(auto it:parent[]) cout<<it.first << " " << it.second << ln;
  for (int i = 0; i <= 5; ++i)
  {
  //for(auto it:parent[i]) cout<<it.first << " " << it.second << ln;
  	 if(parent[i].first!=i)
  	 {	
  	 	cout << i << " " << parent[i].first << " " << parent[i].second << ln;
  	 }
  }
    return 0;
}