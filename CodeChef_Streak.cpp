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
    ll n; cin >> n;
    vector<ll> v1(n),v2(n);
    for(auto &i:v1)cin>>i;
    for(auto &i:v2)cin>>i;
    ll str1=0,str2=0,mxS1=0,mxS2=0;
    forn(i,n)
    {
        if(v1[i]!=0)
        {
            str1++;
        }else 
        {
            mxS1=str1;str1=0;
        }
        if(v2[i]!=0)
        {
            str2++;
        }else 
        {
            mxS2=str2;str2=0;
        }
    }
    if(mxS1>mxS2){cout<<"Om\n";} 
    else if(mxS1<mxS2){cout<<"Addy\n";}
    else cout<<"Draw\n";
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