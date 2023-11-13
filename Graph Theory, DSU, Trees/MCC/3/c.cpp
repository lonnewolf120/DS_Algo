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


string sh="IEHOVA#";
vector<pair<int,int>> vp=
{
	{0,1},{0,-1},{-1,0}
};
vector<pair<ll,ll>> bfs_string(ll sx, ll sy, ll n, ll m, vector<vector<char>> &g, vector<vector<bool>>& visited, map<pair<int,int>,pair<int,int>> &par)
{
	vector<pair<ll,ll>> ans;

	visited[sx][sy]=1;
	queue<pair<ll,ll>> q;
	q.push({sx,sy});
	int ind=0;
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

			if(mx<0 || my<0 || mx>m || my>n) continue;

			//Here we'll only visit the nodes, if the path has the letters from "IEHOVA" in order
			//so we're having an index and also checking from the string & after each successful run, updating the index
			if(!visited[mx][my] && g[mx][my]==sh[ind])
			{
				++ind;
				visited[mx][my]=1;
				//level[mx][my]=level[x][y]+1; //par[{mx,my}]={x,y};
				ans.pb({mx,my});
				q.push({mx,my});
			}
		}
	}
	return ans;
}
void detect(vector<string> &path,pair<int,int> x, pair<int,int> y)
{
	if(x.first>y.first)path.pb("forth");
	else if(x.second>y.second)path.pb("left");
	else if(x.second<y.second)path.pb("right");
}
 
void solve()
{
	ll sx,sy,dx,dy;
	ll n,m; cin >> n >> m;
	vector<vector<char>> g(8,vector<char>(8));
	vector<vector<bool>> visited(8,vector<bool>(8,false));
	map<pair<int,int>,pair<int,int>> par;

	forn(i,n)
	{
		forn(j,m)
		{
			char ch; cin >> ch;
			g[i][j]=ch;
			if(ch=='@'){sx=i;sy=j;}
			if(ch=='#'){dx=i;dy=j;}
		}
	}
	cout<<ln;
	vector<pair<ll,ll>> ans=bfs_string(sx,sy,n,m,g,visited,par);

	vector<string> path;
	//for initial index
	detect(path,{sx,sy},ans[0]);
	//traverse through the path and set the direction
	forn(i,ans.size()-1)
	{
		detect(path,ans[i],ans[i+1]);
	}
	for(auto i:path)
		cout<<i <<" ";
	cout<<ln;
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