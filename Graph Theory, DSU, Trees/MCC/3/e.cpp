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


  void bfs(ll sx,map<ll, vector<ll>> &g,map<ll,bool> &visited, map<ll,ll>& level)
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
  			if(!visited[i])
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
	ll t=0,n,tst=1;
	map<ll,vector<ll>> g;
	while(cin >> n)
	{
		
		//t=t%20;
		// if(t<20)
		// {
			while(n--)
			{
				ll u; cin >> u; 
				g[t+1].pb(u);
				g[u].pb(t+1);
				//cout <<t+1<<" "<<u<<ln;
			}	
			++t;
		//}
		if(t==19)
		{
			
			//bfs(1,g,visited,level);
			ll query; cin >> query; //cout<<query<<ln;
			cout<<"Test Set #"<<tst++<<ln;
			while(query--)
			{
				map<ll,ll> level;
			  map<ll,bool> visited;
				ll u,v; cin >> u >> v;
				bfs(u,g,visited,level);				
				//cout<<u<< " " << level[u] << ", " <<v << " " <<level[v]<<ln;
				(u<=9)?cout<<" "<<u:cout<<u;
				cout << " to ";
				(v<=9)?cout<<" " << v:cout<<v;
				cout << ": " << level[v]<<ln;
			}
			g.clear();cout<<ln;
			t=t%19;
		}
	}
}
int main()
{
    //fastio
    solve();
    return 0;
}