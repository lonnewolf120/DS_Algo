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
   
  
vector<int>::iterator lower(vector<int>& pre, const int& target)
{
    auto l = pre.begin(), h = pre.end();
    while (l < h)
    {
        auto mid = l + (h - l) / 2;
        if (*mid < target) l = mid + 1;
        else h = mid;
    }
    return l;
}

vector<int>::iterator upper(vector<int>& pre, const int& target)
{
    auto l = pre.begin(), h = pre.end();
    while (l < h)
    {
        auto mid = l + (h - l) / 2;
        if (*mid > target) h=mid;
        else l=mid+1;
    }
    return l;
}

void solve()
{
	int n,q,x,y; vector<int> v1,v2;
   cin >> n >> q;
	forn(i,n){cin>>x>>y;v1.pb(x);v2.pb(y);}
	sort(all(v1));
	sort(all(v2));
   forn(i,q)
	{
      cin >> x;
      cout << (upper(v1,x)-v1.begin())-(lower(v2,x)-v2.begin()) << ln;
   }

}
int main()
{
    fastio
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
     cout << "Case " << it << ":\n";
        solve();
    }
    return 0;
}