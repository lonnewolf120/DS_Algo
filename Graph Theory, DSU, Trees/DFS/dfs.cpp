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
#define INF 2e18
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

const int N = 1e3+10;  
vector<int> g[N];
bool visited[N]; //can use a map instead too

void dfs(int vertex)
{
	/*take action on the vertice before moving on to next vertexes*/
	cout << vertex << ln;
	visited[vertex] = true;
	for(int neighbor:g[vertex])
	{
		cout << "parent " << vertex << ", child " << neighbor << ln;
		/*take action on neighbor before dfs/starting dfs on it recurcively*/
		if(visited[neighbor]) continue;
		dfs(neighbor);
		/*take action on neighbor after dfs/exiting neighbors*/
	}
	/*take action on vertice after exiting the vertice*/
}

int main()
{
    fastio
    ll n,x,y; cin >> n;
    forn(i,n)
    {
    	cin >> x >> y;
    	g[x].pb(y);
    	//g[y].pb(x);  //if undirected
    }
 	int root = 1;
    dfs(root);
    return 0;
}