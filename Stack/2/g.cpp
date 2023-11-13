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

/*Soln step: 
1)Find largest rectangle including each bar 1 by 1; 2)Take Max of the Area for each bar;

Find Max Area for A bar (Optimal Approach)
find nearest leftmost bar with height <= current bar & store in vector
find nearest rightmost bar with height <= current bar & store in vector

How to keep track of previous smaller bars
Use stack
for remembering prev smaller elements, maintain elements in increasing order with the largest being at the top of the stack
and store index+1 in vector if they're smaller

range of the element (range of a value to be minimum for a max range)
so, range = high-low+1 and so it's area = num * range
*/
void solve()
{
	ll n; cin >> n;
	vector<ll> v(n+2),lf(n+2),rf(n+2);
	stack<ll> l,r;

	l.push(0);
	forsn(i,1,n) cin >> v[i];
	forsn(i,1,n)
	{
		while(v[l.top()]>=v[i]) l.pop();
		lf[i]=l.top()+1;
		l.push(i);
	}
	r.push(n+1);
	for(ll i=n; i>=1;--i)
	{
		while(v[r.top()]>=v[i]) r.pop();
		rf[i]=r.top()-1;
		r.push(i);
	}
	ll ans=-1;
	forsn(i,1,n)
	{
		ans= max(ans,v[i]*(rf[i]-lf[i]+1));
	}
	cout << ans << ln;
}
int main()
{
    fastio
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
     	cout << "Case " << it << ": ";
        solve();
    }
    return 0;
} 