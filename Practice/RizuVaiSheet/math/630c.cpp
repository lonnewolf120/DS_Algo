#include <bits/stdc++.h>
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

ll nP2(ll n)
{
   return n*(n-1);
}
ll squareSum(ll n)
{
   return ((n*(n+1)*(2*n+1))/6);
}

void solve()
{
   //lucky numbers 7,8 for n numbers
   //2^n for each n gives the amount of ways we can get unique sequences of lucky numbers
   //and for lucky numbers upto n, we'll need summation of 2^k where k=0 to n
   //so, Sn = a((1-r^n)/(1-r)), a=2,r=2 ==> Sn = 2^n+1 -2 = (2LL << n) - 2;
   ll n =100000;
   cout<< n%2<<ln;
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