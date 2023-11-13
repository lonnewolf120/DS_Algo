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

int visited[8][8];
int level[8][8];

vector<pair<int,int>> vp =
{
	{1,-2}, {1,2}, {2,-1}, {2,1},
	{-2,-1}, {-1,-2}, {-2,1}, {-1,2}
};

int bfs_string(string src, string dest)
{
		int sx = src[0]-'a', destX = dest[0]-'a';
		int sy = src[1]-'1', destY = dest[1]-'1';
		visited[sx][sy]=1;

		queue<pair<int,int>> q;
		q.push({sx,sy});
		level[sx][sy]=0;
		while(!q.empty())
		{
			visited[sx][sy]=1;
			pair<int,int> p = q.front();
			q.pop();
			int x = p.first, y = p.second;
			for(auto i:vp)
			{
				int mx= x+i.first, my= y+i.second;
				if(mx<0 || my<0 || mx>=8 || my>=8) continue;
				if(!visited[mx][my])
				{
					q.push({mx,my});
					visited[mx][my]=1;
					level[mx][my]=level[x][y]+1;
				}
			}
			if(level[destX][destY]!=0) break;
		}
		return level[destX][destY];

}

void reset()
{
	forn(i,8)
	{
		forn(j,8)
		{
			level[i][j]=0;
			visited[i][j]=0;
		}
	}
}
int main()
{
    fastio
    ll t;
    cin >> t; cin.ignore();
    for(int it=1;it<=t;it++) 
    {
        string src, dest; 
        cin >> src >> dest;
        reset();
		  cout << bfs_string(src,dest) << ln;		
	 }

      
    return 0;
} 