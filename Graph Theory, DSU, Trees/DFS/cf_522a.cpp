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

   
map<string,ll> post, repost;  
void solve(ll t)
{
	string a,b,c; cin >> a >> b >> c;
    transform(c.begin(), c.end(), c.begin(), ::tolower);
    transform(a.begin(), a.end(), a.begin(), ::tolower);
    if(repost[c]==0)++repost[c];
	repost[a]+=repost[c]+1;
}
int main()
{
    fastio
    ll t,mx=-10;
    cin >> t;
    for(int it=1;it<=t;it++) {
     //cout << "Case " << it << ": ";
        solve(it);
    }
    for(auto i:repost)
    	mx=max(i.second,mx);
    cout << mx << ln;
    return 0;
}