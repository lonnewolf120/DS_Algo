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

/*DFS on tree
const int N = 1e3+10;
vector<int> tree[N];
void dfs1(int vertex, int parent)
{
   for(auto child:tree[vertex]) //go to each child subtree and run dfs again
   {
      if(child!=parent) dfs1(child,vertex);
   }
}
*/

   
  
void solve()
{
	ll n; cin >> n;
	vector<ll> v(n+2), fi(n+2), li(n+2);
	for(ll i=1; i<=n; ++i) cin >> v[i];
	stack<ll> l,r;
	
	l.push(0);
	r.push(n+1);
	for(ll i=1; i<=n; ++i)
	{
		//pop indexes whose values are bigger/equal to the element
		while(v[l.top()]>=v[i]) l.pop();
		//set the index of the left-most smallest value for a certain index
		fi[i]=l.top();
		//insert the indexes
		l.push(i);
	}
	for(ll i=n; i>=1; --i)
	{
		//pop indexes whose values are bigger/equal to the element
		while(v[r.top()]>=v[i]) r.pop();
		//set the index of the left-most smallest value for a certain index
		li[i]=r.top();
		//insert the indexes
		r.push(i);
	}

	ll ans=0;
	for (ll i = 1; i <= n; ++i)
	{
		//count of max subsegments with the same index (i-fi)*(li-i), where li & fi are the left & right most 
		ans += (ll) v[i]*((i-fi[i])*(li[i]-i));
	}
	cout << ans << ln;
}
int main()
{
    fastio
    solve();
    return 0;
}