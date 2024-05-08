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
	ll n,x,c=1,cnt=0; cin >> n;
	stack<ll> st, st2;
	//forsn(i,1,n) {cin >> x; st.push(x);}
	forn(i,2*n)
	{
		string s; cin >> s;
		if(s=="add")
		{
			cin >> x; st2.push(x);
 		}
		else
		{
			if(!st2.empty())
			{
				if(st2.top()!=c) //if top of stack isn't equal to c, then the order is not right & we need to re-order
				{
					cnt++; //since we're re-ordering whole stack now
					st2=stack<ll>();
					/*we can just empty the stack instead of deletion, sorting & re-insertion
					cause it's said they'll be inserted in sorted order, so we'll focus on the newly inserted elements*/ 
				}
				else st2.pop(); //the order is correct here, so we move forward
			}
			++c; //increment c after done with each op 
		}
		
	}
	cout << cnt << ln;
}
int main()
{
    fastio
    solve();
    return 0;
}