#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
using namespace std;
   
typedef long long ll;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define INF 2e18
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
   
  
void solve(){
    ll n,mn=INT_MAX,mx=INT_MIN,p0,p1; cin>>n;
    vector<ll> v(n);
    forn(i,n){
        cin>>v[i];
        //we need to bring the max to 0, so the first ind we got is the one we need to swap (for min op)
        if(v[i]>mx){mx=v[i];p0=i;}
        //we need to bring the min to n-1, so the last ind we got is the one we need to swap (for min op)
        if(v[i]<=mn){mn=v[i];p1=i;} 
    }
    ll cnt=p0+((n-1)-p1);  //simulating the swap for min & max, this is the total swaps needed
    if(p0>p1)--cnt; //if max-index is bigger than while swapping, it'll also swap min-index once, hence subtract
    cout<<cnt<<ln;
}
int main()
{
    fastio
    //ll t;
    //cin >> t;
    //for(int it=1;it<=t;it++) {
     //cout << "Case #" << it+1 << ": ";
        solve();
    //}
    return 0;
}