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

const ll N=1000+10;
ll visited[N][N];
ll level[N][N];

/* BFS on matrix:
instead of having a map<ll,vector<ll>> we'll be having 2D grids
https://www.youtube.com/watch?v=WOV3LYhPews
*/

vector<pair<ll,ll>> vp =
{
	{1,-2}, {1,2}, {2,-1}, {2,1},
	{-2,-1}, {-1,-2}, {-2,1}, {-1,2}
};

void bfs_string(ll sx, ll sy)
{
	memset(visited,0,sizeof(visited));
	memset(level,0,sizeof(level));

	visited[sx][sy]=1;
	queue<pair<ll,ll>> q;
	q.push({sx,sy});
	
	//level[sx][sy]=0;
	while(!q.empty())
	{
		pair<ll,ll> p = q.front();
		q.pop();
		ll x = p.first, y = p.second;
		//visited[x][y]=1;
		for(auto i:vp)
		{
			ll mx= x+i.first, my= y+i.second;
			if(mx>=1 && my>=1 && mx<=1000 && my<=1000 && !visited[mx][my])
			{
				visited[mx][my]=1;
				level[mx][my]=level[x][y]+1;
				q.push({mx,my});
			}
		}
		//if(level[destX][destY]!=0) break;
	}
}

int main()
{
    fastio
    ll t;
    cin >> t; 
   	bfs_string(1,1);
    for(ll it=1;it<=t;it++) 
    {
        ll srcX, srcY; 
        cin >> srcX >> srcY; //srcY--;srcX--;
		cout << level[srcX][srcY] << ln;
	 }

      
    return 0;
} 