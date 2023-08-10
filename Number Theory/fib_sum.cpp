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
#define ull unsigned long long

ll even_fib(ll n)
{
    if(n==0) return 0;
    if(n==2) return 2;
    ll a=4*even_fib(n-1)+even_fib(n-2);

    return a;
}

ull even_fib_sum(ull limit)
{
     ull f1,f2,f3,sum=0;
     f1=0,f2=2;
     sum=f1+f2;
     while(sum<limit)   //if sum is less than limit we iterate
     {
         f3=4*f2+f1;
         if(f3>limit) break; //if f3 is greater than limit than no need to add it to sum further

         f1=f2;
         f2=f3;
         sum+=f2;
     }
     return sum;
}

int main()
{
	ll n; cin >> n;
	//cout << even_fib(n) << ln;
    cout << (char)('A'^(1<<5)) << ln;
}