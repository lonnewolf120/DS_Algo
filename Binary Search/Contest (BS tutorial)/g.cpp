#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
   
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

int findZero(ll n)
{
   ll c=0,i=5;
   while(n/i>0)
   {
      c+=n/i;
      i*=5;
   }
   return c;
}
int findNumber(ll n)
{
   ll l=0,h=5*n,mid,z;
   while(l<=h)
   {
      mid = l + (h-l)/2;
      //if(mid == n) {cout << mid << ln;break;}
      if(findZero(mid) < n) l = mid+1;
      else h = mid-1;
   }
   if(findZero(l)==n) return l;
   else return -1; 
}
void solve()
{
   ll n; cin >> n;
   ll m = findNumber(n);
   //cout << l << ln;
   (m==-1)?cout << "impossible\n": cout << m << "\n";
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