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
  	{0,1}, {0,-1}, {1,0}, {-1,0}
  };
  ll destX,destY;

  ll r,c;
  const int N=21;
  char grid[N][N];

  ll bfs_string(
  ll sx, ll sy)
  {

  vector<vector<bool>> visited(r,vector<bool>(c,false));
  vector<vector<ll>> level(r,vector<ll>(c,0));
  	
  	visited[sx][sy]=true;
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
  			if(mx<0 || my<0 || mx>r || my>c || grid[mx][my]=='#' || grid[mx][my]=='m') continue;
  			
  			if(!visited[mx][my])
  			{
             //   cout<<mx << " " << my<<ln;
  				visited[mx][my]=true;
  				level[mx][my]=level[x][y]+1;
  				q.push({mx,my});
  			}
  		}
  		if(level[destX][destY]!=0) break;
  	}
    //cout<<level[destX][destY];
  	return level[destX][destY];
  }  
  
void solve()
{
	cin >> r >> c;
    pair<ll,ll> aa,bb,cc;
	forn(i,r)
	{
		forn(j,c)
		{
            cin >> grid[i][j];
            if(grid[i][j]=='a') aa={i,j};
            else if(grid[i][j]=='b') bb={i,j};
            else if(grid[i][j]=='c') cc={i,j};
            else if(grid[i][j]=='h') {destX=i;destY=j;}
		}
	}
    set<ll> am;
    am.insert(bfs_string(aa.fi,aa.se));
    am.insert(bfs_string(bb.fi,bb.se));
    am.insert(bfs_string(cc.fi,cc.se));
    cout << *(am.rbegin()) << ln;

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