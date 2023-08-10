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
#define yes cout << "Yes\n"
#define no cout << "No\n"

   
  
bool solve()
{
	ll n,x,ans=0; cin >> n >> x;
	vector<ll> v1(n),v2(n),v3(n);
	for(auto &i:v1)cin>>i;
	for(auto &i:v2)cin>>i;
	for(auto &i:v3)cin>>i;
	stack<ll> s1, s2, s3;
	rforn(i,n-1)
	{
		s1.push(v1[i]);
		s2.push(v2[i]);
		s3.push(v3[i]);
	}
	forn(i,3*n)
	{
		ll tmp;
		if(!s1.empty())
		{
			tmp = s1.top();
			if(x>= (x|tmp))
			{
				s1.pop();
				ans |= tmp;
			}
		}
		if(!s2.empty())
		{
			tmp = s2.top();
			if(x>= (x|tmp))
			{
				s2.pop();
				ans |= tmp;
			}
		}
		if(!s3.empty())
		{
			tmp = s3.top();
			if(x>= (x|tmp))
			{
				s3.pop();
				ans |= tmp;
			}
		}
		
	}
	return (ans==x)? true:false;
}
int main()
{
    fastio
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
     //cout << "Case " << it << ": ";
        solve()?yes:no;
    }
    return 0;
}