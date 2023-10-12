
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

ll sod(ll n)
{
	ll c=0;
	for(ll i=n; i!=0; i/=10)
		c+= i%10;
	return c;
}

void solve()
{
	ll n,q; cin >> n >> q;
	vector<ll> v(n);
	set<ll> st; //set to store the indexes as they're unique & has to be in order
	forn(i,n)
	{
		cin >> v[i];
		if(v[i]>9) st.insert(i);
	}
	while(q--)
	{
		ll x; cin >> x;
		if(x==1)
		{
			ll l,r; 
			cin >> l >> r; --l;--r;
			if(st.empty()) continue;
			//find matching index of l and get its sod & store it, also remove prev one
			
			//if(i==st.end()) continue;
			//iterate (until range) & update
			
			vector<int> a;
          for (auto it = st.lower_bound(l); it != st.end(); it++)
          {
              if (*it > r)
              {
                  break;
              }
              v[*it] = sod(v[*it]);
              if (v[*it] < 10)
              {
                  a.push_back(*it);
              }
          }
          for (auto i : a)
          {
              st.erase(i);
          }
		}
		else
		{ 
			ll a; cin >> a; a--;
			cout << v[a] << ln;
		}
	}
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