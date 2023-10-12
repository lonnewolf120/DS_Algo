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
	ll x;
	multiset<ll> ms;
	multiset<ll> ls;
	while(cin >> x)
	{
		if(x==0) return;
		if(x==-1)
		{
			auto p = ls.rbegin();
			auto pp = ms.begin();
			cout << *p << ln;
			ls.erase(ls.find(*p));
			if(ls.size() < ms.size())
			{
				ls.insert(*pp);
				ms.erase(ms.find(*pp));
			}
		}
		else
		{
			if(ls.empty() || x <= *ls.rbegin()) ls.insert(x);
			else ms.insert(x);
			if(ls.size()>ms.size()+1)
			{
				ms.insert(*ls.rbegin());
				ls.erase(ls.find(*ls.rbegin()));
			}
			else if(ms.size()>ls.size())
			{
				ls.insert(*ms.begin());
				ms.erase(ms.find(*ms.begin()));
			}
		}
	}
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