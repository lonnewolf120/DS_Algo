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
	//only go up, left, right
	{0,1},{0,-1},{-1,0}, {1,0}
};
//this is in forward order, meaning going from source to dest
void detect(vector<string> &path,pair<int,int> x, pair<int,int> y)
{
	if(x.first<y.first)path.pb("forth");
	if(x.first>y.first)path.pb("forth");
	else if(x.second>y.second)path.pb("left");
	else if(x.second<y.second)path.pb("right");
}
vector<string> ans;
void dfs(ll sx, ll sy, ll n, ll m,vector<vector<char>> &g, ll index=0)
{
	if(index==sh.size())return;
	for(auto i:vp)
	{
		ll x=sx+i.first, y=sy+i.second;
		if(x<0 || y<0 || x>=n || y>=m) continue;
		if(g[x][y]==sh[index])
		{
			detect(ans,{sx,sy},{x,y});
			dfs(x,y,n,m,g,++index);
		}
	}
}

void detect2(string &path,pair<int,int> x, pair<int,int> y)
{
	if(x.first>y.first)path+= "forth ";
	else if(x.second>y.second)path += "left ";
	else if(x.second<y.second)path += "right ";
}
void dfs2(ll sx, ll sy, ll n, ll m, string& ans, vector<vector<char>> &g, ll index=0)
{
	if(index==sh.size())return;
	for(auto i:vp)
	{
		ll x=sx+i.first, y=sy+i.second;
		if(x<0 || y<0 || x>m || y>n) continue;
		if(g[x][y]==sh[index])
		{
			detect2(ans,{sx,sy},{x,y});
			dfs2(x,y,n,m,ans,g,++index);
		}
	}
}


vector<string> bfs_string(ll sx, ll sy, ll n, ll m, vector<vector<char>> &g, vector<vector<bool>>& visited)
{
	vector<string> ans;

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

			//Here we'll only visit the nodes, if the path has letters from "IEHOVA" in order (we can do this here because we know the original path will always be the same string)
			//so we're having an index & checking from the string using that index and after each successful run, updating the index
			if(!visited[mx][my] && g[mx][my]==sh[ind])
			{
				++ind;
				visited[mx][my]=1;
				//level[mx][my]=level[x][y]+1; //par[{mx,my}]={x,y};
				detect(ans,{x,y},{mx,my});
				q.push({mx,my});
			}
		}
	}
	return ans;
}

void solve()
{
	ll sx,sy,dx,dy;
	ll n,m; cin >> n >> m;
	vector<vector<char>> g(n+1,vector<char>(m+1));
	vector<vector<bool>> visited(n+1,vector<bool>(m+1,false));

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
	ans.clear();
	dfs(sx,sy,n,m,g);

	forn(i,ans.size())
	{
		cout<<ans[i];
		if(i<ans.size()-1)cout<<" ";
	}
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