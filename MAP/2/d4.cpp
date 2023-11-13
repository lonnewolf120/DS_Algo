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
#define ln "\n"
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

  
void solve()
{
	ll n,k; cin >> n >> k;
	map<ll,ll> mp;
	set<ll> st;
	vector<ll> v(n);
	//we'll use some sort of a sliding window
	forn(i,n)
	{
		cin >> v[i];

		//if elem count is 1 then we'll insert into set else remove it
		if(++mp[v[i]]==1) st.insert(v[i]);		//sliding window: this slides fwd
		else st.erase(v[i]);

		//now unless we reach the point we consider it a subsegment we wont run further op
		if(i<k-1) continue;

		//check the count of the last inserted item in subsegment and re-run prev op
		if(--mp[v[i-k]]==1) st.insert(v[i-k]);		//sliding window: this slides bwd
		else st.erase(v[i-k]);

		if(!st.empty()) cout << *(st.rbegin()) << ln;
		else cout << "Nothing\n";

	}
}
int main()
{
    fastio
    solve();
    return 0;
}