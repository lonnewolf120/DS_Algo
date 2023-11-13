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

   
multimap<string,int> mp;
void solve()
{
	int n; 
	cin >> n; 
	
	if(n==0)
	{
		string s; int x;
		cin >> s; 
		cin >> x;
		mp.insert({s,x});
		
	}
	else if(n==1)
	{
		string s;
		cin >> s;
		auto ilw = mp.lower_bound(s);
		auto ihw = mp.upper_bound(s);

		for(auto k=ilw; k!=ihw; ++k)
			cout <<k->second << ln;
	}
	else if(n==2)
	{
		string s;
		cin >> s;
		mp.erase(s);
	}
	else if(n==3)
	{
		string a,b; cin >> a >> b;
		auto ilw = mp.lower_bound(a);
		auto ihw = mp.upper_bound(b);

		for(auto k=ilw; k!=ihw; ++k)
			cout << k->first << " " <<k->second << ln;
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