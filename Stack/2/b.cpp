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
	deque<ll> dq1,dq2;
	ll n,c=0,w=-1; cin >> n;
	
		ll x,y,a;
		cin >> x;
		while(x--)
		{
			cin >> a; dq1.push_back(a);
		}
		cin >> y;
		while(y--)
		{
			cin >> a; dq2.push_back(a);
		}
		while(c<1e5+10)
		{
			ll c1,c2;
			if(dq1.empty()) {w=2;cout << c << " " << 2 <<ln;break;}
			else if(dq2.empty()){w=1;cout << c << " " << 1 << ln;break;}
			c1=dq1[0], c2=dq2[0];
			dq1.pop_front();
			dq2.pop_front();
			if(c1>c2)
			{
				dq1.push_back(c2);
				dq1.push_back(c1);
			}
			else if(c1<c2)
			{
				dq2.push_back(c1);
				dq2.push_back(c2);
			}
			++c;
		}
		if(w==-1){cout<<-1<<ln;}

	
}
int main()
{
    fastio
    solve();
    return 0;
}