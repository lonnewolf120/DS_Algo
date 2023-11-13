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

   

void solve(vector<ll>& pwON)
{
	ll A,B,C,k,sum=0; cin>>A>>B>>C>>k;
	ll x,y,z; bool f=false;
	forsn(i, pwON[x], pwON[x+1]-1)
	{
		ll mx=pwON[C]-i, mn=pwON[C+1]-i-1;
		mx=max(mx,pwON[B]);
		mn=min(mn,pwON[B+1]-1);
		if(mn<mx)continue;
		
			ll len=mn-mx+1;
			if(sum<k && sum+len>=k)
			{
				f=true;
				x=i;
				y=mx+(k-sum)-1;
				z=x+y;
			}
			sum+=len;
		
	}
	(f)?printf("%lld + %lld = %lld\n",x,y,z) : printf("-1\n");
}
int main()
{
    fastio
    ll t;
    cin >> t;
    vector<ll> pwON(10);
	 forsn(i,2,7) pwON[i]=pwON[i-1]*10;
    for(int it=1;it<=t;it++) {
     //cout << "Case " << it << ": ";
        solve(pwON);
    }
    return 0;
}