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

map<ll,bool> visited;
map<ll,ll> level;

vector<pair<int,int>> vp=
{
	{0,1}, {1,0},{0,-1},{-1,0}
};
ll n,m;
void bfs_string(ll sx, ll sy,
vector<vector<bool>> &visited,
vector<vector<ll>> &grid,
vector<vector<ll>> &level,
map<pair<ll,ll>,pair<ll,ll>> &par)
{
	visited[sx][sy]=1;
	stack<pair<ll,ll>> q;
	q.push({sx,sy});
	level[sx][sy]=0;
	while(!q.empty())
	{
		pair<ll,ll> p = q.top();
		q.pop();
		ll x = p.first, y = p.second;
		//visited[x][y]=1;

		for(auto i:vp)
		{
			ll mx= x+i.first, my= y+i.second;

			if(mx<0 || my<0 || mx>m || my>n) continue;
			if(!visited[mx][my])
			{
				visited[mx][my]=1; cout<<"a\n";
				level[mx][my]=level[x][y]+1;
				par[{mx,my}]={x,y};
				q.push({mx,my});
			}
		}
		//if(level[destX][destY]!=0) break;
	}
}
void solve()
{
	cin >> n >> m;
	vector<vector<ll>> ans;
	vector<vector<ll>> grid(n,vector<ll>(m));
	vector<vector<ll>> level(n,vector<ll>(m,0));
	vector<vector<bool>> visited(n,vector<bool>(m,false));
	map<pair<ll,ll>,pair<ll,ll>> par;
	forn(i,n)
	{
		forn(j,m)
		{
			cin >> grid[i][j];
			cout<<grid[i][j]<<" ";
		}
		cout<<ln;
	}
	//bfs_string(0,0,visited,grid,level,par);
	for(auto i:level)
		for(auto j:i)
			cout<<j<<" ";
	// 	cout<<ln;
	// for(auto i:par)
	// 	cout<<grid[i.fi.fi][i.fi.se] << " "<<grid[i.se.fi][i.se.se]<<ln;
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