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
#define dbg(x) cout<<#x<<" = "<<x<<ln;
#define carr(v) for(auto i:v) cout << i << " ";
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
	ll n,a,b,k,j=0,sum=0; cin >> n >> a >> b >> k;
	vector<int> v(n),l(n);
	forn(i,n) 
	{
		ll x,h; cin >> x;
		(x%(a+b))? h = x%(a+b) : h = a+b;
		v[i] = ceil(h/a)-1;
	}
	sort(all(v));
	for(auto i:v)
	{
		//if(i==k) {l.push_back(i);++j;break;}
		if(i>k || sum+i>k) break;
		sum+=i;
		l.push_back(sum);
		++j;
	}
	carr(v);
	cout << j << ln;

}
int main()
{
    fastio
    solve();
    return 0;
}