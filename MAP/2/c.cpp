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
	map<pair<int,int>,int> mp;
	int n; cin >> n;
	string c;
	cin >> c;
	int x=0,y=0;
	mp.insert({{x,y},1});
	int ans=1e9,l,r;

	for (int i = 1; i <= n; ++i)
	{
		char s=c[i-1];
		if(s=='L') x-=1;
		else if(s=='R') x+=1;
		else if(s=='U') y+=1;
		else if(s=='D') y-=1;
		
		//else cout << -1 << ln;
		//else cout << -1 << ln;
		if(mp[{x,y}])
		{
			if(i-mp[{x,y}] < ans)
			{
				l = mp[{x,y}];
				r = i;
				ans = r-l;
			}
		}
		mp[{x,y}]=i+1; 
	}
	if(ans==1e9) cout << -1 << ln;
	else cout << l << " " << r << ln; 
}
int main()
{
    fastio
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
     //cout << "Case " << it << ": ";
        solve();
    }
    return 0;
}