
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
	ll n,x;
	while(cin >> n)
	{
		if(n==0) return;
		ll sum = 0;
		priority_queue<ll,vector<int>,greater<int>> pq;

		forn(i,n)
		{
			cin >> x; pq.push(x); 
		}
		//sum=pq.top(); pq.pop();
		while(pq.size()>1)
		{
			ll m1= pq.top(); pq.pop(); 
			ll m2=pq.top(); pq.pop();
			sum+=(m1+m2);
			//cout << sum << " ";
			pq.push(m1+m2);
		}
		cout << sum << ln;
	}
}
int main()
{
    fastio
    solve();
    return 0;
}