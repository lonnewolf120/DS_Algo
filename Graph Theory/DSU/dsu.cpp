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

   
  
void solve()
{

}
unordered_map<int,int> parent;
unordered_map<int,int> size;
void make(int v)
{
	//creating each node means assigning them as their root node
	parent[v]=v;
	size[v]=1;
}

int findParent(int u)
{
	if(parent[u]==u) return u;
	return parent[u]=findParent(parent[u]);
	/* usually,
	return findParent(parent[u]);
	using path compression to store paths along way
	*/
}
void Union(int u, int v)
{
	int a = findParent(u);
	int b = findParent(v);

	if(a!=b)
	{
		//we want to add the smallest tree to the other
		if(size[a]<size[b]) swap(a,b); 
		//Now, whatever tree we need to add would be the smallest tree
		parent[b]=a;
		size[a]+=size[b];
	}	
}

int main()
{
    fastio
    ll n,k;
    cin >> n >> k;
    forsn(i,1,n+1) make(i);

    while(k--)
    {
    	ll u,v; cin >> u >> v;
    	Union(u,v);
    }

    //find connected components
    ll cnt=0;
    forsn(i,1,n+1)
    {
    	if(findParen(i)==i)++cnt;
    }
    cout << cnt << ln;
    return 0;
}