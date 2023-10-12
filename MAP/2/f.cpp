
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
#define INF 2e18
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) (x).begin(), (x).end()

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

bool cmp(pair<ll,ll> &p1, pair<ll,ll> &p2)
{
	return p1.second<p2.second; //swap for y
}
void solve()
{
	ll n,m; cin >> n >> m;
	map<ll,vector<pair<ll,ll>>> mp;	//like for color 1 -> (1,1), (2,3), (3,4) for 2 ...
	forn(i,n)
	{
		forn(j,m)
		{
			ll x; cin >> x;
			mp[x].push_back({i,j});
		}
	}
	/*formula for sum of every subsequence of 
	Σ|x-a| (i.e. sum= |b-a|+|c-a|+|d-a| = b+c+d-3a)
	we can determine a+b+c+d, b+c+d, c+d, d by subtracting every element from sum while iterating
	 1  2  3  4  4  5
	 19 18 16 13 9  5
	then for every iteration:

    */
   ll ans=0;
	for(auto it:mp)
	{
	    vector<pair<ll,ll>> v = it.second;	//copy the index vectors of every color
		
		//for x:
		ll sum=0;
		sort(all(v));
		forn(j,v.size()) sum+=v[j].first;
		forn(j,v.size())
		{
			sum -= v[j].first;
			ans += sum-((v.size()-j-1)*v[j].first);
		}

		//for y:
		sum = 0;
		sort(all(v),cmp);
		forn(j,v.size()) sum+=v[j].second;
		forn(j,v.size())
		{
			sum -= v[j].second;
			ans += (sum)-((v.size()-j-1)*v[j].second);
		}
	}
	cout << ans << ln;
	
}
int main()
{
    fastio
    solve();
    return 0;
}