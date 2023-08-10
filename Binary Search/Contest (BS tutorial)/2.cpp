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
   
int lower(int pre[], int h, int target)
{
   int l = 0,ans=-1;h--;
   while(l<=h)
   {
      int mid = l+(h-l)/2;
      if(pre[mid] >= target) {ans=mid;h=mid-1;}
      else l = mid+1;
   }
   return ans;
}
int upper(int pre[], int h, int target)
{
   int l = 0,ans=1;h--;
   while(l<=h)
   {
      int mid = l+(h-l)/2;
      if(pre[mid] <= target) l=mid+1;
      else {ans = mid; h = mid-1;}
   }
   return ans;
}
int main()
{
    fastio
    ll n,q,x; cin >> n;
    int v[n];
    for (int i = 0; i < n; ++i)
    {
       cin >> v[i];
    }
    cin >> q;
    while(q--)
    {
      cin >> x;
      auto m = lower(v,n,x); 
      (v[m]==x)?cout << "Yes ": cout << "No "; 
      cout << m+1 << ln;
      //cout << lower_bound(all(v),x)-v.begin() << "\n";
    }
    return 0;
} 