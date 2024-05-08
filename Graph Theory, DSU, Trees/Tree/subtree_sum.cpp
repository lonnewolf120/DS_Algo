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
vector<int> tree[N];
bool visited[N];
int sum=0;

int dfs1(int vertex)
{
	sum+=vertex; 		//count sum
	visited[vertex]=true;
	for(auto child:tree[vertex]) //go to each child subtree and run dfs again
	{
		if(!visited[child]) dfs1(child);
	}
	return sum; //when all childs are visited we'll return the sum
}

/*without using visited vector*/
int dfs2(int vertex, int parent=0)
{
	sum+=vertex;
//as this is a tree so we dont need to keep track of visited we can 
//just traverse if nodes arent parent
	for(auto child:tree[vertex])				//go to each child subtree and run dfs again
	{
		if(child!=parent) dfs2(child, vertex);
	}
	return sum; //when all childs are visited we'll return the sum
}

/*without taking global variable:*/
void dfs3(int vertex, int* s, int parent=0)
{
	*s = *s + vertex;
	for(auto child:tree[vertex])				//go to each child subtree and run dfs again
	{
		if(child!=parent) dfs3(child,s,vertex);
	}
}

int main()
{
    fastio
    ll t; cin >>t;
    sum=0;
    forn(i,t)
    {
    	int x,y;cin >> x >> y;
    	tree[x].pb(y);
    }
    int q; cin >> q;
    dfs1(q); cout << "Subtree sum: " << sum <<ln; 
		sum = 0;
    dfs2(q); cout << "Subtree sum: " << sum <<ln;
		sum = 0;
    dfs3(q,&sum); cout << "Subtree sum: " << sum <<ln;
    return 0;
}