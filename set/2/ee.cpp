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

/*DFS on tree
const int N = 1e3+10;
vector<int> tree[N];
void dfs1(int vertex, int parent)
{
   for(auto child:tree[vertex]) //go to each child subtree and run dfs again
   {
      if(child!=parent) dfs1(child,vertex);
   }
}
*/

   
  
void solve()
{
   ll n,c=0; cin >> n;
   set<ll> s;
   if(n%10==0)
   {
      //++n; s.insert(n);
      do {s.insert(n++);}
      while(n%10==0);
      //n+=c;
   }
   while(n)
   {
   if(n%10)
   {
      while(n%10) s.insert(n++);
      //n+=c;
   }
   else
   {
      while(n%10==0) n/=10;
      if(s.find(n)!=s.end()) {cout << s.size() << ln;return;}
      else
      {
         s.insert(n++);
      }
   }
   }

   
}
int main()
{
    fastio
    solve();
    return 0;
}