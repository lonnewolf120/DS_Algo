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

vector<pair<int,int>> pat={
	{1,0},{-1,0},{0,1},{0,-1},
	{1,1}, {1,-1}, {-1,1}, {-1,-1}
};
const int N=10e3;
int level[N][N];
map<pair<int,int>,bool> visited;

void bfs(int r, int c, int R, int C)
{
	int cnt=1;
	queue<pair<int,int>> q;
	q.push({r,c});
	level[r][c]=0;
	visited[{r,c}]=false;

	while(!q.empty())
	{
		int x=q.front().first;
		int y=q.front().second;
		q.pop();

		for(auto i : pat)
		{
			int px=x+i.first;
			int py=y+i.second;
			if(px<0 || py<0 || px>=R || py>=C) continue;
			if(!visited[{px,py}])
			{
				++cnt;
				visited[{px,py}]=true;
				level[px][py]=level[x][y]+1;
				q.push({px,py});
			}

		}
	}
}
  
void solve()
{
	int r,c,R,C; cin >> r >> c >> R >> C;
	bfs(R,C,r,c);
	level[R][C]=0;
	for(int i=0;i<r;++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cout << level[i][j] << " ";
		}
		cout << ln;
	}
}
int main()
{
    fastio
    solve();
    return 0;
}