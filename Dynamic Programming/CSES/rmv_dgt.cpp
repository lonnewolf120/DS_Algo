#include <bits/stdc++.h>
// #include <C:\D Drive\Projects\Tutorials\Graph Theory\MCC\1\debug2.h>
using namespace std;
   
typedef long long ll;
typedef long double ld;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i <= e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define yes cout << "YES\n"
#define no cout << "NO\n"

vector<ll> getDgt(ll n)
{
	vector<ll> v;
	stringstream a;
	a << n;
	string ab = a.str();
	for(auto c:ab) v.pb(c-'0');
}
ll solve()
{
	ll n; cin >> n;
	vector<ll> dp(n+1,1<<30);
	ll c=0;
	dp[0]=0;
	forsn(i,0,n)
	{
		for(auto c:to_string(i))
		{
			dp[i]=min(dp[i],dp[i-(c-'0')]+1);
		}
	}
	// vector<ll> v=getDgt(n);
	// dbg(v);
	return dp[n];
}

int main()
{
    fastio
    ll t=1;
    // cin >> t;
    for(int it=1;it<=t;it++) {
     //cout << "Case " << it << ": ";
        cout<<solve()<<ln;
    }
    return 0;
}