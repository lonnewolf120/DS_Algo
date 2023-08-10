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
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define pb push_back
#define fi first
#define se second
#define INF 1e9
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

int getX(string s)
{
	return s[0]-'a';
}
int getY(string s)
{
	return s[1]-'1';
}
const int N = 1e3+10;
int visited[8][8];
int level[8][8];

vector<pair<int,int>> movements=
{
	{1,2},{-1,2},{1,-2},{-1,-2},
	{2,1},{2,-1},{-2,1},{-2,-1},
};
 
bool isValid(int x, int y)
{
	return (x>=0 && y>=0 && x<8 && y<8);
}
int bfs(string source, string dest)
{
	int source_x = getX(source);
	int source_y = getY(source);
	int dest_x = getX(dest);
	int dest_y = getY(dest);

	queue<pair<int,int>> q;
	q.push({source_x, source_y});
	visited[source_x][source_y]=1;
	//level[source_x][source_y]=0;

	while(!q.empty())
	{
		pair<int,int> cur_v = q.front();
		int x=cur_v.first, y =cur_v.second;
		q.pop();

		for(auto move:movements)
		{
			int childX = x+move.first; 
			int childY = y+move.second;

			if(!isValid(childX,childY)) continue;
			if(!visited[childX][childY]) 
			{
				q.push({childX,childY});
				level[childX][childY]=level[x][y]+1;			 
				visited[childX][childY]=1;			 
			}
		}
		
	}

	return level[dest_x][dest_y];
}

int main()
{
    fastio
    
    int t; cin >> t;
    while(t--)
    {
    	string s1,s2; 
    	cin >> s1 >> s2;
    	cout << bfs(s1,s2) << ln;
    }
    return 0;
}