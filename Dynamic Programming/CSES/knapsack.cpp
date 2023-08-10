#include <bits/stdc++.h>
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
#define inf 1e18
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define yes cout << "YES\n"
#define no cout << "NO\n"
const int N=10e5;
vector<ll> wi(N),vi(N);

ll count(ll ind, ll w,vector<vector<ll>> &dp)
{
	//base case 
	if(ind==0)
	{
		return (wi[0]<=w)? vi[0]:0;
	}
	if(dp[ind][w]!=-1)return dp[ind][w];	
	ll not_take=0+count(ind-1,w,dp);
	ll take=INT_MIN;
	if(wi[ind]<=w)
	{
		take=vi[ind]+count(ind-1,w-wi[ind],dp);
	}
	return dp[ind][w]=max(take,not_take);
}

void solve()
{
	// dp[0]=0;

	ll n,W; cin>> n>>W;
	vector<vector<ll>> dp(n,vector<ll>(W+1,-1));

	forn(i,n)
	{
		cin>>wi[i]>>vi[i];
	}
	cout << count(n-1,W,dp) << ln;
}
int main()
{
    fastio
    solve();
    return 0;
}