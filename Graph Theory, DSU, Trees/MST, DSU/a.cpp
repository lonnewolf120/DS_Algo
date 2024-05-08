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
	ll n,m,sum1=0,sum2=0; cin >> n >> m;
	vector<ll> v(n);
	forn(i,n)
	{
		ll x; cin >> x; sum1+=x;
	}
	forn(i,m)
	{
		ll x; cin >> x; sum2+=x;
	}
	if(sum1>sum2) cout << "Tsondu\n";
	else if(sum1<sum2) cout << "Tenzing\n";
	else cout<<"Draw\n";


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