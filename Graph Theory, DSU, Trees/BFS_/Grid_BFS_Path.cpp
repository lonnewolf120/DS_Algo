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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define yes cout << "YES\n"
#define no cout << "NO\n"

const int N=1e3+3;
int grid[N][N];
int level[N][N];


pair<int,int> a,b;
vector<char> path;
map<pair<int,int>,pair<int,int>> par;

/*Idea:
run bfs to find shortest path, now store the parents
of each grid, then if B is found then,
traverse through the parents (from B to A, inclusive! set parent of A as -1), detect whether if L,R,U,D & store it in path
using detect function, now reverse that & print
*/

vector<pair<int,int>> vp=
{
	{-1,0}, {1,0}, {0,-1},{0,1}
};

ll n,m;
bool bfs(int si, int sj, int di, int dj)
{
	queue<pair<int,int>> q;
	q.push({si,sj});
	level[si][sj]=0;
	par[{si,sj}]={-1,-1};

	while(!q.empty())
	{
		pair<int,int> p = q.front(); q.pop();
		int x=p.first,y=p.second;
		for(auto i:vp)
		{
			int mx=x+i.first,my=y+i.second;
			if(mx<0 || my<0 || mx>n || my>m || grid[mx][my]==0) continue;
			
			q.push({mx,my});
			grid[mx][my]=0;
			level[mx][my]=level[x][y]+1;
			par[{mx,my}]={x,y};
		}
	}
	return (level[di][dj]!=0)? true:false;
}

void detect(pair<int,int> x, pair<int,int> y)
{
	//this works if gone from B to A, not the opposite
	if(x.first<y.first)path.pb('U');
	else if(x.first>y.first)path.pb('D');
	else if(x.second>y.second)path.pb('R');
	else if(x.second<y.second)path.pb('L');
	//after finishing reverse the result
}

/*
bool operator==(const pair<int,int> &e, const pair<int,int> &f) 
{
    return ((e.first == f.first) && (e.second == f.second)) ||
           ((e.second == f.second) && (e.first == f.second));
}
*/
void solve(){
	//initialization
	cin >> n >> m;
	forn(i,n)
	{
		forn(j,m)
		{
			char c; cin >> c;
			if(c=='A')
			{
			   a = {i,j};
			   grid[i][j]=1;
			   par[a]={0,0};
			}
			else if(c=='B') 
			{
				b = {i,j};
				grid[i][j]=2;
			}
			else if(c=='#') grid[i][j]=0;
			else grid[i][j]=1;
		}
	}
		//call bfs
	bool f=false;
	f=bfs(a.first, a.second, b.first, b.second);
	if(f)
	{
		yes;
		cout << level[b.first][b.second] << ln;
		while(true)
		{
			detect(b,par[b]);
			if(par[b]==a) break;
			b=par[b];
		}
		detect(par[b],a);
		reverse(all(path));
		for(auto i:path) cout << i;
			cout<<ln;
	}
	else
	{
		no;
	}
	

}
int main()
{
    fastio
    solve();

    return 0;
}