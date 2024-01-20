#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
// #include <C:\D Drive\Projects\debug2.h>
using namespace std;
   
typedef long long ll;
typedef long double ld;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i <= e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define yes cout << "YES\n"
#define no cout << "NO\n"

ll nearest_loc(ll s, vector<ll> &a)
{
	// s--;
	//throw 2 pointers from s and find the nearest loc to s in array a, containing 1
	ll x=s,y=s,n=a.size();
	if(a[x])return x; 
	while(a[x]!=1 && x>0) x--;
	if(a[0] && x==s) x=0; 
	while(a[y]!=1 && y<n) ++y;
	if(a[n-1] && y==s) y=n-1;
	if(abs(s-x)<abs(s-y)) {return x;}
	else {return y;}
	// return min(x,y);
}

void solve()
{
	ll n,s; cin>>n>>s; s--;
	vector<ll> a(n),b(n);
	for (int i = 0; i < n; ++i) cin>>a[i];
	for (int i = 0; i < n; ++i) cin>>b[i];
	if(!a[0]){no;return;}
	else if(a[0] && a[s]) {yes;return;}
	else if(b[s])
	{
		ll c=nearest_loc(s,a);
		if(b[c]) {yes;return;}
	}
	no; return;
}
int main()
{
    fastio
    ll t=1;
    // cin >> t;
    for(int it=1;it<=t;it++) {
     //cout << "Case " << it << ": ";
        solve();
    }
    return 0;
}