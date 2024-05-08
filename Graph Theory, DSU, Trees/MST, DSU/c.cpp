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
#define pqint priority_queue
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
	ll n; cin >> n;
	vector<ll> v(n),dp(n+1,0);
	vector<pqint<pair<ll,ll>>> vq(n);
	for(auto &i:v){cin>>i;--i;}
	forn(i,n)
	{
		dp[i+1]=dp[i];
		if(!vq[v[i]].empty())
		{
			ll x = vq[v[i]].top().second;
			dp[i+1]=max(dp[i+1], dp[x]+ (i-x+1));
		}
		vq[v[i]].push({dp[i]-i,i});
	}
	cout << dp[n] << ln;
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