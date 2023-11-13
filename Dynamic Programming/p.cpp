#include <bits/stdc++.h>
#include <C:\D Drive\Projects\Tutorials\Graph Theory\MCC\1\debug2.h>
using namespace std;
   
typedef long long ll;
typedef long double ld;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i <= e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
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
	{0,1}, {0,-1}, {1,0}, {-1,0}
};
ll h,w;
void bfs_string(ll sx, ll sy,
vector<vector<ll>> &visited,
vector<vector<ll>> &level)
{
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

			if(mx<0 || my<0 || mx>h || my>w) continue;
			if(!visited[mx][my])
			{
				visited[mx][my]=1;
				level[mx][my]=level[x][y]+1;
				q.push({mx,my});
			}
		}
		//if(level[destX][destY]!=0) break;
	}
}


void solve()
{
	cin>>h>>w;
	forn(i,h)
	{
		forn(i,w)
		{

		}
	}
}
int main()
{
    fastio
    ll t=1;
    // cin >> t;
    for(int it=1;it<=t;it++) {
     //cout << "Case " << it << ": ";
        solve();
    }
    return 0;
}