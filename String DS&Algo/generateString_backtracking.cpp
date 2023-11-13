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

vector<string> v;
 //Here we're keeping counts of the open/close parantheses LEFT (not already present)
void generate(int open, int close, string &s)
{
	if(open == 0 && close ==0){v.pb(s);return;}
	if(open>0)
	{
		s.pb('(');
		generate(open-1,close,s);
		s.pop_back();	//popback the ( to continue the recurrence to generate another sequence
	}
	if(close>0)
	{
		if(close>open) //check if more close are left than open
		{
			s.pb(')');
			generate(open,close-1,s);
			s.pop_back();
		}
	}
}
void solve()
{
	int n; cin >> n;
	string s;
	generate(n,n,s);
	//cout << v.size() << ln;
	for(auto i:v) cout << i << " ";
}
int main()
{
    fastio
    //ll t;
    //cin >> t;
    //for(int it=1;it<=t;it++) {
     //cout << "Case " << it << ": ";
        solve();
    //}
    return 0;
}