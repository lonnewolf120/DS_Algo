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
    ll n,mx=-1111,mn=INT_MAX; cin >> n;
    vector<ll> v;
    ll x; cin >> x; v.push_back(x);cin>>x;v.push_back(x);
    mx=max(v[0],v[1]),mn=min(v[0],v[1]); cout<<11;
    forsn(i,2,n)
    {
        cin >> x;
        mx=max(mx,x);
        mn=min(mn,x);
        if(x>= v[i-1] && x>=mx) {cout<<1;v.push_back(x);}
        else if(x<= v[i-1] && x>mn) {cout <<1;v.push_back(x);}
        else cout << 0; 
    }cout<<ln;
   //for(auto i:v)cout<<i;
   
    cout<<ln;
}
int main()
{
    fastio
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
     //cout << "Case #" << it+1 << ": ";
        solve();
    }
    return 0;
}