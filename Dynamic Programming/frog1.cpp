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
#define yes cout << "YES\n"
#define no cout << "NO\n"

const ll N=10e5;
vector<ll> dp(N,-1);
ll mn_cl(vector<ll>&v, ll n, ll mn=0)
{
    if(n==0) return mn;
    if(dp[n]!=-1) return dp[n];

    ll m1=INT_MAX,m2=INT_MAX;
    m1=abs(v[n]-v[n-1]);
    m2=abs(v[n]-v[n-2]);

    ll mini=min(m1,m2);
    ll cost=INT_MAX;

    if ((mini == m1 || n == 0) && n > 0) {
    	cost = min(cost,mn_cl(v, n-=1, mn+=mini));
	} else if ((mini == m2 || n == 1) && n > 1) {
	    cost = min(cost,mn_cl(v, n-=2, mn+=mini));
	}
    return dp[n]=cost;
}

ll mn_cal(vector<ll>&v, ll n, ll k)
{

    if(n==0) return 0;
    if(dp[n]!=-1) return dp[n];

   	ll cst=INT_MAX;

   	forn(i,k)
   	{
   		if(i-k<0)break;
	   	cst=min(cst,mn_cal(v,n-i,k)+abs(v[n]-v[n-i]));	
   	}

   	return dp[n]=cst;
}

ll cal(vector<ll>&v, ll n)
{
	forn(i,n-1)
	{
		if(i>n-1)
			dp[i]=min(abs(v[i]-v[i+1]), abs(v[i]-v[i+2]));
		else
			dp[i]=abs(v[i]-v[i+1]);
	}
	return dp[n-2];
}


void solve()
{
	ll n; cin >> n;
	vector<ll> v(n);
	for(auto &i:v) cin >> i;
	cout << mn_cl(v,n-1) << ln;
}
int main()
{
    fastio
    solve();
    return 0;
}