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

vector<pair<int,int>> vp=
{
	{1,0}, {-1,0}, {0,1}, {0,-1}
};

int bfs_string(ll sx, ll sy, ll n, ll m, vector<vector<int>>& grid, vector<vector<bool>>& visited)
{
	ll c=0;
	//visited[sx][sy]=1;
	queue<pair<ll,ll>> q;
	q.push({sx,sy});
	
	//level[sx][sy]=0;
	while(!q.empty())
	{
		pair<ll,ll> p = q.front();
		q.pop();
		ll x = p.first, y = p.second;
		visited[x][y]=true;

		for(auto i:vp)
		{
			ll mx= x+i.first, my= y+i.second;

			if(mx<0 || my<0 || mx>=m || my>=n || grid[mx][my]==-1) continue;
			if(!visited[mx][my])
			{
				visited[mx][my]=true;
				++c;	//level[mx][my]=level[x][y]+1;
				q.push({mx,my});
			}
		}
	}
	return c+1;
}
void solve()
{ 
	int n,m; cin >> n >> m;
	vector<vector<int>> grid(m,vector<int>(n));	
	vector<vector<bool>> visited(m,vector<bool>(n,false));
	pair<int,int> p;
	forn(i,m)
	{
		forn(j,n)
		{
			char ch; cin >> ch;
			if(ch=='@') 
			{
				grid[i][j]=0;
				p={i,j};
			}
			else if(ch=='.')
			{
				grid[i][j]=0;
			}
			else if(ch=='#')
				grid[i][j]=-1;
		}
	}
	cout << bfs_string(p.first, p.second, n, m, grid,visited) << ln;
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